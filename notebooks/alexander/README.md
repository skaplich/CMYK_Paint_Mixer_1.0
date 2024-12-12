# **ECE 445 Lab Notebook**

## Entry Format:
Date
Brief statement of objectives for that session
Record of what was done


________________________________________________________________________________________________
1. 8/29/24
2. Preliminary Research for the Project + First Web Board Post
  

Today I'm going to research some ideas for the project and come up with a basic draft for the web board post.
Explaining how to use an RGB sensor : https://www.instructables.com/Color-Detection-Using-RGB-LED/
- Color detection using an rgb sensor
- similarly using an arduino breakout board: https://www.instructables.com/TCS3472-RGB-Light-Color-Sensor-With-Arduino/
RGB (Red, Green, Blue):

Additive Color Model: Combines red, green, and blue light to create colors.
Used for Screens: Displays, monitors, and digital devices.
Color Mixing: Adding colors makes them brighter (e.g., all combined = white).
CMYK (Cyan, Magenta, Yellow, Key/Black):

Subtractive Color Model: Uses ink or pigment to subtract light.
Used for Printing: Paper and physical media.
Color Mixing: Combining colors makes them darker (e.g., all combined = black or muddy brown).

Here is my Web post that I'm going to push today: 

Team :
Lucky Konatham (lrk4)
Alexander Kaplich (kaplich2)
Rajeev Bommana (bommana2)
Problem :
Whenever a painter starts a new project they always begin by mixing their desired colors on their palette using some combination of red, blue yellow and white. However, the painter will inevitably run out of paint, and then will need to mix the exact color that they had before. Speaking from experience this part of the process is very frustrating and time consuming, especially for artists that are bad at mixing colors. Rather than wasting time learning color theory, or buying the color you were using straight from the tube, we will save time and money by designing a machine that can determine the pigments required to mix any color using RGB sensors, and it will also mix it for you using a combination of primary colors so that you don't have to.

Solution :
The idea is pretty simple, the user of the device will "scan" the desired color by using a color sensor that detects the RGB values of a surface using red, green, blue and 'clear' photodiodes. The device will send the RGB values of the color to the onboard mcu which will do some simple calculations to convert the RGB value of the color to CMYK format using conversion formulas. This is the same principle behind color printers which create color images by mixing cyan, magenta, yellow, and black. The mcu will then communicate with 5 stepper drivers which are wired to 5 Stepper motors that will dispense the appropriate amount of white, cyan, magenta, yellow and black paint into a cup. The components will be powered by a non-rechargeable battery bank and the final result should a paint cup with the color that was scanned before. Ideally the person using this tool never needs to actually do any mixing, they can just scan a color and apply it directly on the canvas/work surface.

Materials :
3D Printed device casing

5 Peristaltic Pumps -> 5 Stepper Motors

5 Pump controller -> Stepper Drivers

Status LED's

Small Digital Display

STM32 Series MCU (PCB with similar pins to Dough Monitor)

Battery Bank with some sort of DC jack

Potentially : Buzzer, Bluetooth Control

________________________________________________________________________________________________

9/8/24

Rajeev's post didn't get approved yet Professor wanted some extra information: 

Hello Professor thanks for the feedback, to add on to what Rajeev said, we are planning on using fluid body acyllics,. The key here to to use paints with a low viscosity, that would make pumping a lot easier - as you can imagine a paint similar to oil paint would be really tough to use while something more ink-like and watery like guache/fluid body acryllics would be a lot more feasible.

We would like to have a recharging capability to the project, our initial proposal used a dispensable battery pack just because that seemed at the time much easier to implement and is not really the focus of the project - which you stated is accurately mixing the paint. However we agree that it might be necessary to do this anyway given that we are powering several systems, and being able to recharge our system might be way more convenient in the long run as we test and fix issues.

Also, the calculations required to convert RGB to paint are pretty simply and probably the easiest part of this whole project. There are 6 formulas used to convert RGB to CMYK (the model used in printers. Really these values are just proportions, suppose C is 0.5 and we want 100mL of white paint in the mixture, the amount of Cyan paint needed is 100mL of White * 0.5 = 50mL. Now figuring out how to dispense 50mL of a liquid using a motor is a challenge, but I wouldn't say it's too good to be true. By using Stepper motors which are much more controllable than DC motors and with some motor calibration that Rajeev mentioned before - run the motor for x amount of time at some specific settings and see how much x mL of liquid gets dispensed. If the process ends up being too difficult with our acrylics then we will switch to a paint that is more watery.

R' = R/255
G' = G/255
B' = B/255
K = 1-max(R', G', B')
C = (1-R'-K) / (1-K)
M = (1-G'-K) / (1-K)
Y = (1-B'-K) / (1-K)

![Image]()	
________________________________________________________________________________________________

9/12/24 

PCB Needs to get done in a few weeks let's start looking for parts:
MOTOR https://www.amazon.com/peristaltic-Stepper-KPHM100-Service-high-Precision/dp/B0B99ZH9C1/ref=sr_1_1_sspa?crid=3P89EUCOQIJ3G&dib=eyJ2IjoiMSJ9.TPwDIg-bL8P5Tvg9BKPSdzpgey4PK_kuKon2pRRE6ixJzShd4wL6ktk2FXDDS6armvdMxbbdsbKdpevz5GLeKuyC4rBoRRnTa1FXnzq9i4bP_EFjnJVZRSS8uAX-meVMOm-TgqH6CL9QhZ-yMN7Lq27z-Y4eaZNXshNd6Nt7U0cszJwzaRGP5r_b3kN_EX8M77nZwsKRgNXgs-JVKp3dJCkBkvfY6RQ4A9-H0GStdhE.amgJhaxBD09Ocb6JQho2vgTS1uyKtf7nGYPKcqbWYLA&dib_tag=se&keywords=stepper+motor+peristaltic+pump&qid=1729451401&sprefix=stepper+motor+peristaltic+oump%2Caps%2C125&sr=8-1-spons&sp_csd=d2lkZ2V0TmFtZT1zcF9hdGY&psc=1

MOTOR DRIVER https://www.amazon.com/BIGTREETECH-DIRECT-TMC2209-Stepsticks-Motherboard/dp/B07ZQ3C1XW/ref=sr_1_1_sspa?dib=eyJ2IjoiMSJ9.U9QqZZCr7u-b-HbT3uPO-zE4vSmFXI_rhJhKmIr0TgVV741QgU-WoRW-C_OA9pagXsh4KJoYXiQGUFHtHxaKJG_HkXvoDbmjAzFrXvECiDRU3yPJ0chU2g7GpDdutmFRKEnT0C9-tuOFL1DbpIMi1q__SOl2UJkTHpyzK_avUVW_Z7lMmy7hxiZpAesxpDdlI8JyICitRBOrvAXSbGMNJ-eoqyPX6ZO4bmkdwuyPmCA.F_ZLp0XKpwx09wVoFzJtqZPXhxQ33mUgyxWnJDEMJ0Q&dib_tag=se&hvadid=694425533740&hvdev=c&hvexpln=67&hvlocphy=9007527&hvnetw=g&hvocijid=11844786358995837023--&hvqmt=e&hvrand=11844786358995837023&hvtargid=kwd-866463465553&hydadcr=8684_13501820&keywords=tmc2209%2Bstepper%2Bdriver&qid=1729452567&sr=8-1-spons&sp_csd=d2lkZ2V0TmFtZT1zcF9hdGY&th=1
https://www.digikey.com/en/products/detail/analog-devices-inc-maxim-integrated/TMC2209-LA-T/10232491

RGB SENSOR https://www.adafruit.com/product/3779
https://mm.digikey.com/Volume0/opasdata/d220001/medias/docus/758/3779_Web.pdf                
Circuit Protection https://www.digikey.com/en/products/detail/stmicroelectronics/USBLC6-2SC6Y/2819177
24V Power Supply https://www.amazon.com/EMITEVER-Lighting-Transformers-100-240V-UL-Listed/dp/B09S9YF9BX?source=ps-sl-shoppingads-lpcontext&ref_=fplfs&psc=1&smid=A3TH0XOU4ISKPM

Microcontroller https://www.st.com/content/ccc/resource/technical/document/datasheet/group3/98/80/dc/e5/f8/4b/4b/a3/DM00366448/files/DM00366448.pdf/jcr:content/translations/en.DM00366448.pdf
USB Connection https://www.mouser.com/ProductDetail/Amphenol-Commercial-Products/12401598E42A?qs=367PjNmvCmllVMBVyIyS3w%3D%3D
Display https://www.amazon.com/Enhanced-NX4024K032-Resistive-Function-Dashboard/dp/B0BHN7QKVP?dib=eyJ2IjoiMSJ9.tWZNXU-lL10mQ-v1ue0fw2kgqb3gMJ3sC-Zqk_7NqrcGq3jx2iOOz9kl8boMj3umYkYOaU5sLWN3Gz1I3PTkSYWT4gD6AsJ4GV3DL3bwQPdDA_SY3U-2pD8IsvOvUvbfLZA7WlJ9zgrblBz0r1p1TtC-vDa_ppXiWQNnfmBk6gcbyN25NHXAOHqulks57UGRSgRbUeFRajvHURnGm01b3W6cQJAUjjZDB_mQ-WAHWLg.a4o5eR0zAI2tHyLVnoXIS7Hw8xdT1JEUoMlxTot4YwY&dib_tag=se&keywords=nextion%2Bdisplay&qid=1729464789&refinements=p_36%3A-5000&rnid=386442011&sr=8-4&th=1
Voltage Regulator 24V to 3.3V https://www.pololu.com/product/2842 




10.88 for resistors and capacitors

https://jiaolyulu.github.io/kineticSculpture/stepperTMC2209.html

https://learn.watterott.com/silentstepstick/faq/#calculator-tmc21xx-and-tmc2209

https://www.programming-electronics-diy.xyz/2023/12/tmc2209-stepper-driver-module-tutorial.html


 https://forum.arduino.cc/t/tmcstepper-arduino-tmc2209/956036

________________________________________________________________________________________________

9/18/24
TA Weekly Meeting:


** We might need to talk to the machine shop about getting **

Project Kickoff and Initial Brainstorming:

The team introduced the concept of the project: an automated color-detecting paint dispenser designed to streamline color mixing and application processes. This system aims to address challenges faced by artists and industrial users in achieving consistent color reproduction.

Key motivations for the project were outlined, emphasizing efficiency, precision, and user-friendliness. The TA provided feedback on refining these motivations to ensure clear alignment with the course objectives.

Proposal Requirements:

The TA explained the essential components of the project proposal:

Introduction: Establishing the motivation and context of the project.

Problem: Detailed description of the challenges and justification for solving them.

Solution: High-level description of the approach, emphasizing implementation specifics where possible.

Visual Aid: A conceptual diagram illustrating the system's functionality and integration with external systems.

Ethics and Safety: Addressing relevant concerns, including environmental impact and user safety.

Suggestions were made to connect the problem statement with real-world examples, such as automotive paint application and artistic projects.



We really need to research more about possible microncontrollers we should use right now we are learning towards stm32 architecture because they are really beefy and powerful, not sure yet what the scope of the project might be. 

________________________________________________________________________________________________

9/25/25

Project Kickoff and Initial Brainstorming:

For the design doc:  concept of the project: an automated color-detecting paint dispenser designed to streamline color mixing and application processes. This system aims to address challenges faced by artists and industrial users in achieving consistent color reproduction.

Key motivations for the project were outlined, emphasizing efficiency, precision, and user-friendliness. The TA provided feedback on refining these motivations to ensure clear alignment with the course objectives.


Proposal Requirements:

essential components of the project proposal:

Introduction: Establishing the motivation and context of the project.

Problem: Detailed description of the challenges and justification for solving them.

Solution: High-level description of the approach, emphasizing implementation specifics where possible.

Visual Aid: A conceptual diagram illustrating the system's functionality and integration with external systems.

Ethics and Safety: Addressing relevant concerns, including environmental impact and user safety.

Suggestions were made to connect the problem statement with real-world examples, such as automotive paint application and artistic projects.

Action Items:

Me: Begin drafting the problem and solution sections of the proposal.

Rajeev: Research existing automated paint dispensers and their limitations to provide context.

Lucky: Sketch an initial conceptual diagram for the visual aid.

Team: Schedule a follow-up meeting to review individual contributions and consolidate them into a cohesive proposal.



The grades for the proposals and the soldering assignment were released. Chi Zhang advised us to verify our grades for accuracy.
A separate email will be sent detailing where points were deducted from the proposals. Full points can be regained if the proposal is modified and resubmitted before the deadline next week.


Design Document Overview:
The design document is due next week. we need to start reviewing the template and grading rubric on the course website.
Special emphasis was placed on the Requirement and Verification table, which has its own webpage. Formatting must adhere to the standards outlined in the rubric.


Component Orders:
The portal for component orders has not yet opened. In the meantime, the inventory page should be checked for available components.
Components listed in the inventory can be accessed without placing an order.


Project Progress Update Based on our design document draft:

- The RGB sensor and microcontroller interface are outlined, with the sensor converting RGB data to CMYK proportions.

- The motor drivers and peristaltic pumps are described, emphasizing precision in dispensing paint volumes.

- power supply and custom PCB designs have been preliminarily detailed.

- Work on hardware integration and software algorithms for RGB to CMYK conversion is ongoing.

Code for the project

```
/***************************************************************************
  This is a library for the Adafruit AS7262 6-Channel Visible Light Sensor

  This sketch reads the sensor

  Designed specifically to work with the Adafruit AS7262 breakout
  ----> http://www.adafruit.com/products/3779
  
  These sensors use I2C to communicate. The device's I2C address is 0x49
  Adafruit invests time and resources providing this open source code,
  please support Adafruit andopen-source hardware by purchasing products
  from Adafruit!
  
  Written by Dean Miller for Adafruit Industries.
  BSD license, all text above must be included in any redistribution
 ***************************************************************************/

#include <Wire.h>
#include "Adafruit_AS726x.h"

//create the object
Adafruit_AS726x ams;

//buffer to hold raw values
uint16_t sensorValues[AS726x_NUM_CHANNELS];

//buffer to hold calibrated values (not used by default in this example)
//float calibratedValues[AS726x_NUM_CHANNELS];

void setup() {
  Serial.begin(9600);
  while(!Serial);
  
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);

  //begin and make sure we can talk to the sensor
  if(!ams.begin()){
    Serial.println("could not connect to sensor! Please check your wiring.");
    while(1);
  }
}

void loop() {

  //read the device temperature
  uint8_t temp = ams.readTemperature();
  
  //ams.drvOn(); //uncomment this if you want to use the driver LED for readings
  ams.startMeasurement(); //begin a measurement
  
  //wait till data is available
  bool rdy = false;
  while(!rdy){
    delay(5);
    rdy = ams.dataReady();
  }
  //ams.drvOff(); //uncomment this if you want to use the driver LED for readings

  //read the values!
  ams.readRawValues(sensorValues);
  //ams.readCalibratedValues(calibratedValues);

  Serial.print("Temp: "); Serial.print(temp);
  Serial.print(" Violet: "); Serial.print(sensorValues[AS726x_VIOLET]);
  Serial.print(" Blue: "); Serial.print(sensorValues[AS726x_BLUE]);
  Serial.print(" Green: "); Serial.print(sensorValues[AS726x_GREEN]);
  Serial.print(" Yellow: "); Serial.print(sensorValues[AS726x_YELLOW]);
  Serial.print(" Orange: "); Serial.print(sensorValues[AS726x_ORANGE]);
  Serial.print(" Red: "); Serial.print(sensorValues[AS726x_RED]);
  Serial.println();
  Serial.println();
}

```

________________________________________________________________________________________________

9/28/24

Grades Released:

The grades for the proposals were released. The TA advised us to verify our grades for accuracy.

Give quantitative high level requirements when possible                                                   -1
Visual aid: only has 4 motors but the solution says there are 5.                                         -1
Block diagram: make professional block diagram see template Fall 2022 group 1            -1
Label the component (chip number) and subsystems on the block diagram.                     -1
Need quantitative requirement for your color detection                                                       -0
Give formula/calculation process for how much paint the dispenser should output            -1
Describe the process of controlling the motor (how to determine the PWM, and the duration of operation) and how Low flow peristaltic pumps work even if you are buying them off the shelf.                                                                                                                                                        -1

Started Board layout: 
![Image]([http://url/a.png](https://github.com/skaplich/CMYK_Paint_Mixer_1.0/blob/main/Photos/sc.png))	


________________________________________________________________________________________________

10/16/24

final PCB is complete, we need to solder it and test it. 

Right now Lucky is responsible for ordering all the parts so I need to talk to him about making orders.

