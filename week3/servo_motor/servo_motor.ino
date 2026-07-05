/*
Q25 - Servo Motor Sweep

Components Used:
1. ESP32
2. SG90 Servo Motor
3. Potentiometer
4. Push Button

Connections:
Servo Signal -> GPIO23
Potentiometer Middle Pin -> GPIO34
Button -> GPIO17

Functionality:
- Potentiometer controls servo angle from 0° to 180°.
- Current angle is displayed on Serial Monitor.
- Pressing the button makes the servo perform a full sweep:
  0° -> 180° -> 0°.
  
*/

#include <ESP32Servo.h>

Servo myServo;

const int servoPin = 23;
const int potPin = 34;
const int buttonPin = 17;

void setup() {

  Serial.begin(115200);

  myServo.attach(servoPin);

  pinMode(buttonPin, INPUT_PULLUP);

}

void loop() {

  int value = analogRead(potPin);

  int angle = map(value, 0, 4095, 0, 180);

  myServo.write(angle);

  Serial.print("Angle: ");
  Serial.println(angle);

  if (digitalRead(buttonPin) == LOW) {

    Serial.println("Sweep Started");

    for (int i = 0; i <= 180; i++) {
      myServo.write(i);
      delay(10);
    }

    for (int i = 180; i >= 0; i--) {
      myServo.write(i);
      delay(10);
    }

    Serial.println("Sweep Complete");

  }

  delay(100);

}
