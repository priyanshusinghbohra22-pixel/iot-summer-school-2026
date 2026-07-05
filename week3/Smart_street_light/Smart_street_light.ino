/*
Author - Priyanshu Singh Bohra 
date - 05-07-2026 
Q23 - Smart Street Light (LDR + PIR)

Features:
- LDR below threshold (dark): Motion detection mode enabled
- PIR detects motion at night: LED ON at full brightness
- No motion after 30 seconds: LED dimmed to 20% using PWM
- LDR above threshold (daylight): LED OFF
- Events logged to Serial Monitor

Connections:
LDR AO  -> GPIO27
PIR OUT -> GPIO16
LED     -> GPIO22
*/

const int ldr = 27;
const int pir = 16;
const int led = 22;

const int threshold = 2000;

unsigned long motionTime = 0;
bool motionDetected = false;

void setup() {

  Serial.begin(115200);

  pinMode(pir, INPUT);

  ledcAttach(led, 5000, 8);

}

void loop() {

  int light = analogRead(ldr);

  int motion = digitalRead(pir);

  Serial.print("LDR = ");
  Serial.print(light);

  Serial.print(" PIR = ");
  Serial.println(motion);

  // DAY
  if (light < threshold) {

    ledcWrite(led, 0);

    motionDetected = false;

    Serial.println("[DAY] LED OFF");

  }

  // NIGHT
  else {

    if (motion == HIGH) {

      motionDetected = true;

      motionTime = millis();

      ledcWrite(led, 255);

      Serial.println("[NIGHT] Motion Detected");

    }

    else {

      if (motionDetected) {

        if (millis() - motionTime < 30000) {

          ledcWrite(led, 255);

        }

        else {

          ledcWrite(led, 51);

          Serial.println("[NIGHT] Dim Mode");

        }

      }

      else {

        ledcWrite(led, 51);

      }

    }

  }

  delay(500);

}
