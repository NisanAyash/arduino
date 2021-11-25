#include <SoftwareSerial.h>

// Bluetooth
SoftwareSerial Slave(2, 11);
char BluetoothData;


// HSCR04 sensor
const int pingPin = 10; // Trigger Pin of Ultrasonic Sensor
const int echoPin = 11; // Echo Pin of Ultrasonic Sensor
long duration, inches, cm;

void setup() {
  Serial.begin(9600);
  Slave.begin(9600);
}


void loop() {
  // Initialize distance sensor
  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(pingPin, LOW);
  pinMode(echoPin, INPUT);

  duration = pulseIn(echoPin, HIGH);
  inches = microsecondsToInches(duration);
  cm = microsecondsToCentimeters(duration);

  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();

  // Action by sensor
  if (cm < 30) Right();
  if (cm >= 30) Stop();

  // Actions by bluetooth
  if (Slave.available()) {
    BluetoothData = Slave.read();

    Serial.println(BluetoothData);
    //if (BluetoothData!='S')   Serial.println(BluetoothData);

    if (BluetoothData == 'F') Forward();
    if (BluetoothData == 'B') Back();
    if (BluetoothData == 'R') Right();
    if (BluetoothData == 'L') Left();
    if (BluetoothData == 'S') Stop();
  }

  // we should delay, because the initialization of the distance sensor.
  delay(100);
}

void Forward() {
  analogWrite(5, 0);
  analogWrite(6, 0);
  analogWrite(3, 255);
  analogWrite(9, 255);
}

void Back() {
  analogWrite(3, 0);
  analogWrite(9, 0);
  analogWrite(5, 255);
  analogWrite(6, 255);
}

void Right() {
  analogWrite(3, 255);
  analogWrite(9, 0);
}

void Left() {
  analogWrite(5, 0);
  analogWrite(6, 255);
}

void Stop() {
  analogWrite(3, 0);
  analogWrite(9, 0);
  analogWrite(5, 0);
  analogWrite(6, 0);
}


long microsecondsToInches(long microseconds) {
  return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds) {
  return microseconds / 29 / 2;
}
