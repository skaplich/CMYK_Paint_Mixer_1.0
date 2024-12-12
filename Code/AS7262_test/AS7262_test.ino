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
  
  ams.drvOn(); //uncomment this if you want to use the driver LED for readings
  ams.startMeasurement(); //begin a measurement
  
  //wait till data is available
  bool rdy = false;
  while(!rdy){
    delay(5);
    rdy = ams.dataReady();
  }
  ams.drvOff(); //uncomment this if you want to use the driver LED for readings

  //read the values!
  ams.readRawValues(sensorValues);
  //ams.readCalibratedValues(calibratedValues);

  // Serial.print("Temp: "); Serial.print(temp);
  // Serial.print(" Violet: "); Serial.print(sensorValues[AS726x_VIOLET]);

  // Serial.print(" Yellyow: "); Serial.print(sensorValues[AS726x_YELLOW]);
  // Serial.print(" Orange: "); Serial.print(sensorValues[AS726x_ORANGE]);
  int rval = ((sensorValues[AS726x_RED]/ 3000.00) * 255.00);
  int gval = ((sensorValues[AS726x_GREEN]/ 7000.00) * 255.00);
  int bval = ((sensorValues[AS726x_BLUE]/ 4000.00) * 255.00);
  if(rval > 255){
    rval = 255;
  }
  if(bval > 255){
    bval = 255;
  }
  if(gval > 255){
    gval = 255;
  }
  Serial.print(" Red: "); Serial.print(rval);
  Serial.print(" Green: "); Serial.print(gval); 
  Serial.print(" Blue: "); Serial.print(bval);
 
  Serial.println();
  Serial.println();
}
