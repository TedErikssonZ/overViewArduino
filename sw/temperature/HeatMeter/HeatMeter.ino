// test some TMP and analoginput

const int sensorPin = A0;
const float baselineTemp = 28.0;

void setup() {
  Serial.begin(9600); // open serialPort

  for(int pinNumber = 2; pinNumber<5; pinNumber++){
    pinMode(pinNumber, OUTPUT); // set as output 2-4
    digitalWrite(pinNumber, LOW); 
  }
}
void loop() {
  int sensorVal=analogRead(sensorPin); // 0 -1023 
  Serial.print("Sensor Value: ");
  Serial.print(sensorVal);

  float voltage = (sensorVal/1024.0)*5; // 0-5 V, rescale
  Serial.print(", Volts: ");
  Serial.print(voltage);

  Serial.println(", Degrees C: ");
  //convert the voltage to temperature in degrees
  float temperature = (voltage- 0.5)* 100;
  Serial.println(temperature);

if(temperature < baselineTemp +1){
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  }else if(temperature >= baselineTemp+1 && temperature < baselineTemp+2){
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  }else if(temperature >= baselineTemp+3 && temperature < baselineTemp+4){
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
  }else if(temperature >= baselineTemp+4 && temperature < baselineTemp+5){
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
  }
  delay(1);
} //loop
