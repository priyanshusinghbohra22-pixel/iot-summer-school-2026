#include <DHTesp.h>
#include <Adafruit_SSD1306.h>
#include <Wire.h>
#include <Adafruit_GFX.h>

const int red = 25;
const int green = 26;
const int buzzer = 27;
const int dhtPIN = 4;
const int SDAPIN= 21;
const int SCLPIN = 22;
DHTesp dht;
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() 
{
  Serial.begin(115200);
  dht.setup(dhtPIN, DHTesp::DHT22);
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(buzzer, OUTPUT);

  Wire.begin(SDAPIN, SCLPIN);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
}
void loop()
{
  TempAndHumidity data = dht.getTempAndHumidity();
  float temperature = data.temperature;
  float humidity = data.humidity;

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.print("Temp: ");
  display.print(temperature);
  display.println(" C");
  display.setCursor(0, 16);
  display.print("Hum: ");
  display.print(humidity);
  display.println(" %");
  display.display();

  Serial.print("Temperature: ");
  Serial.println(temperature);
  Serial.print("Humidity: ");
  Serial.println(humidity);
  delay(2000);

  if(temperature > 38 || humidity > 80 )
  {
    delay(2000);
    digitalWrite(red,HIGH);
    digitalWrite(green, LOW);
    digitalWrite(buzzer, HIGH);
    delay(1000);
    digitalWrite(buzzer, LOW);

  }
  else
  {
    digitalWrite(red, LOW);
    digitalWrite(green, HIGH);
    digitalWrite(buzzer, LOW);
  }

  String status;
  if(temperature > 38 || humidity > 80)
 {
  status = "DANGER";
 }
 else if (temperature > 30 || humidity > 70)
 {
   status = "HOT";
 }
 else if (temperature >= 20 && humidity >= 40)
 {
   status = "COMFORT";
 }
 else
 {
   status = "COOL";
 }

 display.setCursor(0, 32);
 display.print("Status: ");
 display.println(status);
 
}

