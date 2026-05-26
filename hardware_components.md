# Hardware Components

This file documents the main hardware components used in the embedded sensor control system.

## Main Controller

### Arduino Mega

The Arduino Mega is used as the main controller for motor control, sensor reading and movement logic.

Main responsibilities:

- Read sensor data
- Control motors
- Process compass heading
- Send debug information to Serial Monitor
- Execute movement logic

## Wireless Module

### ESP8266

The ESP8266 is used for web-assisted control and communication.

Possible responsibilities:

- Start or stop robot actions
- Provide a simple web interface
- Send control commands to the Arduino
- Support calibration or debug commands

## Compass Sensor

### CMPS14 Compass

The compass sensor is used to read the robot's current heading.

Purpose:

- Detect current direction
- Support compass-based turning
- Reduce dependency on timer-based rotation
- Improve movement accuracy

Example use:

The robot can turn toward 90 degrees by comparing the current heading with the target heading.

## Distance Sensor

### LIDARLite Sensor

The distance sensor can be used to measure distance to obstacles or walls.

Possible use cases:

- Obstacle detection
- Distance-based navigation
- Wall approach logic
- Movement verification

## Color Sensor

### TCS34725 Color Sensor

The color sensor can be used to detect surface or marker colors.

Possible use cases:

- Detecting colored zones
- Identifying field markers
- Supporting navigation decisions

## Motors

The robot uses two DC motors controlled through motor direction and PWM pins.

Motor control includes:

- Forward movement
- Backward movement
- Left turn
- Right turn
- Stop

## Encoders

Wheel encoders can be used to measure movement distance and wheel rotation.

Possible use cases:

- Distance tracking
- Movement calibration
- Detecting wheel slip
- Improving movement accuracy

## LCD Display

The LCD display can be used to show useful system information.

Possible displayed values:

- Current heading
- Target heading
- Sensor status
- Robot mode
- Error messages

## Serial Monitor

The Serial Monitor is used during development and debugging.

Important debug values:

- Compass heading
- Target heading
- Heading error
- Motor command
- Sensor readings
- System state
