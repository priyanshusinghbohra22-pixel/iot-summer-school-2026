# Serial Command Interface using ESP32

This project demonstrates a **Serial Command Interface** implemented on ESP32, allowing the user to control an LED and monitor its status through commands sent from the Serial Monitor.

## Features

* Turn LED ON using `LED_ON`
* Turn LED OFF using `LED_OFF`
* Blink LED multiple times using `BLINK_X`
* Display LED status using `STATUS`
* Reset blink counter using `RESET`
* Command-based interaction through Serial Monitor

## Components Used

* ESP32 Development Board
* LED
* Breadboard
* Jumper Wires

## Connections

* LED → GPIO2

## Supported Commands

| Command   | Function                           |
| --------- | ---------------------------------- |
| `LED_ON`  | Turns the LED ON                   |
| `LED_OFF` | Turns the LED OFF                  |
| `BLINK_X` | Blinks the LED X times (1–9)       |
| `STATUS`  | Displays LED state and blink count |
| `RESET`   | Resets the blink counter           |

## Output

The Serial Monitor displays responses such as:

```text
Serial Command Interface Ready

LED ON

LED OFF

Blinked 5 times

LED State: ON
Blink Counter: 5

Blink counter reset
```

## Concepts Covered

* Serial Communication
* String Processing
* Command Parsing
* Digital Output Control
* User Interaction through Serial Monitor
* Embedded System Interfaces

