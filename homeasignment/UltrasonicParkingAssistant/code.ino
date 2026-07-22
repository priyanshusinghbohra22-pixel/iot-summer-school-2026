#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

const int trig = 9;
const int echo = 10;
const int green = 11;
const int yellow = 12;
const int red = 13;
const int buzzer = 6;

#define W 128
#define H 64
#define RST -1
Adafruit_SSD1306 oled(W, H, &Wire, RST);

unsigned long lastbeep = 0;
unsigned long lastPrint = 0;


void setup()
{
  Serial.begin(9600);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(buzzer, OUTPUT);

  oled.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  oled.clearDisplay();
  oled.display();
}
void loop()
{
  float sum = 0;
  for (int i = 0; i < 5; i++) 
  {
    digitalWrite(trig, LOW);
    delayMicroseconds(2);
    digitalWrite(trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig, LOW);
    long duration = pulseIn(echo, HIGH); 
    float distance = duration * 0.0343 / 2;
    sum = sum + distance;
  }
  float average = sum/5;

  oled.clearDisplay();
  oled.setTextColor(SSD1306_WHITE);
  oled.setTextSize(2);
  oled.setCursor(10, 5);
  oled.print(average, 0);
  oled.print(" cm");
  int bar = map((int)average, 60, 0, 0, 120);
  bar = constrain(bar, 0, 120);
  oled.drawRect(4, 40, 120, 15, SSD1306_WHITE);
  oled.fillRect(4, 40, bar, 15, SSD1306_WHITE);
  oled.display();


  if (average > 60 )
  {
    digitalWrite(green, HIGH);
    digitalWrite(red, LOW);
    digitalWrite(yellow, LOW);
    noTone(buzzer);
    Serial.println("SAFE");   
  }
  else if(average >= 30 )
  {
    digitalWrite(green, LOW);
    digitalWrite(red, LOW);
    digitalWrite(yellow, HIGH);
    if (millis() - lastbeep >=800)
    {
      lastbeep = millis();
      tone(buzzer,1000,100);
    } 
    Serial.println("CAUTION"); 
  }
  else if(average >=15 )
  {
    digitalWrite(green, LOW);
    digitalWrite(red, HIGH);
    digitalWrite(yellow, HIGH);
    if (millis() - lastbeep >=300)
    {
      lastbeep = millis();
      tone(buzzer,1000,100);
    } 
    Serial.println("CLOSE"); 
  }
  else
  {
    digitalWrite(green, LOW);
    digitalWrite(red, HIGH);
    digitalWrite(yellow, LOW);
    tone(buzzer,1000);
    Serial.println("DANGER"); 
  }
  if (millis() - lastPrint >= 500)
  {
    lastPrint = millis();

    Serial.print("Distance: ");
    Serial.print(average);
    Serial.println(" cm");
  }
}  

