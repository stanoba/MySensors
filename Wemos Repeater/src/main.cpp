/*
 * The MySensors Arduino library handles the wireless radio link and protocol
 * between your home built sensors/actuators and HA controller of choice.
 * The sensors forms a self healing radio network with optional repeaters. Each
 * repeater and gateway builds a routing tables in EEPROM which keeps track of the
 * network topology allowing messages to be routed to nodes.
 *
 * Created by Henrik Ekblad <henrik.ekblad@mysensors.org>
 * Copyright (C) 2013-2019 Sensnology AB
 * Full contributor list: https://github.com/mysensors/MySensors/graphs/contributors
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
 * REVISION HISTORY
 * Version 1.0 - Henrik Ekblad
 *
 * DESCRIPTION
 * Example sketch showing how to create a node that repeats messages
 * from nodes far from gateway back to gateway.
 * It is important that nodes that has enabled repeater mode calls
 * process() frequently. Repeaters should never sleep.
 */

// Enable debug prints to serial monitor
#define MY_DEBUG

// Use a bit lower baudrate for serial prints on ESP8266 than default in MyConfig.h
#define MY_BAUD_RATE 9600

#define MY_NODE_ID 250 // Node ID

// Enable and select radio type attached
#define MY_RADIO_RF24

#define MY_SIGNAL_REPORT_ENABLED

// PA Level == RF24_PA_MIN=-18dBm, RF24_PA_LOW=-12dBm, RF24_PA_HIGH=-6dBM, and RF24_PA_MAX=0dBm
#define MY_RF24_PA_LEVEL RF24_PA_MAX 

// Enabled repeater feature for this node
#define MY_REPEATER_FEATURE

#include <MySensors.h>

void setup()
{
	// Setup locally attached sensors
}

void presentation()
{
	//Send the sensor node sketch version information to the gateway
	sendSketchInfo("Repeater Node", "1.0");
}

void loop()
{
    // Send locally attached sensors data here
}
