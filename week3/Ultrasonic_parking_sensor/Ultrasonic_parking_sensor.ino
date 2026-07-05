/*
Author: Priyanshu Singh Bohra
Module 3 - Question 22

Project: Ultrasonic Parking Sensor

Components Used:
- ESP32
- HC-SR04 Ultrasonic Sensor
- Red LED
- Yellow LED
- Green LED
- Passive Buzzer
- 3 × 220Ω Resistors

Pin Configuration:

HC-SR04
TRIG  -> GPIO25
ECHO  -> GPIO26

LEDs
Red LED    -> GPIO23
Yellow LED -> GPIO22
Green LED  -> GPIO21

Buzzer
Buzzer (+) -> GPIO16
Buzzer (-) -> GND


Working:

Distance > 50 cm
SAFE condition
Green LED ON
Buzzer OFF

Distance 20–50 cm
Yellow LED ON
Buzzer beeps every 500 ms

Distance 10–20 cm
Red LED ON
Buzzer beeps every 200 ms

Distance < 10 cm
All LEDs blink rapidly
Buzzer sounds continuously

Advanced Feature:
Implemented using millis()
(No delay() used)
Non-blocking timing for bonus marks.

Formula Used:

distance = (duration × 0.034) / 2

Serial Monitor Output Example:

Distance: 72.5 cm
SAFE

Distance: 35.2 cm

Distance: 15.4 cm

Distance: 8.1 cm

*/


const int trig = 25;
const int echo = 26;

const int red = 23;
const int yellow = 22;
const int green = 21;

const int buzzer = 16;

unsigned long previousMillis = 0;
unsigned long blinkMillis = 0;

bool flashState = false;

void setup() {

  Serial.begin(115200);

  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);

  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);

  pinMode(buzzer, OUTPUT);

}

void loop() {

  digitalWrite(trig, LOW);
  delayMicroseconds(2);

  digitalWrite(trig, HIGH);
  delayMicroseconds(10);

  digitalWrite(trig, LOW);

  long duration = pulseIn(echo, HIGH);

  float distance = (duration * 0.034) / 2;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  unsigned long currentMillis = millis();

  if (distance > 50) {

    Serial.println("SAFE");

    digitalWrite(green, HIGH);
    digitalWrite(yellow, LOW);
    digitalWrite(red, LOW);

    noTone(buzzer);

  }

  else if (distance >= 20 && distance <= 50) {

    digitalWrite(green, LOW);
    digitalWrite(yellow, HIGH);
    digitalWrite(red, LOW);

    if (currentMillis - previousMillis >= 500) {

      previousMillis = currentMillis;

      flashState = !flashState;

      if (flashState)
        tone(buzzer, 1000);
      else
        noTone(buzzer);

    }

  }

  else if (distance >= 10 && distance < 20) {

    digitalWrite(green, LOW);
    digitalWrite(yellow, LOW);
    digitalWrite(red, HIGH);

    if (currentMillis - previousMillis >= 200) {

      previousMillis = currentMillis;

      flashState = !flashState;

      if (flashState)
        tone(buzzer, 1000);
      else
        noTone(buzzer);

    }

  }

  else {

    if (currentMillis - blinkMillis >= 100) {

      blinkMillis = currentMillis;

      flashState = !flashState;

      digitalWrite(red, flashState);
      digitalWrite(yellow, flashState);
      digitalWrite(green, flashState);

    }

    tone(buzzer, 1000);

  }

}
