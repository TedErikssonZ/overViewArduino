int sensorValue;
int sensorLow = 1023;
int sensorHigh = 0;

const int ledPin = 13;

void setup() {
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);
  Serial.begin(9600);      

  while (millis() < 5000 ){ // move hand up and down, change to conditions
    sensorValue = analogRead(A0);
    if(sensorValue > sensorHigh){
      sensorHigh = sensorValue;
    }
    if(sensorValue < sensorLow){
      sensorLow = sensorValue;
    }
  }
  digitalWrite(ledPin,LOW); // turn off the LED
  Serial.println("LowValue: ");
  Serial.println(sensorLow);
  Serial.println("HighValue: ");
  Serial.print(sensorHigh);
}

void loop() {
  sensorValue = analogRead(A0);
  int pitch = map(sensorValue,sensorLow,sensorHigh,50,4000);
  tone(8,pitch,20);
  delay(10); // reduce noise, did not work, only update freq
} 