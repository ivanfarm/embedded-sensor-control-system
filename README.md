# Embedded Sensor Control System

An embedded systems project focused on sensor data handling, motor control, serial debugging and compass-based turning logic using Arduino and ESP8266.

## Project Overview

This project demonstrates the control logic of a small robotic vehicle built around an Arduino-based system. The main goal is to create reliable movement behavior using sensor feedback instead of fixed timing.

The project focuses on:

- Compass-based turning
- Motor control logic
- Sensor data processing
- Serial debugging
- Embedded system structure
- Web-assisted control through ESP8266

This repository documents the core logic, hardware components and debugging approach used in the project.

## Main Idea

Instead of turning the robot for a fixed number of milliseconds, the system uses compass heading data to rotate toward a target angle.

This is important because timer-based turning can become unreliable when:

- Battery voltage changes
- The robot moves on different surfaces
- Wheels slip
- The robot meets resistance or obstacles
- Motors do not behave identically

Compass-based turning makes the logic more adaptive because the robot checks its actual direction while turning.

## Technologies and Components

- Arduino Mega
- ESP8266
- CMPS14 compass sensor
- LIDARLite sensor
- TCS34725 color sensor
- DC motors
- Motor driver
- Wheel encoders
- LCD display
- Serial Monitor
- Arduino C/C++
- Basic web control through ESP8266

## Project Structure

embedded-sensor-control-system/

- README.md
- compass_turning_logic.ino
- hardware_components.md
- robot_control_overview.md
- sensor_debug_output.txt
- LICENSE
- .gitignore

## Key Features

- Reads compass heading
- Calculates shortest turn direction
- Rotates toward target heading
- Stops when heading error is within tolerance
- Prints debug data to Serial Monitor
- Separates movement logic from sensor reading
- Documents hardware and control flow

## Why Compass-Based Turning

A simple timed turn may work during testing, but it does not guarantee that the robot actually reaches the required angle.

Compass-based turning is more reliable because the robot continuously checks its current heading and compares it with the target heading.

Example:

If the robot needs to turn to 90 degrees, it does not simply rotate for one second. Instead, it keeps reading the compass until the current heading is close enough to 90 degrees.

## Example Control Logic

The robot follows this simplified logic:

1. Read current compass heading.
2. Set target heading.
3. Calculate heading error.
4. Choose the shortest rotation direction.
5. Rotate left or right.
6. Keep checking compass data.
7. Stop motors when the target heading is reached.

## Debugging Approach

Serial Monitor is used to check important values during movement:

- Current heading
- Target heading
- Heading error
- Turn direction
- Motor state
- Sensor readings

This helps verify whether the robot is turning correctly and whether the sensor data is stable.

## What I Practiced

- Embedded C/C++ programming
- Working with sensors
- Motor control logic
- Compass-based navigation
- Serial debugging
- Breaking a system into smaller functions
- Thinking about real-world hardware limitations
- Documenting an embedded systems project

## Possible Improvements

- Add encoder-based distance tracking
- Add obstacle avoidance
- Add better web interface for calibration
- Add PID control for smoother turning
- Save calibration values in EEPROM
- Add structured logging
- Improve sensor fusion between compass, encoders and distance sensors
