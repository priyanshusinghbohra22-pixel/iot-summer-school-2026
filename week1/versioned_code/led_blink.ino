int potPin = A0;

void setup() {

  pinMode(13, OUTPUT);

}

void loop() {

  int value = analogRead(potPin);

  int speed = map(value,0,1023,100,1000);

  digitalWrite(13,HIGH);
  delay(speed);

  digitalWrite(13,LOW);
  delay(speed);

}
