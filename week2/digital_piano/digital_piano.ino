/*
Author: Priyanshu Singh Bohra
Date: 05-07-2026

Project: Digital Piano using ESP32

Description:
A digital piano implemented using ESP32, five push buttons,
and a passive buzzer.

Features:
1. Four buttons generate Do, Re, Mi and Fa notes.
2. Pressing Button1 and Button2 together plays Sol (392 Hz).
3. A fifth button toggles between Major and Minor scales.
4. Serial Monitor displays the currently played note and mode.

Pin Configuration:
BTN1   -> GPIO16
BTN2   -> GPIO17
BTN3   -> GPIO18
BTN4   -> GPIO21
BTN5   -> GPIO22
BUZZER -> GPIO25
*/


const int BTN1 = 16;
const int BTN2 = 17;
const int BTN3 = 18;
const int BTN4 = 21;
const int BTN5 = 22;

const int BUZZER = 25;

bool major = true;

void setup() {

  pinMode(BTN1, INPUT_PULLUP);
  pinMode(BTN2, INPUT_PULLUP);
  pinMode(BTN3, INPUT_PULLUP);
  pinMode(BTN4, INPUT_PULLUP);
  pinMode(BTN5, INPUT_PULLUP);

  Serial.begin(115200);

  ledcAttach(BUZZER, 2000, 8);

}

void loop() {

  // Toggle Mode
  if (digitalRead(BTN5) == LOW) {

    major = !major;

    if (major) {

      Serial.println("MAJOR MODE");

    }

    else {

      Serial.println("MINOR MODE");

    }

    delay(300);

  }

  // SOL chord
  if (digitalRead(BTN1) == LOW &&
      digitalRead(BTN2) == LOW) {

    Serial.println("SOL");

    ledcWriteTone(BUZZER, 392);

  }

  // DO
  else if (digitalRead(BTN1) == LOW) {

    Serial.println("DO");

    ledcWriteTone(BUZZER, major ? 262 : 247);

  }

  // RE
  else if (digitalRead(BTN2) == LOW) {

    Serial.println("RE");

    ledcWriteTone(BUZZER, major ? 294 : 277);

  }

  // MI
  else if (digitalRead(BTN3) == LOW) {

    Serial.println("MI");

    ledcWriteTone(BUZZER, major ? 330 : 311);

  }

  // FA
  else if (digitalRead(BTN4) == LOW) {

    Serial.println("FA");

    ledcWriteTone(BUZZER, major ? 349 : 330);

  }

  else {

    ledcWriteTone(BUZZER, 0);

  }

  delay(100);

}
