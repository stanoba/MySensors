/**
 * The MySensors Arduino library handles the wireless radio link and protocol
 * between your home built sensors/actuators and HA controller of choice.
 * The sensors forms a self healing radio network with optional repeaters. Each
 * repeater and gateway builds a routing tables in EEPROM which keeps track of the
 * network topology allowing messages to be routed to nodes.
 *
 * Created by Henrik Ekblad <henrik.ekblad@mysensors.org>
 * Copyright (C) 2013-2015 Sensnology AB
 * Full contributor list: https://github.com/mysensors/Arduino/graphs/contributors
 *
 * Documentation: http://www.mysensors.org
 * Support Forum: http://forum.mysensors.org
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * version 2 as published by the Free Software Foundation.
 *
 *******************************
 *
 * DESCRIPTION
 *
 * Simple binary switch example 
 * Connect button or door/window reed switch between 
 * digitial I/O pin 3 (BUTTON_PIN below) and GND.
 * http://www.mysensors.org/build/binary
 */

// Inspired by https://github.com/OliverHi/MultiuseSensorPlatform/blob/master/Software/ButtonDoor/ButtonDoor.ino

// Enable debug prints to serial monitor
#define MY_DEBUG 

#define MY_NODE_ID 235 // Node ID

#define MY_BAUD_RATE 9600

// Use built in LED if uncommented
#define LED_PIN A2

// Enable and select radio type attached
#define MY_RADIO_RF24

int oldBatteryPcnt = 0;
#define FULL_BATTERY 3.2 // 3V for 2xAA alkaline. Adjust if you use a different battery setup.
#define ONE_DAY_SLEEP_TIME  86400000  // report battery status each day at least once

#include <MySensors.h>

#define CHILD_ID 3
#define BUTTON_PIN  3  // Arduino Digital I/O pin for reed switch

// Change to V_LIGHT if you use S_LIGHT in presentation below
MyMessage msg(CHILD_ID,V_TRIPPED);

void setup()  
{  
  // Setup the button
  pinMode(BUTTON_PIN,INPUT);
  // Activate internal pull-up
  digitalWrite(BUTTON_PIN,HIGH);

  // Setup built in LED
  #ifdef LED_PIN
    pinMode(LED_PIN, OUTPUT);
  #endif
}

void presentation() {
  // Send the sketch version information to the gateway and Controller
  sendSketchInfo("MailBox", "1.0");

  // Register binary input sensor to gw (they will be created as child devices)
  // You can use S_DOOR, S_MOTION or S_LIGHT here depending on your usage. 
  // If S_LIGHT is used, remember to update variable type you send in. See "msg" above.
  present(CHILD_ID, S_DOOR);  
}

//  Check if digital input has changed and send in new value
void loop() 
{
  // turn the LED ON
  #ifdef LED_PIN
    digitalWrite(LED_PIN, HIGH);
  #endif

  // debouncing
  wait(50);

  // get the battery Voltage
  long batteryMillivolts = hwCPUVoltage();
  int batteryPcnt = batteryMillivolts / FULL_BATTERY / 1000.0 * 100 + 0.5;

  // check if the door/button is open or closed
  if (digitalRead(BUTTON_PIN) == HIGH) {
    send(msg.set("0")); // door open
  } else {
    send(msg.set("1")); // door closed
  }

  // Check battery state
  if (oldBatteryPcnt != batteryPcnt) {
      sendBatteryLevel(batteryPcnt);
      oldBatteryPcnt = batteryPcnt;
  }

  // turn the LED OFF
  #ifdef LED_PIN
    digitalWrite(LED_PIN, LOW);
  #endif

  // Sleep until something happens with the sensor
  sleep(BUTTON_PIN - 2, CHANGE, ONE_DAY_SLEEP_TIME);
}
