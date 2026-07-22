# Project 9: Stepper Motor Precision Positioner

## Overview

This project implements a precision position control system for a 28BYJ-48 stepper motor using an Arduino Uno and ULN2003 driver. A potentiometer is used to set a target angle between 0° and 360°. Two push buttons control clockwise and anticlockwise movement, while a third button sets the current position as the logical home position.

An OLED display shows the current angle, target angle, direction, and current step position.

## Components Required

- Arduino Uno R3
- 28BYJ-48 Stepper Motor
- ULN2003 Driver Board
- 10kΩ Potentiometer
- 3 Push Buttons
- 0.96" I2C OLED Display
- LED
- 220Ω Resistor
- Breadboard
- Jumper Wires

## Pin Connections

| Component | Arduino Pin |
|---|---|
| ULN2003 IN1 | Pin 8 |
| ULN2003 IN2 | Pin 9 |
| ULN2003 IN3 | Pin 10 |
| ULN2003 IN4 | Pin 11 |
| Potentiometer | A0 |
| Clockwise Button | Pin 2 |
| Anticlockwise Button | Pin 3 |
| Home Button | Pin 4 |
| Position LED | Pin 5 |
| OLED SDA | A4 |
| OLED SCL | A5 |

## Working

The potentiometer value is read using the Arduino analog input and mapped to a target angle between 0° and 360°.

The Clockwise button rotates the stepper motor by 45° in the clockwise direction. The Anticlockwise button rotates it by 45° in the opposite direction.

For the 4096-step-per-revolution model used in this project:

- 360° = 4096 steps
- 45° = 512 steps

The program keeps track of the motor position using the `currentSteps` variable. The current angle is calculated from this step position.

The Home button sets `currentSteps` to zero without physically rotating the motor. Therefore, the motor's current position becomes the new logical home position.

The OLED displays:

- Current Angle
- Target Angle
- Required Direction
- Current Step Position

The LED turns ON when the current position is very close to the target position.

## Position Calculation

The current motor angle is calculated using:

Current Angle = (Current Steps × 360) / 4096

The number of steps required to reach the target is calculated using:

Steps Needed = (Target Angle - Current Angle) × 4096 / 360

A positive value indicates clockwise movement, while a negative value indicates anticlockwise movement.

## Features

- Precision stepper motor position tracking
- 0°–360° target selection using potentiometer
- Clockwise and anticlockwise manual control
- 45° movement per button command
- Logical Home position setting
- Real-time OLED display
- Target position LED indicator

## Simulation / Hardware Note

The exact 28BYJ-48 stepper motor with ULN2003 driver was not available in the simulation environment used for this project. The required hardware components were also unavailable for physical implementation at the time of submission. Therefore, the control logic and complete source code were developed according to the specified hardware configuration, but the exact hardware simulation could not be demonstrated.

## Applications

This project demonstrates the basic position-control principles used in:

- CNC machines
- 3D printers
- Robotic arms
- Camera positioning systems
- Automated mechanical systems
