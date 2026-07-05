# Traffic Light Controller with Pedestrian Button

This project simulates a **Traffic Light Control System** using ESP32, LEDs, and a pedestrian push button. The system cycles through standard traffic light states and gives priority to pedestrians when the button is pressed.

## Features

* Automatic traffic light sequencing
* Red, Yellow, and Green signal control
* Pedestrian crossing request button
* Immediate pedestrian priority handling
* Serial Monitor status updates
* Timed traffic signal operation

## Components Used

* ESP32 Development Board
* Red LED
* Yellow LED
* Green LED
* Push Button
* Breadboard
* Jumper Wires

## Connections

* Red LED → GPIO23
* Yellow LED → GPIO22
* Green LED → GPIO21
* Pedestrian Button → GPIO19

## Working

* The system cycles through:

  * **RED**
  * **YELLOW**
  * **GREEN**
* When the pedestrian button is pressed:

  * Traffic immediately switches to **RED**
  * Pedestrian crossing mode is activated
  * Crossing remains enabled for **8 seconds**
* Current signal status is displayed on the Serial Monitor.

## Output

The Serial Monitor displays messages such as:

```text
RED
YELLOW
GREEN
PEDESTRIAN CROSSING
```

## Concepts Covered

* Finite State Control
* Digital Output Interfacing
* Push Button Interfacing
* Event Handling
* Traffic Signal Automation
* Human–Machine Interaction

