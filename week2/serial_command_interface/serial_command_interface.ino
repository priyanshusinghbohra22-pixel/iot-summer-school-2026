/*
Author: Priyanshu Singh Bohra

Commit 4
Features:
LED_ON
LED_OFF
BLINK_X
STATUS
RESET

Input Validation Added
Unknown Command Detection
Range Checking (1–9)
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

      String num = cmd.substring(6);

      bool valid = true;

      for (int i = 0; i < num.length(); i++) {

        if (!isDigit(num[i])) {

          valid = false;
          break;

        }

      }

      if (valid) {

        blinkCount = num.toInt();

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

        else {

          Serial.println("Error: Blink value must be between 1 and 9");

        }

      }

      else {

        Serial.println("Error: Invalid BLINK command");

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

    else {

      Serial.println("Error: Unknown command");

    }

  }

}
