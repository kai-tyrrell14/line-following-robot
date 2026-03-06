// This code allows for testing of any bias the robot may have to either side.

const int STBY = 4;


// Left motor control pins.
const int PWMA = 5;
const int AIN1 = 7;
const int AIN2 = 8;


// Right motor control pins.
const int PWMB = 6;
const int BIN1 = 9;
const int BIN2 = 10;


// Test speed used for both motors.
int testSpeed = 120;

void setup() {
  pinMode(STBY, OUTPUT);

  pinMode(PWMA, OUTPUT);
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);

  pinMode(PWMB, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);

  digitalWrite(STBY, HIGH);
}

void loop() {

// This drives both motors at the same PWM so the robot should go straight.
  driveForward(testSpeed, testSpeed);

  delay(4000);

// This stops the robot for a brief period.
  driveForward(0, 0);
  delay(3000);
}


// Function to drive each motor forward.
void driveForward(int leftSpeed, int rightSpeed) {

  // Left motor forward
  digitalWrite(AIN1, HIGH);
  digitalWrite(AIN2, LOW);
  analogWrite(PWMA, leftSpeed);

  // Right motor forward
  digitalWrite(BIN1, HIGH);
  digitalWrite(BIN2, LOW);
  analogWrite(PWMB, rightSpeed);
}