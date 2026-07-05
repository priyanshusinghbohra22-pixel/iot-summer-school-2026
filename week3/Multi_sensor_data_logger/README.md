# Multi-Sensor Data Logger using ESP32

## Overview

This project implements a Multi-Sensor Data Logger using an ESP32 development board. It integrates three sensors—DHT22, LDR, and HC-SR04—to monitor environmental conditions and distance measurements simultaneously. Sensor readings are displayed on the Serial Monitor every 5 seconds.

## Features

* Temperature measurement using DHT22
* Humidity measurement using DHT22
* Ambient light intensity monitoring using LDR
* Distance measurement using HC-SR04 ultrasonic sensor
* Bright/Dark condition detection
* Periodic data logging every 5 seconds
* Real-time serial monitoring

## Components Used

* ESP32 Development Board
* DHT22 Temperature and Humidity Sensor
* LDR Module
* HC-SR04 Ultrasonic Sensor
* Breadboard
* Jumper Wires

## Circuit Connections

| Component    | ESP32 Pin               |
| ------------ | ----------------------- |
| DHT22 DATA   | GPIO19                  |
| LDR AO       | GPIO33                  |
| HC-SR04 TRIG | GPIO22                  |
| HC-SR04 ECHO | GPIO21                  |
| VCC          | 3.3V / 5V (as required) |
| GND          | GND                     |

## Working Principle

The ESP32 reads data from three sensors:

### DHT22

Measures:

* Temperature (°C)
* Humidity (%)

### LDR Module

Reads analog light intensity values and maps them to a percentage scale (0–100%).

* Light > 60% → Bright
* Light ≤ 60% → Dark

### HC-SR04

Measures the distance of nearby objects using ultrasonic waves.

Distance is calculated using:

```cpp
distance = duration * 0.034 / 2.0;
```

## Serial Output Example

```text
=== SENSOR LOG ===
Time : 15000 ms
Temp : 29.4 C | Humidity : 65%
Light : 72% (Bright)
Distance : 18.5 cm
=================
```

## Applications

* Smart Agriculture
* Environmental Monitoring
* Home Automation
* Smart Lighting Systems
* Obstacle Detection
* IoT Data Logging

## Author

Priyanshu Singh Bohra

Date: 05-07-2026

