#include <SoftwareSerial.h>

SoftwareSerial Slave(2, 11);
char BluetoothData;

void setup() {
  Serial.begin(9600);
  Slave.begin(9600); 
}


void loop() {
  if (Slave.available()) {
    BluetoothData = Slave.read();
    Serial.println(BluetoothData);
  //if (BluetoothData!='S')   Serial.println(BluetoothData);
    if (BluetoothData == 'F') Forward();
    if (BluetoothData == 'B') Back();
    if (BluetoothData == 'R') Right();
    if (BluetoothData == 'L') Left();
    if(BluetoothData == 'S') Stop();
  }
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
  analogWrite(9, 120);
}

void Left() {
  analogWrite(5, 120);
  analogWrite(6, 255);
}

void Stop(){
  analogWrite(3, 0);
  analogWrite(9, 0);
  analogWrite(5, 0);
  analogWrite(6, 0);
}
