# Smart Ultrasonic Distance Monitoring using ESP8266 and ThingSpeak

A smart IoT project that measures the distance using an **ultrasonic sensor (HC-SR04)** and sends the data to **ThingSpeak Cloud** via **ESP8266 Wi-Fi module**.  
The distance readings are uploaded live and visualized as a real-time graph on your ThingSpeak dashboard.

## Components Required

| Component | Quantity | Description |
|------------|-----------|-------------|
| ESP8266 (NodeMCU) | 1 | Wi-Fi enabled microcontroller board |
| HC-SR04 Ultrasonic Sensor | 1 | Measures distance using sound waves |
| Jumper Wires | As needed | For connections |
| Breadboard | 1 | For circuit setup |
| Micro USB Cable | 1 | For uploading code & powering NodeMCU |

## Circuit Connections

| Ultrasonic Sensor | ESP8266 (NodeMCU) |
|--------------------|------------------|
| VCC | 3.3V |
| GND | GND |
| TRIG | D5 |
| ECHO | D6 |

## Working Principle

- The **ultrasonic sensor** sends out a short sound pulse.  
- When the sound hits an object, it reflects back and is detected by the **ECHO pin**.  
- The **ESP8266** calculates the distance based on the time it takes for the echo to return.  
- This measured distance is then **sent to the ThingSpeak cloud**, where it’s displayed as a live graph.

## ThingSpeak Setup

1. Create an account on [ThingSpeak](https://thingspeak.com/).  
2. Create a **New Channel** and enable **Field 1** (name it "Distance").  
3. Copy your **Write API Key** and **Channel Number**.  
4. Write the Arduino code in Arduino IDE
5. Save and upload the code to your NodeMCU.
