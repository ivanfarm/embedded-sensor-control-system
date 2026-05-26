# Robot Control Overview

## Purpose

This document explains the high-level control logic of the embedded sensor control system.

The goal of the project is to control a small robotic vehicle using sensor feedback instead of relying only on fixed timing.

## Control Philosophy

A real robot does not always behave the same way in every situation.

Movement can be affected by:

- Battery level
- Surface friction
- Motor differences
- Wheel slip
- Obstacles
- Sensor noise

Because of this, the control system should use feedback from sensors whenever possible.

## Main Control Loop

The robot control process can be described as:

1. Read sensor data.
2. Understand current robot state.
3. Compare current state with target state.
4. Choose motor action.
5. Execute action.
6. Print debug information.
7. Repeat until the target is reached.

## Compass-Based Turning

Compass-based turning is one of the key parts of the project.

Instead of using this logic:

Turn right for 900 milliseconds.

The system uses this logic:

Turn right until the compass heading is close to the target heading.

This makes the robot more reliable because it checks the actual result of the movement.

## Heading Error

The heading error is the difference between the target heading and the current heading.

Example:

Current heading: 70 degrees  
Target heading: 90 degrees  
Heading error: 20 degrees

The robot continues turning until the error becomes small enough.

## Shortest Turn Direction

The system should choose the shortest direction to the target angle.

Example:

Current heading: 350 degrees  
Target heading: 10 degrees  

The shortest turn is not 340 degrees left.  
The shortest turn is 20 degrees right.

This is why the heading error must be normalized between -180 and +180 degrees.

## Motor Commands

The basic motor commands are:

- Stop motors
- Turn left
- Turn right
- Move forward
- Move backward

For turning:

- Left motor and right motor rotate in opposite directions
- PWM controls turning speed
- Compass feedback decides when to stop

## Debugging Strategy

During development, every important value should be printed to Serial Monitor.

Useful debug output includes:

- Current heading
- Target heading
- Heading error
- Turn direction
- Motor speed
- Sensor status

This helps detect problems such as:

- Compass readings are unstable
- Robot turns in the wrong direction
- Target heading is never reached
- Motors are wired incorrectly
- Tolerance is too strict
- Turning speed is too high

## Reliability Notes

Compass-based turning is better than timer-based turning, but it still requires careful testing.

Possible issues:

- Magnetic interference
- Sensor calibration errors
- Delay in sensor reading
- Motor overshoot
- Mechanical imbalance

To improve reliability, the system can later use:

- Lower speed near target angle
- PID control
- Encoder feedback
- Sensor calibration
- EEPROM-stored settings
