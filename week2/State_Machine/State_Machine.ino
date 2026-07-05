/*
Author - Priyanshu Singh Bohra 
Date - 05 / 07 /2026
State Transition Diagram

IDLE
 |
Coin Inserted
 |
 v
COIN_INSERTED
 |
Select Item
 |
 v
ITEM_SELECTED
 |
Dispensing
 |
 v
DISPENSING
 |
Complete
 |
 v
IDLE

Cancel:
COIN_INSERTED -> IDLE
ITEM_SELECTED -> IDLE
*/

enum State {

  IDLE,
  COIN_INSERTED,
  ITEM_SELECTED,
  DISPENSING

};

State currentState = IDLE;

const int coinBtn = 25;
const int selectBtn = 33;
const int cancelBtn = 32;

const int redLED = 16;
const int yellowLED = 17;
const int greenLED = 18;

void setup() {

  pinMode(coinBtn, INPUT_PULLUP);
  pinMode(selectBtn, INPUT_PULLUP);
  pinMode(cancelBtn, INPUT_PULLUP);

  pinMode(redLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(greenLED, OUTPUT);

  Serial.begin(115200);

  Serial.println("State = IDLE");

}

void loop() {

  switch (currentState) {

    case IDLE:

      digitalWrite(redLED, HIGH);
      digitalWrite(yellowLED, LOW);
      digitalWrite(greenLED, LOW);

      if (digitalRead(coinBtn) == LOW) {

        currentState = COIN_INSERTED;

        Serial.println("IDLE -> COIN_INSERTED");

        delay(300);

      }

      break;

    case COIN_INSERTED:

      digitalWrite(redLED, LOW);
      digitalWrite(yellowLED, HIGH);
      digitalWrite(greenLED, LOW);

      if (digitalRead(selectBtn) == LOW) {

        currentState = ITEM_SELECTED;

        Serial.println("COIN_INSERTED -> ITEM_SELECTED");

        delay(300);

      }

      else if (digitalRead(cancelBtn) == LOW) {

        currentState = IDLE;

        Serial.println("COIN_INSERTED -> IDLE");

        delay(300);

      }

      break;

    case ITEM_SELECTED:

      digitalWrite(redLED, LOW);
      digitalWrite(yellowLED, LOW);
      digitalWrite(greenLED, HIGH);

      Serial.println("ITEM_SELECTED -> DISPENSING");

      currentState = DISPENSING;

      delay(1000);

      break;

    case DISPENSING:

      digitalWrite(redLED, HIGH);
      digitalWrite(yellowLED, HIGH);
      digitalWrite(greenLED, HIGH);

      Serial.println("DISPENSING -> IDLE");

      delay(2000);

      currentState = IDLE;

      break;

  }

}
