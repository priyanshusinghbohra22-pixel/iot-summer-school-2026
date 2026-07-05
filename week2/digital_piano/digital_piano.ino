const int BTN1 = 16;
const int BTN2 = 17;
const int BTN3 = 18;
const int BTN4 = 21;

const int BUZZER = 25;

void setup() {

  pinMode(BTN1, INPUT_PULLUP);
  pinMode(BTN2, INPUT_PULLUP);
  pinMode(BTN3, INPUT_PULLUP);
  pinMode(BTN4, INPUT_PULLUP);

  Serial.begin(115200);

  ledcAttach(BUZZER, 2000, 8);

}

void loop() {

  if (digitalRead(BTN1) == LOW) {

    Serial.println("DO");

    ledcWriteTone(BUZZER, 262);

  }

  else if (digitalRead(BTN2) == LOW) {

    Serial.println("RE");

    ledcWriteTone(BUZZER, 294);

  }

  else if (digitalRead(BTN3) == LOW) {

    Serial.println("MI");

    ledcWriteTone(BUZZER, 330);

  }

  else if (digitalRead(BTN4) == LOW) {

    Serial.println("FA");

    ledcWriteTone(BUZZER, 349);

  }

  else {

    ledcWriteTone(BUZZER, 0);

  }

  delay(100);

}
