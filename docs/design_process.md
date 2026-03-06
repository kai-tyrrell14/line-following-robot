# Design Process
## 1. Project Objective
The main objective of this project was to design and assemble a small autonomous robot capable of following black line track on a contrasting surface through a series of different curves through onboard sensing and embedded motor control. To be successful, the robot needed to detect the position of the line relative to its centre and make the necessary steering adjustments to maintain alignment with the track.

## 2. System Design
The initial design of the robot began with selecting simple components necesary to complete the objective. A differential-drive
chassis robot was chosen with the need for a battery to supply power, a microcontroller and motor driver for logic, sensors to track the line and two DC motors capable of driving the chassis. Through research kit was found online including the chassis, wheels and two motors and the following components were chosen separately:
- Arduino Uno microcontroller
- TB6612FNG motor driver
- 7-channel IR sensor array

## 3. Sensor Integration
The sensor array was mounted underneath the chassis, low enough to detect the contrast between the track and the background, and forward enough to ensure the robot had enough time to react to the track's position. During intial testing the calibration values for the sensors were calculated before the sensor order was verified.

## 4. Controller Development

