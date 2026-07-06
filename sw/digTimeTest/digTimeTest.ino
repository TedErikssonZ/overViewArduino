// globals
const int SwitchPin = 8;
unsigned long previousTime = 0;
int SwitchState = 0;
int prevSwitchState = 0;
int led = 2;

long interval = 3000; // 6 sec

void setup() {
  for (int x=2; x<8; x++){
    pinMode(x,OUTPUT); // declare as outputs
  }
  pinMode(SwitchPin, INPUT);
}

void loop() {
  unsigned long currentTime = millis();
  if(currentTime - previousTime > interval){
     previousTime = currentTime;
     digitalWrite(led,HIGH);
     led++;
     if(led==7){
        digitalWrite(led,HIGH);
        while(SwitchState == prevSwitchState){
           delay(1000);
           for(int x=2;x<8;x++){
            digitalWrite(x, LOW);
           }
           delay(1000);
          for(int x=2;x<8;x++){
            digitalWrite(x, HIGH);
          }
          SwitchState = digitalRead(SwitchPin);// function blink
       }
      }
  }
  
SwitchState = digitalRead(SwitchPin);
  if(SwitchState != prevSwitchState){
    for(int x=2;x<8;x++){
        digitalWrite(x, LOW);
        }
      led =2;
      previousTime = currentTime;
      }

  prevSwitchState = SwitchState; // in the end of the loop
}
