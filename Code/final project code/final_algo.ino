

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

  // ResetButtonState = digitalRead(PD2);

  // while (ResetButtonState) {


  //    ResetButtonState = digitalRead(PD2);
    
    


  //       digitalWrite(A3, HIGH);
        

  //       delayMicroseconds(100);

      
  //       digitalWrite(A3, LOW);

  //       delayMicroseconds(100);

  //       counter++;
  //       flag = 1;
  // }


  // if (flag) {

  //   Serial.println(counter);
  //   flag = 0;
  //   counter = 0;
  //   Serial.println("Counter Reset");

  // }

  // digitalWrite(PD7, HIGH);

  
}




// // put your main code here, to run repeatedly:
// int8_t temp = ams.readTemperature();

// ams.drvOn(); //uncomment this if you want to use the driver LED for readings
// ams.startMeasurement(); //begin a measurement

// //wait till data is available
// bool rdy = false;
// while(!rdy){
//   delay(5);
//   rdy = ams.dataReady();
// }
// ams.drvOff(); //uncomment this if you want to use the driver LED for readings

// //read the values!
// ams.readRawValues(sensorValues);
// //ams.readCalibratedValues(calibratedValues);

// // Serial.print("Temp: "); Serial.print(temp);
// // Serial.print(" Violet: "); Serial.print(sensorValues[AS726x_VIOLET]);

// // Serial.print(" Yellyow: "); Serial.print(sensorValues[AS726x_YELLOW]);
// // Serial.print(" Orange: "); Serial.print(sensorValues[AS726x_ORANGE]);
// int rval = ((sensorValues[AS726x_RED]/ 3000.00) * 255.00);
// int gval = ((sensorValues[AS726x_GREEN]/ 7000.00) * 255.00);
// int bval = ((sensorValues[AS726x_BLUE]/ 4000.00) * 255.00);
// if(rval > 255){
//   rval = 255;
// }
// if(bval > 255){
//   bval = 255;
// }
// if(gval > 255){
//   gval = 255;
// }
// Serial.print(" Red: "); Serial.print(rval);
// Serial.print(" Green: "); Serial.print(gval);
// Serial.print(" Blue: "); Serial.print(bval);

// Serial.println();
// Serial.println();



//   digitalWrite(PD5, LOW);
//   for(int i = 0; i < 2000; i++){
//     digitalWrite(PD6, HIGH);
//     //digitalWrite(PD4, HIGH);
//     delayMicroseconds(250);              // wait
//     digitalWrite(PD6, LOW);
//     //digitalWrite(PD4, LOW);
//     delayMicroseconds(250);
//   }
//   digitalWrite(PD5, HIGH);

//   while(1){
//  //read the device temperature
//     if(counter == 45000){
//       digitalWrite(PD7, HIGH);
//     }
//     buttonState = digitalRead(PD2);
//     if(buttonState == HIGH){
//       digitalWrite(PD7, HIGH);
//       break;
//     }
//     if(buttonState == 0){

//     digitalWrite(PD6, HIGH);
//     //digitalWrite(PD4, HIGH);
//     delayMicroseconds(250);              // wait
//     digitalWrite(PD6, LOW);
//     //digitalWrite(PD4, LOW);
//     delayMicroseconds(250);              // wait
//     counter++;
//     Serial.println(counter);
//     }
//   }
