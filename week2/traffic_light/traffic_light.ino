/*
Author: Priyanshu Singh Bohra
Date: 05-07-2026
Description: Traffic Light Controller with Pedestrian Button
*/

const int RED = 23;
const int YELLOW = 22;
const int GREEN = 21;
const int BUTTON = 19;

bool pedestrian() {

  if (digitalRead(BUTTON) == LOW) {

    Serial.println("PEDESTRIAN CROSSING");

    digitalWrite(RED, HIGH);
    digitalWrite(YELLOW, LOW);
    digitalWrite(GREEN, LOW);

    delay(8000);

    return true;
  }

  return false;
}

void setup() {

  pinMode(RED, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(GREEN, OUTPUT);

  pinMode(BUTTON, INPUT_PULLUP);

  Serial.begin(115200);
}

void loop() {

  // RED
  Serial.println("RED");

  digitalWrite(RED, HIGH);
  digitalWrite(YELLOW, LOW);
  digitalWrite(GREEN, LOW);

  for(int i=0;i<50;i++){
    if(pedestrian()) return;
    delay(100);
  }


  // YELLOW
  Serial.println("YELLOW");

  digitalWrite(RED, LOW);
  digitalWrite(YELLOW, HIGH);
  digitalWrite(GREEN, LOW);

  for(int i=0;i<20;i++){
    if(pedestrian()) return;
    delay(100);
  }


  // GREEN
  Serial.println("GREEN");

  digitalWrite(RED, LOW);
  digitalWrite(YELLOW, LOW);
  digitalWrite(GREEN, HIGH);

  for(int i=0;i<40;i++){
    if(pedestrian()) return;
    delay(100);
  }

}
