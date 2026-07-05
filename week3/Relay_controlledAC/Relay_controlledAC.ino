/*
Author : Priyanshu Singh Bohra
Date : 05 July 2026

Q27 : Relay Controlled AC Device Simulation

Description:
Simulates an AC appliance using an LED as a relay.

Features:
• DHT22 monitors temperature continuously
• Relay (LED) turns ON above 32°C
• Relay (LED) turns OFF below 28°C
• Manual override button
• Serial logging of state changes
• Hysteresis implemented

Connections:

DHT22
VCC  -> 3.3V
DATA -> GPIO23
GND  -> GND

Relay Simulation LED
GPIO22 -> 220Ω Resistor -> LED -> GND

Push Button
GPIO17 -> Button -> GND
(INPUT_PULLUP enabled)

Library:
DHT sensor library for ESPx
Version: 1.19.0
*/

#include <DHTesp.h>

DHTesp dht;

const int DHT_PIN = 23;
const int LED = 22;
const int BUTTON = 17;

bool relayState = false;

void setup() {

  Serial.begin(115200);

  dht.setup(DHT_PIN, DHTesp::DHT22);

  pinMode(LED, OUTPUT);

  pinMode(BUTTON, INPUT_PULLUP);

  digitalWrite(LED, LOW);

  Serial.println("AC Device Simulation Started");

}

void loop() {

  TempAndHumidity data = dht.getTempAndHumidity();

  float temp = data.temperature;

  if (temp > 32 && !relayState) {

    relayState = true;

    digitalWrite(LED, HIGH);

    Serial.println("Relay ON");

  }

  else if (temp < 28 && relayState) {

    relayState = false;

    digitalWrite(LED, LOW);

    Serial.println("Relay OFF");

  }

  if (digitalRead(BUTTON) == LOW) {

    relayState = !relayState;

    digitalWrite(LED, relayState);

    Serial.println("Manual Override Activated");

    delay(300);

  }

  Serial.print("Temperature: ");
  Serial.print(temp);
  Serial.print(" °C");

  Serial.print("   Relay: ");

  if (relayState) {

    Serial.println("ON");

  }

  else {

    Serial.println("OFF");

  }

  delay(1000);

}
