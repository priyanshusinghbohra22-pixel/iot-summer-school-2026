# Project 4: Smart Plant Watering Monitor

## Overview

The Smart Plant Watering Monitor is an ESP32-based system that monitors soil moisture and temperature and automatically controls a water pump through a relay.

The system measures soil moisture using a capacitive soil moisture sensor and converts the raw sensor value into a percentage. Based on the moisture percentage, the soil condition is classified as DRY, OPTIMAL, or WET.

A hysteresis mechanism is used to prevent rapid switching of the pump. The system also includes an OLED display for real-time monitoring and a manual override button for force watering.

---

## Components Required

- ESP32 Dev Board
- Capacitive Soil Moisture Sensor
- DHT11 Temperature and Humidity Sensor
- 2-Channel Relay Module
- 0.96" SSD1306 I2C OLED Display
- Red LED for pump simulation
- Push Button
- Breadboard
- Jumper Wires
- Resistors

---

## Wiring Connections

| Component | ESP32 Connection |
|---|---|
| Soil Sensor VCC | 3.3V |
| Soil Sensor GND | GND |
| Soil Sensor AOUT | GPIO34 |
| DHT11 VCC | 3.3V |
| DHT11 GND | GND |
| DHT11 DATA | GPIO4 |
| Relay VCC | 5V / VIN |
| Relay GND | GND |
| Relay IN1 | GPIO26 |
| Push Button | GPIO0 to GND |
| OLED SDA | GPIO21 |
| OLED SCL | GPIO22 |
| OLED VCC | 3.3V |
| OLED GND | GND |

The push button uses the ESP32's internal `INPUT_PULLUP` configuration.

The relay is active-low:

- `LOW` = Relay ON
- `HIGH` = Relay OFF

A Red LED connected through the relay's COM and NO terminals is used to simulate the water pump.

---

## Working Principle

The capacitive soil moisture sensor provides an analog reading to GPIO34 of the ESP32.

The raw sensor reading is converted into a moisture percentage using calibration values.

The calibration range used for this project is:

- Dry value: approximately 3200
- Wet value: approximately 1200

The conversion is performed by mapping the sensor range to a percentage between 0% and 100%.

```text
3200 → 0% moisture
1200 → 100% moisture
