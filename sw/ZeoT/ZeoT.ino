// Blev exempel med extremt långa variabelnamn? kortade dem gick knappt att läsa

const int ctrPin1 = 2;
const int ctrPin2 = 3;
const int enablePin = 9;
const int dirPin = 4;
const int startPin = 5;
const int potPin = A0; // potensial

int start = 0;
int PreOnState = 0;
int dirState = 0;
int preDirState = 0;

int motorEnabled = 0;
int motorSpeed = 0;
int motorDirection = 1;

void setup() {
  pinMode(dirPin, INPUT);
  pinMode(startPin, INPUT);
  pinMode(ctrPin1, OUTPUT);
  pinMode(ctrPin2, OUTPUT);
  pinMode(enablePin, OUTPUT); 

  digitalWrite(enablePin, LOW);
}

void loop() {
  start = digitalRead(startPin);
  delay(2);
  dirState = digitalRead(dirPin);
  motorSpeed = analogRead(potPin)/4;

  if(startPin != PreOnState){
    if(start == HIGH){
      //motorEnabled = !motorEnabled; //flipp bool value
      if (motorEnabled) {
         motorEnabled = false;
        }
        else {
        motorEnabled = true;
        }
    }  
  }

  if(dirState != preDirState){
    if(dirState==HIGH){
      motorDirection = !motorDirection;
    }
  }

  if(motorDirection == 1){
    digitalWrite(ctrPin1, HIGH);
    digitalWrite(ctrPin2, LOW);
  }
  else{
    digitalWrite(ctrPin1, LOW);
    digitalWrite(ctrPin2, HIGH);
  }

  if(motorEnabled == 1){
    analogWrite(enablePin, motorSpeed);
  }
  else{
    analogWrite(enablePin, 0);
  }

  preDirState = dirState;
  PreOnState = start;
  
}
