# Debugging Log

This document outlines a number of issues encountered during the testing process and the solutions implemented.

## 1. Sensor Ordering Issue

### 1.1 Issue
The robot initially drifted away from the lineand corrected in the wrong direction.

### 1.2 Testing
Through testing of the individual sensor outputs it was revealed that they were ordered incorrectly. Since the position weighting is reliant on correct positioning this caused the issue.

### 1.3 Solution
The sensor pin order was rearranged in software so that the array matched the left to right order expected.

## 2. Line Loss Behaviour

### 2.1 Issue
When the robot lost the line, it occasionally spun continuously in one direction instead of recovering.

### 2.2 Testing
This behaviour occurred when the recovery logic repeatedly searched in the same direction regardless of where the line was last detected.

### 2.3 Solution
The code implemented a function which remembered the last position of the line to more accurately regain tracking in this case.

## 3. S-Curve Instability

### 3.1 Issue
The robot struggled to transition smoothly between opposite turns in S-curve sections.

### 3.2 Testing
The controller response was analysed and it was observed that the robot reacted too slowly to successive changes in line position.

### 3.3 Solution
Derivative filtering was implemented to prevent overcorrection and reduce noise.

## 4. U-Turn Understeer

### 4.1 Issue
The robot was unable to perform tight radius U-turns.

### 4.2 Testing
The maximum turn allowable was not high enough to perform these turns, but increasing this value resulted in losing the line after the turn was completed.

### 4.3 Solution
A hard turn mode was implemented that activates at during these tighter radius turns.

## 5. Summary

The debugging process revealed that reliable line following depended on both hardware validation and controller tuning.

Key improvements included:

- Correcting sensor ordering
- Compensating for drivetrain imbalance
- Improving lost line recovery
- Implementing a hard turn mode

These changes significantly improved the robot's ability to navigate straights, S-curves, and tight U-turns.
