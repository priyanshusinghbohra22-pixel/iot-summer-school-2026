/*
  Question 24
  Multi-Sensor Data Logger

  Sensors:
  DHT22
  LDR Module
  HC-SR04

  Connections

  DHT22 DATA -> GPIO19

  LDR AO -> GPIO33

  HC-SR04
  TRIG -> GPIO22
  ECHO -> GPIO21

  Output every 5 seconds
*/

#include <DHTesp.h>

// DHT object
DHTesp dht;

// Pin definitions

const int DHT_PIN = 19;

const int LDR_PIN = 33;

const int TRIG = 22;

const int ECHO = 21;

void setup() {

  Serial.begin(115200);

  // Initialize DHT22

  dht.setup(DHT_PIN, DHTesp::DHT22);

  // Ultrasonic pins

  pinMode(TRIG, OUTPUT);

  pinMode(ECHO, INPUT);

}

void loop() {

  /*--------------------
      DHT22 Reading
  --------------------*/

  TempAndHumidity data =
      dht.getTempAndHumidity();

  float temp =
      data.temperature;

  float humidity =
      data.humidity;

  /*--------------------
      LDR Reading
  --------------------*/

  int raw =
      analogRead(LDR_PIN);

  int light =
      map(raw, 0, 4095, 0, 100);

  /*--------------------
      HC-SR04 Reading
  --------------------*/

  digitalWrite(TRIG, LOW);

  delayMicroseconds(2);

  digitalWrite(TRIG, HIGH);

  delayMicroseconds(10);

  digitalWrite(TRIG, LOW);

  long duration =
      pulseIn(ECHO, HIGH);

  float distance =
      duration * 0.034 / 2.0;

  /*--------------------
      Serial Output
  --------------------*/

  Serial.println();

  Serial.println("=== SENSOR LOG ===");

  Serial.print("Time : ");

  Serial.print(millis());

  Serial.println(" ms");

  Serial.print("Temp : ");

  Serial.print(temp);

  Serial.print(" C | Humidity : ");

  Serial.print(humidity);

  Serial.println("%");

  Serial.print("Light : ");

  Serial.print(light);

  Serial.print("% ");

  if (light > 60) {

    Serial.println("(Bright)");

  }

  else {

    Serial.println("(Dark)");

  }

  Serial.print("Distance : ");

  Serial.print(distance);

  Serial.println(" cm");

  Serial.println("=================");

  // Update every 5 seconds

  delay(5000);

}
