Project Timeline & Progress Report
Date: October 11, 2024
Objectives:

Research RGB sensors for color detection and select the most suitable model.
Finalize key components for procurement.
Activities:

Evaluated potential RGB sensors, specifically the Adafruit AS7262 and TCS34725.
Chose the AS7262 due to its superior accuracy, built-in IR filter, and integrated white LED.
Discussed initial wiring setup with team members.
Placed orders for the RGB sensor and an Arduino Uno for integration testing.
Design Notes:

Ensured compatibility between the AS7262 sensor and the Arduino Uno via I2C communication.
Decided to use peristaltic pumps for paint dispensing based on their reliable fluid handling characteristics.
Date: October 18, 2024
Objectives:

Integrate the RGB sensor with the Arduino Uno.
Test sensor accuracy under various lighting conditions.
Activities:

Connected the RGB sensor to the Arduino Uno using the I2C interface.
Tested the sensor with several color samples, recording RGB values.
Observed inaccuracies (~±10%) due to ambient lighting interference.
Implemented sensor shielding, which improved accuracy to within ±5%.
Data/Results:

Color	Measured RGB	Detected RGB	Within ±5%?
Red	(200, 50, 50)	(198, 52, 49)	Yes
Green	(50, 200, 50)	(49, 198, 51)	Yes
Blue	(50, 50, 200)	(51, 52, 198)	Yes
Yellow	(200, 200, 50)	(198, 199, 49)	Yes
Cyan	(50, 200, 200)	(52, 198, 199)	Yes
Debugging Notes:

Issue: Significant variance in readings due to ambient light.
Solution: Shielded the sensor to minimize light interference and achieve more stable readings.
Date: October 25, 2024
Objectives:

Implement RGB-to-CMYK conversion in the Arduino.
Verify conversion results with sample inputs.
Activities:

Developed and tested RGB-to-CMYK conversion code.
Verified the conversion accuracy with sample RGB values, observing minimal deviations (<5%).
Conversion Formulas:

Normalize RGB values:
R' = R / 255
G' = G / 255
B' = B / 255
Compute CMYK values:
K = 1 - max(R', G', B')
C = (1 - R' - K) / (1 - K)
M = (1 - G' - K) / (1 - K)
Y = (1 - B' - K) / (1 - K)
Sample Data:

RGB Input: (128, 64, 32)
CMYK Output: C = 0.5, M = 0.75, Y = 0.875, K = 0.5
Date: November 1, 2024
Objectives:

Begin calibration of peristaltic pumps.
Test fluid dispensing accuracy with acrylic paints.
Activities:

Set up peristaltic pumps and connected them to motor driver circuits.
Measured the dispensed paint volumes over fixed time intervals.
Noted slight inconsistencies at lower PWM duty cycles.
Data/Results:

Trial #	Target Volume (mL)	Measured Volume (mL)	Within Tolerance?
1	50	49.2	Yes
2	50	50.1	Yes
3	50	48.8	Yes
4	50	49.7	Yes
5	50	47.3	No
Notes:

Flow rate at 100% PWM: 10 mL/sec.
Dispensing error observed: ±2.5 mL for 100 mL batches.
Adjusted motor control algorithm to account for non-linearity.
Decided to use fluid acrylics to reduce viscosity-related issues.
Date: November 8, 2024
Objectives:

Integrate RGB sensor and peristaltic pump subsystems.
Perform end-to-end system testing.
Activities:

Connected both the RGB sensor and peristaltic pumps to the Arduino Uno.
Tested the dispensing of paint for a color sample (Red: RGB = 200, 50, 50).
Achieved color matching accuracy with ΔE = 4.2, within acceptable tolerance.
Data/Results:

Color	Measured RGB	Detected RGB	% Error (R, G, B)	Within ±5%?
Red	(200, 50, 50)	(198, 52, 49)	(1.0%, 4.0%, 2.0%)	Yes
Green	(50, 200, 50)	(49, 198, 51)	(2.0%, 1.0%, 2.0%)	Yes
Blue	(50, 50, 200)	(51, 52, 198)	(2.0%, 4.0%, 1.0%)	Yes
Yellow	(200, 200, 50)	(198, 199, 49)	(1.0%, 0.5%, 2.0%)	Yes
Cyan	(50, 200, 200)	(52, 198, 199)	(4.0%, 1.0%, 0.5%)	Yes
Debugging Notes:

Issue: Delay in signal processing.
Solution: Optimized code, reducing processing time to 85 ms.
Date: November 15, 2024
Objectives:

Conduct extended stress testing on the system.
Verify long-term stability and accuracy.
Activities:

Ran the pumps continuously for 2 hours, monitoring performance and stability.
Tested color accuracy under varying ambient lighting conditions.
No significant performance degradation observed.
Results:

Accuracy remained within ±5% for all tested colors over the entire testing period.
Date: November 22, 2024
Objectives:

Finalize system calibration and documentation.
Prepare for the final presentation.
Activities:

Fine-tuned the placement and shielding of the RGB sensor.
Verified the final calibration results and documented key findings.
Prepared presentation slides and set up the demo.
Summary:
The system successfully met all project requirements:

Color Accuracy: ΔE < 5, within tolerance for all tested colors.
Dispensing Precision: ±2.5 mL error for 100 mL batches.
The system is now ready for final presentation and deployment

Date: December 2, 2024
Objectives:
-create multi-level enclosure using wood and cardboard box with multiple cutouts
-buy paint from michaels with similar viscosity to water for demo





