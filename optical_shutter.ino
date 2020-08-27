// For simple optical shutter in Greytak Laboratory
// Servo motor movement direction driven by push buttons, LEDs indicate which button was pressed
// Arduino Nano board used in this build
// Mathew L. Kelley

#include<Servo.h>

int pos = 0;

Servo servo;

const int GREENBUTTON = 5;
const int GREENLED = 3;
int GREENBUTTONstate = 0;  

const int REDBUTTON = 6;
const int REDLED = 4;
int REDBUTTONstate = 0;    


void setup() {
  // Servo setup:
  pinMode(11, INPUT);  // digital pin 11
  pinMode(12, INPUT);  // digital pin 12

  pinMode(GREENBUTTON, INPUT);
  pinMode(GREENLED, OUTPUT);

  pinMode(REDBUTTON, INPUT);
  pinMode(REDLED, OUTPUT);
  
  servo.attach(2);  // digital pin 2
}


void loop() {
  GREENBUTTONstate = digitalRead(GREENBUTTON);
  if (GREENBUTTONstate == HIGH)
  {
    digitalWrite(GREENLED, HIGH);
  } 
  else{
    digitalWrite(GREENLED, LOW);
  }


  REDBUTTONstate = digitalRead(REDBUTTON);
  if (REDBUTTONstate == HIGH)
  {
    digitalWrite(REDLED, HIGH);
  } 
  else{
    digitalWrite(REDLED, LOW);
  }

  
  if (digitalRead(11) == HIGH && pos < 180) {
    pos = 15;
    servo.write(pos);
    delay(10);
  }

  
  if (digitalRead(12) == HIGH && pos > 0 ) {
    pos = 130;
    servo.write(pos);
    delay(10);  
  }
}
