
int buttons[6]; //array 6 integers
int notes[] = {262,294,330,349};

void setup() {
  Serial.begin(9600);
  buttons[0] = 2;
}

void loop() {
  int keyVal = analogRead(A0);
  Serial.println(keyVal); // print out the value in logger
  
  if(keyVal == 1023){
    tone(8, notes[0]);
    }
    else if(keyVal >= 690 && keyVal <= 700){
      tone(8,notes[1]);
    }
    else if(keyVal >= 505 && keyVal <= 515){
      tone(8, notes[2]);
    }
    else if(keyVal >= 5 && keyVal <=10){
      tone(8, notes[3]);
    }
    else{
      noTone(8);
    }
  }
