# Project 1: Smart Room Climate Monitor

## Overview

The Smart Room Climate Monitor is an ESP32-based system that continuously monitors room temperature and humidity using a DHT11 sensor. The readings are displayed on a 0.96-inch OLED display.

When the temperature exceeds 38°C or the humidity exceeds 80%, the system activates a Red LED and a buzzer to indicate an alert condition. Under normal conditions, the Green LED remains ON.

The system also displays a comfort status and logs sensor readings to the Serial Monitor in CSV format.

---

## Components Required

- ESP32 Dev Board
- DHT11 Temperature and Humidity Sensor
- 0.96" SSD1306 I2C OLED Display
- Active Buzzer
- Red LED
- Green LED
- 220Ω Resistors
- 10kΩ Resistor
- Breadboard
- Jumper Wires
- USB Cable

---

## Wiring Connections

| Component | Connection |
|---|---|
| DHT11 VCC | ESP32 3.3V |
| DHT11 GND | ESP32 GND |
| DHT11 DATA | GPIO4 |
| OLED VCC | ESP32 3.3V |
| OLED GND | ESP32 GND |
| OLED SDA | GPIO21 |
| OLED SCL | GPIO22 |
| Red LED | GPIO25 through 220Ω resistor |
| Green LED | GPIO26 through 220Ω resistor |
| Buzzer (+) | GPIO27 |
| Buzzer (-) | GND |

The DHT11 DATA pin uses a 10kΩ pull-up resistor connected to 3.3V.

---

## Libraries Used

- DHTesp
- Adafruit GFX Library
- Adafruit SSD1306 Library
- Wire Library

> Library versions depend on the versions installed in the Arduino IDE or simulation environment used for the project.

---

## Working Principle

The ESP32 reads temperature and humidity values from the DHT11 sensor every 2 seconds.

The OLED displays:

- Temperature in °C
- Humidity in %
- Comfort status

The alert condition is:

- Temperature > 38°C, OR
- Humidity > 80%

When an alert condition occurs:

- Red LED turns ON
- Green LED turns OFF
- Buzzer is activated

Under normal conditions:

- Green LED turns ON
- Red LED remains OFF
- Buzzer remains OFF

The comfort status is displayed as one of the following:

- COOL
- COMFORT
- HOT
- DANGER

The sensor readings are also logged to the Serial Monitor in CSV format every 5 seconds.

---

## Serial Monitor Output

The output is displayed in the following CSV format:

```text
millis,temp,humidity,status
5000,28.3,65.0,COMFORT
10000,29.1,67.0,COMFORT
15000,39.2,70.0,DANGER
20000,31.5,82.0,DANGER
25000,27.8,60.0,COOL
