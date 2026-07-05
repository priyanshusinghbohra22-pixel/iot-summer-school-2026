  /*
Author - Priyanshu Singh Bohra 
Date - 05-07-2026

Environmental Monitoring Station

Sensor Connections:
DHT22 DATA -> GPIO25
Green LED  -> GPIO22
Red LED    -> GPIO23

Features:
- Reads temperature in Celsius
- Converts temperature to Fahrenheit
- Reads humidity percentage
- Logs readings every 2 seconds
- Outputs data in CSV format
- Red LED turns ON when:
  Temperature > 35°C
  OR
  Humidity > 80%
- Green LED indicates normal conditions


*/
  
#include <DHTesp.h>

DHTesp dht;

const int DHT_PIN = 25;

const int GREEN = 22;
const int RED = 23;

void setup() {

  Serial.begin(115200);

  dht.setup(DHT_PIN, DHTesp::DHT22);

  pinMode(GREEN, OUTPUT);
  pinMode(RED, OUTPUT);

  Serial.println("timestamp,temp_C,temp_F,humidity");

}

void loop() {

  TempAndHumidity data = dht.getTempAndHumidity();

  float tempC = data.temperature;

  float humidity = data.humidity;

  float tempF = tempC * 9 / 5 + 32;

  unsigned long timestamp = millis();

  Serial.print(timestamp);
  Serial.print(",");

  Serial.print(tempC);
  Serial.print(",");

  Serial.print(tempF);
  Serial.print(",");

  Serial.println(humidity);

  if (tempC > 35 || humidity > 80) {

    digitalWrite(RED, HIGH);

    digitalWrite(GREEN, LOW);

  }

  else {

    digitalWrite(RED, LOW);

    digitalWrite(GREEN, HIGH);

  }

  delay(2000);

}
