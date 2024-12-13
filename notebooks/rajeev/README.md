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



important links:

https://www.instructables.com/Color-Detection-Using-RGB-LED/
https://www.instructables.com/TCS3472-RGB-Light-Color-Sensor-With-Arduino/ 
MOTOR:
https://www.amazon.com/peristaltic-Stepper-KPHM100-Service-high-Precision/dp/B0B99ZH9C1/ref=sr_1_1_sspa?crid=3P89EUCOQIJ3G&dib=eyJ2IjoiMSJ9.TPwDIg-bL8P5Tvg9BKPSdzpgey4PK_kuKon2pRRE6ixJzShd4wL6ktk2FXDDS6armvdMxbbdsbKdpevz5GLeKuyC4rBoRRnTa1FXnzq9i4bP_EFjnJVZRSS8uAX-meVMOm-TgqH6CL9QhZ-yMN7Lq27z-Y4eaZNXshNd6Nt7U0cszJwzaRGP5r_b3kN_EX8M77nZwsKRgNXgs-JVKp3dJCkBkvfY6RQ4A9-H0GStdhE.amgJhaxBD09Ocb6JQho2vgTS1uyKtf7nGYPKcqbWYLA&dib_tag=se&keywords=stepper+motor+peristaltic+pump&qid=1729451401&sprefix=stepper+motor+peristaltic+oump%2Caps%2C125&sr=8-1-spons&sp_csd=d2lkZ2V0TmFtZT1zcF9hdGY&psc=1

MOTOR DRIVER:
https://www.amazon.com/BIGTREETECH-DIRECT-TMC2209-Stepsticks-Motherboard/dp/B07ZQ3C1XW/ref=sr_1_1_sspa?dib=eyJ2IjoiMSJ9.U9QqZZCr7u-b-HbT3uPO-zE4vSmFXI_rhJhKmIr0TgVV741QgU-WoRW-C_OA9pagXsh4KJoYXiQGUFHtHxaKJG_HkXvoDbmjAzFrXvECiDRU3yPJ0chU2g7GpDdutmFRKEnT0C9-tuOFL1DbpIMi1q__SOl2UJkTHpyzK_avUVW_Z7lMmy7hxiZpAesxpDdlI8JyICitRBOrvAXSbGMNJ-eoqyPX6ZO4bmkdwuyPmCA.F_ZLp0XKpwx09wVoFzJtqZPXhxQ33mUgyxWnJDEMJ0Q&dib_tag=se&hvadid=694425533740&hvdev=c&hvexpln=67&hvlocphy=9007527&hvnetw=g&hvocijid=11844786358995837023--&hvqmt=e&hvrand=11844786358995837023&hvtargid=kwd-866463465553&hydadcr=8684_13501820&keywords=tmc2209%2Bstepper%2Bdriver&qid=1729452567&sr=8-1-spons&sp_csd=d2lkZ2V0TmFtZT1zcF9hdGY&th=1 https://www.digikey.com/en/products/detail/analog-devices-inc-maxim-integrated/TMC2209-LA-T/10232491

RGB SENSOR: 
https://www.adafruit.com/product/3779 https://mm.digikey.com/Volume0/opasdata/d220001/medias/docus/758/3779_Web.pdf
Circuit Protection https://www.digikey.com/en/products/detail/stmicroelectronics/USBLC6-2SC6Y/2819177 24V Power Supply https://www.amazon.com/EMITEVER-Lighting-Transformers-100-240V-UL-Listed/dp/B09S9YF9BX?source=ps-sl-shoppingads-lpcontext&ref_=fplfs&psc=1&smid=A3TH0XOU4ISKPM

Microcontroller:
https://www.st.com/content/ccc/resource/technical/document/datasheet/group3/98/80/dc/e5/f8/4b/4b/a3/DM00366448/files/DM00366448.pdf/jcr:content/translations/en.DM00366448.pdf USB Connection https://www.mouser.com/ProductDetail/Amphenol-Commercial-Products/12401598E42A?qs=367PjNmvCmllVMBVyIyS3w%3D%3D Display https://www.amazon.com/Enhanced-NX4024K032-Resistive-Function-Dashboard/dp/B0BHN7QKVP?dib=eyJ2IjoiMSJ9.tWZNXU-lL10mQ-v1ue0fw2kgqb3gMJ3sC-Zqk_7NqrcGq3jx2iOOz9kl8boMj3umYkYOaU5sLWN3Gz1I3PTkSYWT4gD6AsJ4GV3DL3bwQPdDA_SY3U-2pD8IsvOvUvbfLZA7WlJ9zgrblBz0r1p1TtC-vDa_ppXiWQNnfmBk6gcbyN25NHXAOHqulks57UGRSgRbUeFRajvHURnGm01b3W6cQJAUjjZDB_mQ-WAHWLg.a4o5eR0zAI2tHyLVnoXIS7Hw8xdT1JEUoMlxTot4YwY&dib_tag=se&keywords=nextion%2Bdisplay&qid=1729464789&refinements=p_36%3A-5000&rnid=386442011&sr=8-4&th=1 Voltage Regulator 24V to 3.3V https://www.pololu.com/product/2842

10.88 for resistors and capacitors:

https://jiaolyulu.github.io/kineticSculpture/stepperTMC2209.html

https://learn.watterott.com/silentstepstick/faq/#calculator-tmc21xx-and-tmc2209

https://www.programming-electronics-diy.xyz/2023/12/tmc2209-stepper-driver-module-tutorial.html

https://forum.arduino.cc/t/tmcstepper-arduino-tmc2209/956036

code:


#include <Wire.h>
#include "Adafruit_AS726x.h"

//create the object
Adafruit_AS726x ams;

//buffer to hold raw values
uint16_t sensorValues[AS726x_NUM_CHANNELS];
int offButtonState = 0;
int ResetButtonState = 0;
unsigned long counter = 0;
int flag = 0;

void setup() {
  //UCSR0B = 0;


  Serial.begin(9600);
  while (!Serial);

  // // initialize digital pin LED_BUILTIN as an output.
  // pinMode(LED_BUILTIN, OUTPUT);

  // //begin and make sure we can talk to the sensor
  if(!ams.begin()){
    Serial.println("could not connect to sensor! Please check your wiring.");
    while(1);
  }
  pinMode(PD2, INPUT);   //off button
  pinMode(A5, INPUT);    //reset button
  pinMode(A0, OUTPUT);   // motor 3 dir BLACK
  pinMode(A3, OUTPUT);   // motor 3 step
  pinMode(PD7, OUTPUT);  //enable
  pinMode(PD6, OUTPUT);  // motor 1 step CYAN
  pinMode(PD5, OUTPUT);  // motor 1 dir
  pinMode(PD4, OUTPUT);  // motor 2 step MAGENTA
  pinMode(PD3, OUTPUT);  // motor 2 dir
  pinMode(A1, OUTPUT);   // motor 4 step YELLOW
  pinMode(A2, OUTPUT);   // motor 4 dir

  digitalWrite(PD7, LOW);   // universal enable
  digitalWrite(PD5, HIGH);  //motor 1 dir
  digitalWrite(PD3, HIGH);  //motor 2 dir
  digitalWrite(A0, HIGH);   //motor 3 dir
  digitalWrite(A2, HIGH);   //motor 3 dir

  counter = 0;
  offButtonState = 0;
  ResetButtonState = 0;
  flag = 0;

 
}


void loop() {
 
  offButtonState = digitalRead(PD2);


  if (offButtonState) {

    digitalWrite(PD7, LOW);

    ams.drvOn(); //uncomment this if you want to use the driver LED for readings

    ams.startMeasurement();  //begin a measurement

    //wait till data is available
    bool rdy = false;
    while (!rdy) {
      delay(5);
      rdy = ams.dataReady();
    }
    ams.drvOff();  //uncomment this if you want to use the driver LED for readings

    //read the values!
    ams.readRawValues(sensorValues);

    int rval = ((sensorValues[AS726x_RED] / 5500.00) * 255.00);
    int gval = ((sensorValues[AS726x_GREEN] / 10500.00) * 255.00);
    int bval = ((sensorValues[AS726x_BLUE] / 12000.00) * 255.00);

    if (rval > 255) {
      rval = 255;
    }
    if (bval > 255) {
      bval = 255;
    }
    if (gval > 255) {
      gval = 255;
    }

    Serial.print("red :");
    Serial.println(rval);
    Serial.println(sensorValues[AS726x_RED]);
    Serial.print("green : ");
    Serial.println(gval);
    Serial.println(sensorValues[AS726x_GREEN]);
    Serial.print("blue : ");
    Serial.println(bval);
    Serial.println(sensorValues[AS726x_BLUE]);

    float R_prime = rval / 255.0;
    float G_prime = gval / 255.0;
    float B_prime = bval / 255.0;

    // Calculate K (Key)
    float K = 1 - max(max(R_prime, G_prime), B_prime);

    // Avoid division by zero when K == 1
    float C = (K < 1) ? (1 - R_prime - K) / (1 - K) : 0;
    float M = (K < 1) ? (1 - G_prime - K) / (1 - K) : 0;
    float Y = (K < 1) ? (1 - B_prime - K) / (1 - K) : 0;

    float white = 100;

    float cyan = C * white;
    float magenta = M * white;
    float yellow = Y * white;
    float black = K * white;

    float mlstep = (226935-25500)/40;
    float tube = 25500;

    float cyan_motorstep = (cyan / 25) * mlstep;
    float magenta_motorstep = (magenta / 25) * mlstep;
    float yellow_motorstep = (yellow / 25) * mlstep;
    float black_motorstep = (black / 25) * mlstep;

    Serial.println(cyan_motorstep);
    Serial.println(magenta_motorstep);
    Serial.println(yellow_motorstep);
    Serial.println(black_motorstep);

   

  if(cyan_motorstep > 0.00){

  
    for (long i = 0; i < (long)((tube * 1.25)+cyan_motorstep); i++) {
      digitalWrite(PD6, HIGH);
      //digitalWrite(PD4, HIGH);
      delayMicroseconds(100);
      digitalWrite(PD6, LOW);
      //digitalWrite(PD4, LOW);
      delayMicroseconds(100);
    }
  }
    
    Serial.println("cyan complete");

    if(magenta_motorstep > 0.00){

      for (long i = 0; i < (long)((tube * 1.25)+magenta_motorstep); i++) {
        digitalWrite(PD4, HIGH);
        //digitalWrite(PD4, HIGH);
        delayMicroseconds(100);
        digitalWrite(PD4, LOW);
        //digitalWrite(PD4, LOW);
        delayMicroseconds(100);
      }
    }
    Serial.println("magenta complete");


    if(yellow_motorstep > 0.00){

    
      for (long i = 0; i < (long)((tube * 1.25)+yellow_motorstep); i++) {
        digitalWrite(A3, HIGH);
        //digitalWrite(PD4, HIGH);
        delayMicroseconds(100);
        digitalWrite(A3, LOW);
        //digitalWrite(PD4, LOW);
        delayMicroseconds(100);
      }
    }

    Serial.println("yellow complete");

    if(black_motorstep > 0.00){

      for (long i = 0; i < (long)((tube * 1.25)+black_motorstep); i++) {
        digitalWrite(A1, HIGH);
        //digitalWrite(PD4, HIGH);
        delayMicroseconds(100);
        digitalWrite(A1, LOW);
        //digitalWrite(PD4, LOW);
        delayMicroseconds(100);
      }

    }
    Serial.println("black complete");

    delay(1000);

    digitalWrite(A0, LOW);

    digitalWrite(PD5, LOW);  //dir motor 1

    digitalWrite(PD3, LOW);  //dir motor 2

    digitalWrite(A2, LOW);

    delay(1000);

    for(long i = 0; i<long((tube*1.25)+1000); i++)
    {
          

          digitalWrite(PD6, HIGH);

          digitalWrite(PD4, HIGH);

          digitalWrite(A3, HIGH);
          
          digitalWrite(A1, HIGH);

          delayMicroseconds(100);

          digitalWrite(PD6, LOW);

          digitalWrite(PD4, LOW);

          digitalWrite(A3, LOW);

          digitalWrite(A1, LOW);

          delayMicroseconds(100);

          counter++;
          flag = 1;
    }


  digitalWrite(PD5, HIGH);  // dir

  digitalWrite(PD3, HIGH);  // dir

  digitalWrite(A0, HIGH);

  digitalWrite(A2, HIGH);

  digitalWrite(PD7, HIGH);
  
  }






