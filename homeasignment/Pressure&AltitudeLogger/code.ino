#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_BMP085.h>
#include <Adafruit_SSD1306.h>

Adafruit_SSD1306 screen(128, 64, &Wire, -1);
Adafruit_BMP085 sensor;

const int green = 25;
const int red = 26;
const int pot = 34;

float pressureLog[24];
int logIndex = 0;

unsigned long lastPage = 0;
bool page = false;

unsigned long lastPrint = 0;
unsigned long lastLog = 0;


void setup() 
{
  Serial.begin(115200);
  pinMode(green, OUTPUT);
  pinMode(red, OUTPUT);

  sensor.begin();

  screen.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  screen.clearDisplay();
  screen.display();

  pressureLog[0] = sensor.readPressure();
  logIndex = 1;
}
  

void loop()
{
  float pressure = sensor.readPressure();

  if (millis() - lastLog >= 60000)
  {
    lastLog = millis();
    pressureLog[logIndex % 24] = pressure;
    logIndex++;
  }
  float temp = sensor.readTemperature();
  float altitude = sensor.readAltitude();
  int potValue = analogRead(pot);
  float localAltitude = map(potValue, 0, 4095, 0, 2000);
  float seaLevelPressure = pressure / pow(1 - localAltitude / 44330.0, 5.255);
  
  String trend;

  float difference = pressure - pressureLog[0];

  if (difference > 50)
  {
    trend = "RISING";
  }
  else if (difference < -50)
  {
    trend = "FALLING";
  }
  else
  {
    trend = "STABLE";
  }
  if (trend == "FALLING")
  {
    digitalWrite(red, HIGH);
    digitalWrite(green, LOW);
  }
  else
  { 
    digitalWrite(red, LOW);
    digitalWrite(green, HIGH);
  }


  if (millis() - lastPage >= 5000)
  {
    lastPage = millis();
    page = !page;
  }

  screen.clearDisplay();
  screen.setTextColor(SSD1306_WHITE);

  if (page == false)
  {
    screen.setTextSize(1);
    screen.setCursor(0, 0);
    screen.print("Pressure: ");
    screen.println(pressure);
    screen.print("Temp: ");
    screen.println(temp);
    screen.print("Altitude: ");
    screen.println(localAltitude);
  }
  else
  {
    screen.setTextSize(2);
    screen.setCursor(10, 20);
    screen.println(trend);
  }

  screen.display();

  if (millis() - lastPrint >= 30000)
  {
    lastPrint = millis();

    Serial.print("Pressure: ");
    Serial.print(pressure);
    Serial.print(" Pa | Temp: ");
    Serial.print(temp);
    Serial.print(" C | Altitude: ");
    Serial.print(localAltitude);
    Serial.print(" m | Trend: ");
    Serial.println(trend);
  }
}
