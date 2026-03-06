#include <math.h>

// Sensor Pins
const int sensorPins[6] = {A0, A1, A2, A3, A4, A5};
const int N = 6;

// Calibration to convert raw reflectance readings into consistent limts.
const int whiteLevel = 50;
const int blackLevel = 750;

// TB6612FNG pins
const int STBY = 4;

// Left motor (A)
const int PWMA = 5;
const int AIN1 = 7;
const int AIN2 = 8;

// Right motor (B)
const int PWMB = 6;
const int BIN1 = 9;
const int BIN2 = 10;

// Position weights to given to each sensor reading to convert them into a single
// estimated position for the line.
const int pos[6] = {-6, -4, -2, 2, 4, 6};

// These are the values which can be tuned in testing to ensure reliable performance.
int   baseSpeed = 110;     // Baseline speed
float Kp = 13.5;           // Correction factor
float Kd = 0.09;           // Damps fast changes in error to prevent overshooting
int   maxTurn = 230;       // Prevents the robot from attempting unrealistic turns

// These values compensate for any external factors which may bias the robot in a
// certain direction.
int leftTrim  = 0;
int rightTrim = 0;

// These values set a PWM limit where below the motors may not behave reliably.
int minPWM_L = 55;
int minPWM_R = 55;

// Prevents the controller from reacting to sensor noise.
float dFilt = 0.0;
float dAlpha = 0.40;

// This section allows the robot to turn more aggresively when required.
float hardErrOn  = 5.0;
float hardErrOff = 3.2;

int hardBaseSpeed = 85;
int outsideBoost  = 55;
int insideBrake   = 110;

bool  enableInsideReverse = true;
float reverseErrThresh = 6.0;
int   reversePWM = 45;

unsigned long hardUntilMs = 0;
const unsigned long hardCooldownMs = 260;


// These values help remember where the line was lost in order to perform
// the correct turn to find the track.
unsigned long lostStartMs = 0;
float lastError = 0.0;
unsigned long lastUs = 0;

void setup() {
  pinMode(STBY, OUTPUT);

  pinMode(PWMA, OUTPUT);
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);

  pinMode(PWMB, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);

  digitalWrite(STBY, HIGH);
  lastUs = micros();
}

void loop() {
// Uses actual elapsed time for derivative calculations.
  unsigned long nowUs = micros();
  float dt = (nowUs - lastUs) * 1e-6f;
  if (dt <= 0) dt = 1e-3f;
  lastUs = nowUs;

  long weightedSum = 0;
  long sum = 0;

// This function applies the sensor weightings to the sensor readings and reduces 
// them to one line position.
  for (int i = 0; i < N; i++) {
    int v = analogRead(sensorPins[i]);
    int b = map(constrain(v, whiteLevel, blackLevel),
                whiteLevel, blackLevel,
                0, 1000);
    weightedSum += (long)b * (long)pos[i];
    sum += b;
  }

// This function deciphers when the line has been lost and figures out the
// best way to regain the line.
  if (sum < 300) {
    if (lostStartMs == 0) lostStartMs = millis();
    unsigned long t = millis() - lostStartMs;

    int initialDir = (lastError < 0) ? -1 : 1;
    int dir = initialDir;
    if (t > 350) dir = (((t - 350) / 250) % 2 == 0) ? initialDir : -initialDir;

    int fast = 170;
    int slow = 45;

    if (dir == 1) driveForward(constrain(fast + leftTrim, 0, 255),
                               constrain(slow + rightTrim, 0, 255));
    else          driveForward(constrain(slow + leftTrim, 0, 255),
                               constrain(fast + rightTrim, 0, 255));
    return;
  }
// This resets the lost line function so normal line tracking continues.
  lostStartMs = 0;

// This value determines where the line is in relation to the centre of the sensors.
  float error = (float)weightedSum / (float)sum;
// Thiese values help the robot to respond to quick direction changes in succession.
  float dRaw = (error - lastError) / dt;
  dFilt = (1.0f - dAlpha) * dFilt + dAlpha * dRaw;
  lastError = error;

// This prevents the robot from switching in and out of hard turn mode when
// it is around the threshold
  static bool inHard = false;

  if (!inHard && fabs(error) > hardErrOn) inHard = true;

  if (inHard && fabs(error) < hardErrOff) {
    inHard = false;

    dFilt = 0.0;
    lastError = error;

    hardUntilMs = millis() + hardCooldownMs;
  }

  bool hardAllowed = (millis() >= hardUntilMs);
  bool hardTurn = inHard && hardAllowed;

// This is the PD controller to convert the line position into steering commands.
  int correction = (int)(-(Kp * error + Kd * dFilt));
  correction = constrain(correction, -maxTurn, maxTurn);

// Reduces speed to allow for accurate turning.
  int dynamicBase = baseSpeed - (abs(correction) / 7);
  dynamicBase = constrain(dynamicBase, 75, baseSpeed);

// This applies the hard turn values from above.
  int leftCmd, rightCmd;

  if (hardTurn) {
    int base = hardBaseSpeed;

    leftCmd  = base - correction + leftTrim;
    rightCmd = base + correction + rightTrim;

    if (error < 0) {
// This applies a left hard turn command.
      rightCmd += outsideBoost;
      leftCmd  -= insideBrake;

      if (enableInsideReverse && fabs(error) > reverseErrThresh) {
        leftCmd = -reversePWM;  // tiny reverse inside wheel to pivot
      }
    } else {
// This applies a right hard turn command.
      leftCmd  += outsideBoost;
      rightCmd -= insideBrake;

      if (enableInsideReverse && fabs(error) > reverseErrThresh) {
        rightCmd = -reversePWM;
      }
    }
  } else {
// This applies normal left and right turn commands.
    leftCmd  = dynamicBase - correction + leftTrim;
    rightCmd = dynamicBase + correction + rightTrim;
  }

// Allows for compensation for small commands despite minimum PWM limits.
  leftCmd  = applyDeadbandSigned(leftCmd,  minPWM_L);
  rightCmd = applyDeadbandSigned(rightCmd, minPWM_R);

// Sets the minimum and maximum drive commands.
  leftCmd  = constrain(leftCmd, -255, 255);
  rightCmd = constrain(rightCmd, -255, 255);
// This function sends the drive commands to the motor driver.
  driveSigned(leftCmd, rightCmd);
}

// This applies the minimum PWM values used ensure motor behaviour is reliable.
int applyDeadbandSigned(int cmd, int minPwm) {
  if (cmd == 0) return 0;
  if (cmd > 0 && cmd < minPwm) return minPwm;
  if (cmd < 0 && cmd > -minPwm) return -minPwm;
  return cmd;
}

// This function converts the wheel commands into signals used by the motor driver.
void driveSigned(int leftCmd, int rightCmd) {
// Left motor control
  if (leftCmd >= 0) {
    digitalWrite(AIN1, HIGH);
    digitalWrite(AIN2, LOW);
    analogWrite(PWMA, leftCmd);
  } else {
    digitalWrite(AIN1, LOW);
    digitalWrite(AIN2, HIGH);
    analogWrite(PWMA, -leftCmd);
  }

// Right motor control
  if (rightCmd >= 0) {
    digitalWrite(BIN1, HIGH);
    digitalWrite(BIN2, LOW);
    analogWrite(PWMB, rightCmd);
  } else {
    digitalWrite(BIN1, LOW);
    digitalWrite(BIN2, HIGH);
    analogWrite(PWMB, -rightCmd);
  }
}

void driveForward(int leftSpeed, int rightSpeed) {
  digitalWrite(AIN1, HIGH);
  digitalWrite(AIN2, LOW);
  analogWrite(PWMA, leftSpeed);

  digitalWrite(BIN1, HIGH);
  digitalWrite(BIN2, LOW);
  analogWrite(PWMB, rightSpeed);
}

