void setup() {


}

void loop() {
  Forward(255);
  delay(1000);
 
  Forward(120);
  delay(1000);

  Back(255);
  delay(1000);
 
  Back(120);
  delay(1000);

  Right();

  delay(1000);

  Left();
}


void Forward(int speed){
  analogWrite(5, 0);
  analogWrite(6, 0);  
  analogWrite(3, speed);
  analogWrite(9, speed);  
}

void Back(int speed){
  analogWrite(3, 0);
  analogWrite(9, 0);  
  analogWrite(5, speed);
  analogWrite(6, speed);  
}

void Right(){
  analogWrite(3,255);
  analogWrite(9, 120);    
}

void Left(){
  analogWrite(5,120);
  analogWrite(6, 255);    
}



// setup
//  pinMode(3, OUTPUT);
//  pinMode(5, OUTPUT);
//  pinMode(6, OUTPUT);
//  pinMode(9, OUTPUT);

// loop
//digitalWrite(3, HIGH);
//digitalWrite(9, HIGH);
  
//  delay(1000);
//
//  digitalWrite(3, LOW);
//  digitalWrite(9, LOW);
//
//
//  digitalWrite(5, HIGH);
//  digitalWrite(6, HIGH);
//
//  delay(1000);
//
//  digitalWrite(5, LOW);
//  digitalWrite(6, LOW);
