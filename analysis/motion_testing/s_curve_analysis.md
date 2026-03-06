# S-Curve Analysis
## 1. Purpose
The S-curve section was critical for testing how quickly the robot can react to successive changes in curvature.

This testing focused controller responsiveness and damping.

## 2. Observed Behaviour
In initial testing the robot often performed well in the first curve but understeered the second curve. 

## 3. Solution
The following solutions were implemented to improve performance:
- Increased derivative responsiveness
- Reducing noise through derivative filtering
- Refining dynamic speed reduction tuning

## 4. Outcome
S-curves were navigated much more efficiently without understeering on curves.
