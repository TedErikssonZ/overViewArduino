// finally some time for my uno Arduino, starting with checking the components SW again.. using projects e.g. proj2 StarShip Interface

int SwitchState=0;

void setup() {
 pinMode(3, OUTPUT);
 pinMode(4, OUTPUT);
 pinMode(5, OUTPUT);
 pinMode(2, INPUT);
}

void loop() {
SwitchState = digitalRead(2);// read pin 2, med resistor för att ta ner spänningen
if(SwitchState == LOW){
    digitalWrite(3, HIGH); // green LED
    digitalWrite(4, LOW); // red LED
    digitalWrite(5, LOW); // red LED
  }
  else{ //button is pressed}
    digitalWrite(3, LOW); // turn off green LED
    digitalWrite(4, LOW); // red still off 
    digitalWrite(5, HIGH); // red on
    delay(500); //wait some time
    digitalWrite(4, HIGH); // red on // both RED on
    digitalWrite(5, HIGH); // red on
    delay(100);
  }
}// go back to the beginning of the loop
