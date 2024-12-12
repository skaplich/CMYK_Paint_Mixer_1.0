Date: October 11, 2024

Objectives:

Research RGB sensors and select the most suitable model for color detection.

Finalize key components for procurement.

Record of Activities:

Evaluated RGB sensors (Adafruit AS7262 and TCS34725).

Selected AS7262 due to high accuracy, built-in IR filter, and white LED.

Discussed with team members about the initial wiring setup.

Ordered RGB sensor and Arduino Uno for integration testing.

Design Notes:

Ensured compatibility between RGB sensor and Arduino Uno (I2C communication).

Decision made to use peristaltic pumps for paint dispensing based on fluid handling capabilities.



Date: October 18, 2024

Objectives:

Begin integrating the RGB sensor with Arduino Uno.

Test sensor accuracy under different lighting conditions.

Record of Activities:

Connected RGB sensor to Arduino Uno using I2C interface.

Tested sensor with various color samples and recorded RGB values.

Observed ambient lighting causing inaccuracies (~±10%).

Shielded the sensor to minimize light interference, improving accuracy to within ±5%.

Data/Results:

Red: Measured (200, 50, 50), Detected (198, 52, 49).

Green: Measured (50, 200, 50), Detected (49, 198, 51).

RGB Color Sensor Accuracy
Color
Measured RGB (Reference)
Detected RGB (Sensor)
Within ±5%?
Red
(200, 50, 50)
(198, 52, 49)
Yes
Green
(50, 200, 50)
(49, 198, 51)
Yes
Blue
(50, 50, 200)
(51, 52, 198)
Yes
Yellow
(200, 200, 50)
(198, 199, 49)
Yes
Cyan
(50, 200, 200)
(52, 198, 199)
Yes

Debugging Notes:

Issue: High variance in readings due to ambient light.


Date: October 25, 2024

Objectives:

Implement RGB-to-CMYK conversion in Arduino.

Verify conversion results with sample inputs.

Record of Activities:

Wrote code for RGB-to-CMYK conversion based on defined formulas.

Tested code using sample RGB values and verified outputs.

Observed deviations in CMYK values (<5%).

Equations:

Conversion formulas:

R' = R/255
G' = G/255
B' = B/255
K = 1-max(R', G', B')
C = (1-R'-K) / (1-K)
M = (1-G'-K) / (1-K)
Y = (1-B'-K) / (1-K)

Data/Results:

Example RGB Input: (128, 64, 32)

CMYK Output: C=0.5, M=0.75, Y=0.875, K=0.5



Date: November 1, 2024

Objectives:

Begin calibration of peristaltic pumps.

Test dispensing accuracy for fluid acrylics.

Record of Activities:

Set up peristaltic pumps with motor driver circuits.

Measured paint volumes dispensed over fixed durations.

Noted inconsistencies at low PWM duty cycles.

Data/Results:

Flow rate: 10 mL/sec at 100% PWM.

Dispensing error: ±2.5 mL for 100 mL batches.
Peristaltic Pump Accuracy
Trial
Target Volume (mL)
Measured Volume (mL)
Within Requirement?
1
50
49.2
Yes
2
50
50.1
Yes
3
50
48.8
Yes
4
50
49.7
Yes
5
50
47.3
No



Design Adjustments:

Adjusted motor control algorithm to account for non-linearity.

Decided to switch to fluid acrylics to mitigate viscosity issues.



Date: November 8, 2024

Objectives:

Integrate sensor and pump subsystems.

Perform end-to-end testing.

Record of Activities:

Connected RGB sensor and pumps to Arduino Uno.

Scanned sample colors and verified corresponding paint proportions dispensed.

Conducted full system test for Red (RGB: 200, 50, 50).

Results:

Color Match Accuracy: ΔE = 4.2 (within tolerance).
RGB Color Sensor Accuracy
Color
Measured RGB (Reference)
Detected RGB (Sensor)
% Error (R, G, B)
Within ±5%?
Red
(200, 50, 50)
(198, 52, 49)
(1.0%, 4.0%, 2.0%)
Yes
Green
(50, 200, 50)
(49, 198, 51)
(2.0%, 1.0%, 2.0%)
Yes
Blue
(50, 50, 200)
(51, 52, 198)
(2.0%, 4.0%, 1.0%)
Yes
Yellow
(200, 200, 50)
(198, 199, 49)
(1.0%, 0.5%, 2.0%)
Yes
Cyan
(50, 200, 200)
(52, 198, 199)
(4.0%, 1.0%, 0.5%)
Yes



Debugging Notes:

Issue: Delay in signal processing.

Resolution: Optimized code to reduce processing time to 85 ms.



Date: November 15, 2024

Objectives:

Conduct extended stress testing on the system.

Verify long-term stability and accuracy.

Record of Activities:

Ran pumps continuously for 2 hours; monitored performance.

Tested color accuracy under varying ambient lighting conditions.

Results:

No significant degradation in performance.

Accuracy remained within ±5% for all tested colors.



Date: November 22, 2024

Objectives:

Finalize system calibration and documentation.

Prepare for final presentation.

Record of Activities:

Fine-tuned sensor placement and shielding.

Verified calibration results and documented key findings.

Prepared presentation slides and demo setup.

Summary:

The system achieved all high-level requirements, including color accuracy (ΔE < 5) and dispensing precision (±2.5 mL).


