/*
Mysensors Sensebender micro blink example
*/

#include <Arduino.h>

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin as an output.
  pinMode(A2, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(A2, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(100);              // wait for 0.1 sec
  digitalWrite(A2, LOW);   // turn the LED off by making the voltage LOW
  delay(100);              // wait for 0.1 sec
  digitalWrite(A2, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(100);              // wait for 0.1 sec
  digitalWrite(A2, LOW);   // turn the LED off by making the voltage LOW
  delay(1000);             // wait for a second
}
