# Debugging Log

This log documents key issues encountered during development of the line-following robot and the steps taken to resolve them.

The goal of this record is to capture the engineering reasoning behind hardware adjustments and control algorithm changes.

---

## 1. Sensor Ordering Issue

### Problem
The robot initially steered in the wrong direction when the line moved away from the centre of the sensor array.

### Investigation
Serial output of individual sensor values revealed that the software ordering of the sensors did not match their physical layout.

Because the line position estimate depends on weighted sensor positions, incorrect ordering caused the controller to calculate steering corrections in the wrong direction.

### Resolution
The sensor pin order was rearranged in software so that the array matched the physical left-to-right layout of the sensor board.

---

## 2. Straight-Line Drift

### Problem
When driving forward with equal motor commands, the robot drifted slightly to one side on straight sections of the track.

### Investigation
A motor drift test was implemented to determine whether the behaviour was caused by control logic or mechanical imbalance.

The test confirmed that the drivetrain produced slightly different output from the left and right motors.

### Resolution
Motor trim values were introduced and deadband compensation was implemented to improve low-speed motor response.

---

## 3. Line Loss Behaviour

### Problem
When the robot lost the line, it occasionally spun continuously in one direction instead of recovering.

### Investigation
This behaviour occurred when the recovery logic repeatedly searched in the same direction regardless of where the line was last detected.

### Resolution
A directional search algorithm was implemented that initially searches in the last known line direction and alternates direction if the line is not reacquired.

---

## 4. S-Curve Instability

### Problem
The robot struggled to transition smoothly between opposite turns in S-curve sections of the track.

### Investigation
The controller response was analysed and it was observed that the robot reacted too slowly to rapid changes in line position.

### Resolution
Derivative filtering and derivative gain adjustments were introduced to improve responsiveness to changing error signals while limiting noise sensitivity.

---

## 5. U-Turn Understeer

### Problem
The robot was unable to negotiate tight-radius U-turns using standard PD control alone.

### Investigation
The maximum steering authority available from differential drive was insufficient when the base speed remained high.

### Resolution
A hard-turn mode was implemented that activates at large tracking error values. This mode reduces base speed and increases differential wheel commands to produce tighter turning behaviour.

---

## 6. Corner Exit Overshoot

### Problem
After leaving tight corners, the robot sometimes turned sharply in the opposite direction before stabilising.

### Investigation
This behaviour was traced to residual derivative response and aggressive steering correction immediately after exiting hard-turn mode.

### Resolution
A short cooldown period was introduced after hard-turn mode exits, along with derivative reset logic to prevent rebound steering behaviour.

---

## Summary

The debugging process revealed that reliable line following depended on both hardware validation and controller tuning.

Key improvements included:

- correcting sensor ordering
- compensating for drivetrain imbalance
- implementing robust lost-line recovery
- improving controller responsiveness
- introducing a dedicated hard-turn strategy

These changes significantly improved the robot's ability to navigate straights, S-curves, and tight U-turns.
