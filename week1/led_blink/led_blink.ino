/*
Author: Priyanshu Singh Bohra
Date: 05-07-2026
Description: LED Blink Program

The LED connected to pin 13 turns ON for one second
and OFF for one second repeatedly.
*/

void setup() {
    pinMode(13, OUTPUT);
}

void loop() {
    digitalWrite(13, HIGH);
    delay(1000);

    digitalWrite(13, LOW);
    delay(1000);
}
