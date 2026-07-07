
// not using function to follow structure, men borde ha det

// globals
const int SwitchPin = 8;
unsigned long previousTime = 0;
int SwitchState = 0;
int prevSwitchState = 0;
int led = 0;

long interval = 3000; // 6 sec

void setup() {
  for (int x=2; x<8; x++){
    pinMode(x,OUTPUT); // declare as outputs
  }
  pinMode(SwitchPin, INPUT);
  Serial.begin(9600);    
  SwitchState = digitalRead(SwitchPin);
  if (SwitchState==0){
    led = 7;
    }
  else{
    led = 2;
    }
}

void loop() {
  unsigned long currentTime = millis();
  if(currentTime - previousTime > interval){
     previousTime = currentTime;
     digitalWrite(led,HIGH);
  
     if( (led==2 && SwitchState==0) || (led==7 && SwitchState==1) ){
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

     if (SwitchState==0){
        led--;
     }
     else {
       led++;
     }
  }
  
SwitchState = digitalRead(SwitchPin);
  if(SwitchState != prevSwitchState){
    for(int x=2;x<8;x++){
        digitalWrite(x, LOW);
        }
    if (SwitchState==0){
      led = 7;
      }
     else{
      led = 2;
      }
      previousTime = currentTime;
      }

  prevSwitchState = SwitchState; // in the end of the loop
  Serial.println("SwitchState: "); // 0 down, 1 up
  Serial.println(SwitchState);
}
