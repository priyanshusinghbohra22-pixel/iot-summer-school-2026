const int green = 10;
const int yellow = 11;
const int red = 12;
const int flame = 7; 
const int buzzer = 9;
const int gas = A0;

unsigned long previousBeep = 0;
unsigned long previousPrint = 0;

bool buzzerState = false;

void setup()
{
  Serial.begin(9600);

  pinMode(flame, INPUT_PULLUP);

  pinMode(buzzer, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(red, OUTPUT);
}

void loop()
{
  int gasValue = analogRead(gas);
  int gasPercent = map(gasValue, 0, 1023, 0, 100);

  int flameValue = digitalRead(flame);
  bool flameDetected = (flameValue == LOW);

  String status;

  if (gasPercent > 60 && flameDetected)
  {
    status = "GAS + FLAME DANGER";

    digitalWrite(green, LOW);
    digitalWrite(yellow, LOW);
    digitalWrite(red, HIGH);
    tone(buzzer, 1500);
  }
  else if (flameDetected)
  {
    status = "FLAME DANGER";
    digitalWrite(green, LOW);
    digitalWrite(yellow, LOW);
    digitalWrite(red, HIGH);
    tone(buzzer, 1200);
  }
  else if (gasPercent > 60)
  {
    status = "GAS DANGER";
    digitalWrite(green, LOW);
    digitalWrite(yellow, LOW);
    digitalWrite(red, HIGH);
    tone(buzzer, 1000);
  }
  else if (gasPercent >= 30)
  {
    status = "WARNING";

    digitalWrite(green, LOW);
    digitalWrite(yellow, HIGH);
    digitalWrite(red, LOW);
    if (millis() - previousBeep >= 500)
    {
      previousBeep = millis();
      buzzerState = !buzzerState;

      if (buzzerState)
      {
        tone(buzzer, 1000);
      }
      else
      {
        noTone(buzzer);
      }
    }
  }
  else
  {
    status = "SAFE";

    digitalWrite(green, HIGH);
    digitalWrite(yellow, LOW);
    digitalWrite(red, LOW);

    noTone(buzzer);
    buzzerState = false;
  }
  if (millis() - previousPrint >= 1000)
  {
    previousPrint = millis();

    Serial.print("GAS: ");
    Serial.print(gasPercent);
    Serial.print("% | FLAME: ");

    if (flameDetected)
      Serial.print("DETECTED");
    else
      Serial.print("NONE");

    Serial.print(" | STATUS: ");
    Serial.println(status);
  }
}
