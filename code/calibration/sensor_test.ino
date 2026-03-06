// This code is used to determine the order of the sensors and that each sensor is working correctly

const int sensorPins[6] = {A0, A1, A2, A3, A4, A5};
const int N = 6;

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.print("Sensors: ");
// This prints the reading for each sensor in the sensor array.
  for (int i = 0; i < N; i++) {
    int v = analogRead(sensorPins[i]);

    Serial.print(v);

    if (i < N - 1) Serial.print(" , ");
  }

  Serial.println();
  delay(200);
}
