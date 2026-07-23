# Project 8: IoT Pressure & Altitude Logger

## Overview

The IoT Pressure & Altitude Logger is an ESP32-based environmental monitoring system that measures atmospheric pressure, temperature, and altitude.

The system stores pressure readings and analyzes changes in atmospheric pressure to classify the pressure trend as:

- RISING
- FALLING
- STABLE

An OLED display is used to show sensor readings and pressure trends on separate pages. A potentiometer is used to set the local altitude for sea-level pressure compensation.

## Components Required

- ESP32 Dev Board
- BMP280 Pressure Sensor
- 0.96" SSD1306 I2C OLED Display
- 10kΩ Potentiometer
- Green LED
- Red LED
- 220Ω Resistors
- Breadboard
- Jumper Wires

## Simulation Note

The original project specifies a BMP280 sensor. During simulation, a BMP180 sensor was used as an alternative due to simulator component availability.

The BMP180 also provides atmospheric pressure and temperature readings and was used to demonstrate the main pressure-logging and trend-detection concepts of the project.

## Wiring Connections

| Component | ESP32 Connection |
|---|---|
| BMP180/BMP280 VCC | 3.3V |
| BMP180/BMP280 GND | GND |
| BMP180/BMP280 SDA | GPIO21 |
| BMP180/BMP280 SCL | GPIO22 |
| OLED VCC | 3.3V |
| OLED GND | GND |
| OLED SDA | GPIO21 |
| OLED SCL | GPIO22 |
| Potentiometer VCC | 3.3V |
| Potentiometer GND | GND |
| Potentiometer Signal | GPIO34 |
| Green LED | GPIO25 through 220Ω |
| Red LED | GPIO26 through 220Ω |

The pressure sensor and OLED share the same I2C SDA and SCL lines because they use different I2C addresses.

## Working Principle

The pressure sensor measures:

- Atmospheric pressure
- Temperature
- Calculated altitude

The potentiometer value is read through GPIO34 and mapped to a local altitude between 0 and 2000 metres.

Pressure readings are stored in an array containing up to 24 readings. The system compares pressure readings to determine whether atmospheric pressure is rising, falling, or remaining stable.

## Pressure Trend Calculation

The difference between the newer and older pressure readings is calculated.

The trend conditions are:

- Difference greater than +50 Pa → RISING
- Difference less than -50 Pa → FALLING
- Difference between -50 Pa and +50 Pa → STABLE

### LED Indication

When the pressure trend is RISING or STABLE:

- Green LED turns ON
- Red LED turns OFF

When the pressure trend is FALLING:

- Red LED turns ON
- Green LED turns OFF

## Circular Buffer

The project uses an array of 24 pressure readings.

After reaching the last position in the array, the index returns to the beginning and starts replacing the oldest readings.

This allows the system to continuously maintain a history of the most recent pressure measurements without requiring an unlimited amount of memory.

## Sea-Level Pressure Compensation

Atmospheric pressure changes with altitude. A pressure measurement taken at a high altitude will normally be lower than a measurement taken at sea level.

To compare pressure readings from different altitudes, the measured atmospheric pressure can be converted to equivalent sea-level pressure.

The formula used is:

P0 = P / (1 - altitude / 44330)^5.255

Where:

- P0 = Calculated sea-level pressure
- P = Measured atmospheric pressure
- altitude = Local altitude in metres

The potentiometer allows the user to simulate or set the known local altitude between 0 and 2000 metres.

As the selected altitude increases, the calculated sea-level pressure is adjusted accordingly.

## OLED Display

The OLED cycles between two pages approximately every 5 seconds.

### Page 1

Displays environmental readings:

- Pressure
- Temperature
- Altitude

Example:

Pressure: 101325 Pa  
Temp: 27.5 C  
Altitude: 120 m

### Page 2

Displays the calculated pressure trend:

RISING

or

FALLING

or

STABLE

## Serial Monitor Output

The system prints pressure, temperature, altitude, and trend information to the Serial Monitor.

Example:

Pressure: 101325 Pa | Temp: 27.5 C | Altitude: 120 m | Trend: STABLE

Pressure: 101410 Pa | Temp: 27.6 C | Altitude: 120 m | Trend: RISING

Pressure: 101290 Pa | Temp: 27.4 C | Altitude: 120 m | Trend: FALLING

## Features

- Atmospheric pressure monitoring
- Temperature monitoring
- Altitude calculation
- Local altitude adjustment using potentiometer
- Sea-level pressure compensation
- Pressure history storage
- Pressure trend detection
- RISING, FALLING, and STABLE classification
- Red and Green LED trend indication
- Two-page OLED display
- Serial Monitor logging

## Applications

- Weather monitoring systems
- Basic weather trend prediction
- Altitude monitoring
- Environmental data logging
- IoT weather stations

## Conclusion

The IoT Pressure & Altitude Logger demonstrates how atmospheric pressure data can be collected and analyzed to identify pressure trends. The system combines pressure sensing, altitude compensation, historical data storage, LED indicators, and an OLED display to create a basic environmental monitoring and weather prediction system.
