//Servormotor test, lib

#include <Servo.h>
Servo myServo;

int const potPin = A0;
int potVal;
int angle;

void setup() {
 myServo.attach(9);
 Serial.begin(9600); // serial connection to see what happens? Only why I am doing it?
}

void loop() {
  potVal = analogRead(potPin);
  Serial.println("");
  Serial.print("PotVal: ");
  Serial.print(potVal);
  angle = map(potVal,0,1023,0,179);
  Serial.println("");
  Serial.print("Angle: ");
  Serial.print(angle);

  myServo.write(angle);
  delay(1000);
}
