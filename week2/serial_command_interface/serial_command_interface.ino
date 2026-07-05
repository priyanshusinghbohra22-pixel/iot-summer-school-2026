/*
Author: Priyanshu Singh Bohra
Date-05-07-2026

Commit 3
Features:
LED_ON
LED_OFF
BLINK_X
STATUS
RESET
*/

const int led = 2;

int blinkCount = 0;

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

      blinkCount = cmd.substring(6).toInt();

      if (blinkCount >= 1 && blinkCount <= 9) {

        for (int i = 0; i < blinkCount; i++) {

          digitalWrite(led, HIGH);
          delay(500);

          digitalWrite(led, LOW);
          delay(500);

        }

        Serial.print("Blinked ");
        Serial.print(blinkCount);
        Serial.println(" times");

      }

    }

    else if (cmd == "STATUS") {

      Serial.print("LED State: ");

      if (digitalRead(led)) {

        Serial.println("ON");

      }

      else {

        Serial.println("OFF");

      }

      Serial.print("Blink Counter: ");

      Serial.println(blinkCount);

    }

    else if (cmd == "RESET") {

      blinkCount = 0;

      Serial.println("Blink counter reset");

    }

  }

}
