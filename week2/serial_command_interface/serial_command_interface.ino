/*
Author: Priyanshu Singh Bohra
Commit 1

Features:
LED_ON
LED_OFF
*/

const int led = 2;

void setup() {

  pinMode(led, OUTPUT);

  Serial.begin(115200);

  Serial.println("Serial Command Interface Ready");

}

void loop() {

  if (Serial.available()) {

    String cmd = Serial.readStringUntil('\n');

    cmd.trim();

    if (cmd == "LED_ON") {

      digitalWrite(led, HIGH);

      Serial.println("LED ON");

    }

    else if (cmd == "LED_OFF") {

      digitalWrite(led, LOW);

      Serial.println("LED OFF");

    }

  }

}
