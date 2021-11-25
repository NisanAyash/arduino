void setup() {
  pinMode(13, OUTPUT);
  pinMode(9, OUTPUT);


  // digitalWrite(10, LOW || HIGH) => write to digital pin
  // analogWrite(10, 0 || 255) => write to digital pin
}

void loop() {
for(int i=0;i<150;i=i+1){
  analogWrite(10, i);
  delay(20);
 };

 for(int i=150;i > 0 ;i=i-1){
  analogWrite(9, i);
  delay(20);
 };
}
