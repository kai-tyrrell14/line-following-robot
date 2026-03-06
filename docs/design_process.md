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
Once reliable sensor readings were obtained, a control algorithm was implemented to convert sensor data into steering commands.

A weighted position estimation method was used to determine the location of the line relative to the robot's centre. This position estimate was used to calculate a tracking error which was passed to a proportional-derivative (PD) controller.

The controller generated steering corrections by adjusting the relative speeds of the left and right motors.

---

## 5. System Testing and Iteration

After implementing the initial controller, the robot was tested on a simple line track.

Testing revealed several issues including:

- drivetrain drift during straight motion
- unstable response during rapid direction changes
- insufficient turning authority in tight corners
- inconsistent behaviour when the line was lost

These observations guided further development and controller refinement.

---

## 6. Control Improvements

Several improvements were introduced to address the issues identified during testing.

These included:

- motor trim adjustments to compensate for drivetrain imbalance
- deadband compensation for consistent motor response
- derivative filtering to stabilise control behaviour
- hard-turn logic for tight-radius corners
- improved line-loss recovery behaviour

These changes significantly improved the stability and reliability of the robot.

---

## 7. Final System

After iterative testing and refinement, the robot was able to reliably follow a line across a test track containing straights, S-curves, and tight turns.

The final system integrates sensor calibration, closed-loop control, and specialised turning logic to maintain stable tracking under a range of conditions.

This iterative development process allowed the robot’s behaviour to be progressively improved through testing, analysis, and targeted control adjustments.
