# Project Digibod Augment Controller
**The processor for an individual Digibod augment**

## About
The code in this repository is for a Digibod Augment Controller. Each Augment
Controller is responsible for handling sensor inputs and converting them into a
usable form for the Digibod Augment Hub.

Parts of this project were inspired by Google Creative Lab's ["Teachable Machine"](https://github.com/googlecreativelab/teachable-machine)
AI experiment.

## Development

### Hardware
Each Digibod agument controller uses an Arduino Uno.

TODO: Complete hardware description and diagrams

### Software

#### Libraries
This project was made using Visual Studio Code and the Arduino plugin, but you
can still use the Arduino IDE.

Download the following libraries in zip form, and add them to the project (in
the Arduino IDE, go to Sketch > Include Library > Include .ZIP Library):
 - [ArduinoJson](https://arduinojson.org/)


#### Uploading
Assuming the build directions were followed, there are special instructions for
uploading code to the Arduino.

Before you upload the sketch to the Arduino, unplug the Digital 0 (D0) and
Digital 1 (D1) pins. Otherwise, the upload will (probably) fail. After the
upload, plug them back in.

#### Interaction with Augment Hub

The Augment Controller constantly polls sensor values and broadcasts them to the
connected Augment Hub, but it's the responsibility of the Hub to determine what
is done with those sensor snapshots. 

TL;DR: The Augment Controller spits out sensor snapshots that the Augment Hub interprets.