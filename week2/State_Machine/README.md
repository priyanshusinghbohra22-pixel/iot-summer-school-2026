# Vending Machine State Machine using ESP32

This project demonstrates the implementation of a **Finite State Machine (FSM)** for a vending machine using ESP32, push buttons, and LEDs.

## States Implemented

* **IDLE**
* **COIN_INSERTED**
* **ITEM_SELECTED**
* **DISPENSING**

## Features

* Coin insertion detection
* Item selection mechanism
* Cancel operation support
* Automatic dispensing process
* LED indication for each state
* State transition monitoring through Serial Monitor

## Components Used

* ESP32
* 3 Push Buttons
* 3 LEDs
* Resistors
* Breadboard
* Jumper Wires

## Connections

* Coin Button → GPIO25

* Select Button → GPIO33

* Cancel Button → GPIO32

* Red LED → GPIO16

* Yellow LED → GPIO17

* Green LED → GPIO18

## State Transitions

* `IDLE → COIN_INSERTED`
* `COIN_INSERTED → ITEM_SELECTED`
* `ITEM_SELECTED → DISPENSING`
* `DISPENSING → IDLE`

### Cancel Operation

* `COIN_INSERTED → IDLE`
* `ITEM_SELECTED → IDLE`

## Output

The Serial Monitor displays state transitions such as:

```text
IDLE -> COIN_INSERTED
COIN_INSERTED -> ITEM_SELECTED
ITEM_SELECTED -> DISPENSING
DISPENSING -> IDLE
```

