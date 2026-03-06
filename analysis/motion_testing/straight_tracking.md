# Straight Tracking
## 1. Purpose
Straight lines sections were necessary for testing the stability of the motors and controller. This testing verified that the robot
could track a simple track without oscillating or drifting off the line.

## 2. Observed Behaviour
Initially testing showed that the drifted to one direction whilst tracking a straight line with motors commanded to equal PWM signals.
In addition, the robot overcorrected when attempting to return to the line.

This was likely a result of motor imbalance or sensitivity to small tracking errors.

## 3. Solutions
In order to improve straight line tracking performance the following solutions were implemented:
- Verified the correct positioning of sensors.
- Implemented left and right motor trims to compensate for imbalances.
- Implemented a deadband for motors to improve reliability.
- Tuned values to reduce oscillation.

## 4. Outcome
After these solutions were implemented, the robot was able to more accurately follow straight line tracks.
