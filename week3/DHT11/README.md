# Environmental Monitoring Station using ESP32 and DHT22

## Overview

This project implements an Environmental Monitoring Station using an ESP32 and a DHT22 sensor. The system continuously measures temperature and humidity, converts temperature values from Celsius to Fahrenheit, and provides visual alerts using LEDs when environmental conditions exceed predefined thresholds.

-## Libraries Used

- DHT sensor library for ESPx v1.18.0

## Features

* Temperature measurement in Celsius (°C)
* Temperature conversion to Fahrenheit (°F)
* Humidity measurement (%RH)
* CSV formatted serial output
* Data logging every 2 seconds
* Real-time environmental monitoring
* LED-based status indication

## Components Used

* ESP32 Development Board
* DHT22 Temperature and Humidity Sensor
* Green LED
* Red LED
* Breadboard
* Jumper Wires

## Circuit Connections

| Component  | ESP32 Pin |
| ---------- | --------- |
| DHT22 DATA | GPIO25    |
| Green LED  | GPIO22    |
| Red LED    | GPIO23    |
| VCC        | 3.3V      |
| GND        | GND       |

## Working Principle

The DHT22 sensor measures temperature and humidity values. The ESP32 reads these values every 2 seconds and sends the data to the Serial Monitor in CSV format:

```csv
timestamp,temp_C,temp_F,humidity
```

Temperature values are converted from Celsius to Fahrenheit using:

```cpp
tempF = tempC * 9 / 5 + 32;
```

### Alert Conditions

The system enters an alert state when:

* Temperature > 35°C
* Humidity > 80%

During alert conditions:

* Red LED turns ON
* Green LED turns OFF

Under normal conditions:

* Green LED remains ON
* Red LED remains OFF

## Applications

* Smart Agriculture
* Greenhouse Monitoring
* Weather Stations
* Industrial Environmental Monitoring
* Home Automation Systems

## Author

Priyanshu Singh Bohra

Date: 05-07-2026

