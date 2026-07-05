/*
Author: Priyanshu Singh Bohra

Commit 2
Features:
LED_ON
LED_OFF
BLINK_X
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

    else if (cmd.startsWith("BLINK_")) {

      int count = cmd.substring(6).toInt();

      if (count >= 1 && count <= 9) {

        for (int i = 0; i < count; i++) {

          digitalWrite(led, HIGH);
          delay(500);

          digitalWrite(led, LOW);
          delay(500);

        }

        Serial.print("Blinked ");
        Serial.print(count);
        Serial.println(" times");

      }

    }

  }

}
