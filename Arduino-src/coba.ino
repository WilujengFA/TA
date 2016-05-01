/*
Project:	coba
Board:		uno
MCU:		16MHzatmega328	
FRENQUENCY:	16000000

Created using Qt Creator
*/
#ifndef ARDUINO_H
#define ARDUINO_H
#include <Arduino.h>
#endif

#define Cal_Factor 0.0001984
#define SensorPin A0            //pH meter Analog output to Arduino Analog Input 0
#define Offset 0.00            //deviation compensate
#define LED 13
#define samplingInterval 20
#define printInterval 800
#define ArrayLenth  40    //times of collection
int pHArray[ArrayLenth];   //Store the average value of the sensor feedback
int pHArrayIndex=0;

unsigned long samplingTime = millis();
unsigned long printTime = millis();
float pHValue,voltage;

float v_p10;
float v_p7;
float v_p4;
float temp_cal;

float temp;

double avergearray(int* arr, int number);
float pHConversion(float input, float cal_1, float cal_2, float cal_3, float temp, float temp_cal);

void setup()
{
    pinMode(LED,OUTPUT);
    Serial.begin(9600);
    Serial.println("pH meter experiment!");    //Test the serial monitor
}

void loop()
{


    if(millis()-samplingTime > samplingInterval)
    {
      pHArray[pHArrayIndex++]=analogRead(SensorPin);
      if(pHArrayIndex==ArrayLenth)pHArrayIndex=0;
      voltage = avergearray(pHArray, ArrayLenth)*5.0/1024;

//      pHValue = 3.5*voltage+Offset;

      pHValue = pHConversion(voltage,v_p10,v_p7,v_p4,temp,temp_cal);
      samplingTime=millis();
    }

    if(millis() - printTime > printInterval)   //Every 800 milliseconds, print a numerical, convert the state of the LED indicator
    {
    Serial.print("Voltage:");
       Serial.print(voltage,2);
       Serial.print("    pH value: ");
    Serial.println(pHValue,2);
       digitalWrite(LED,digitalRead(LED)^1);
       printTime=millis();
    }
}

double avergearray(int* arr, int number){
    int i;
    int max,min;
    double avg;
    long amount=0;

    if(number<=0){
       Serial.println("Error number for the array to avraging!/n");
       return 0;
    }

    if(number<5){   //less than 5, calculated directly statistics

       for(i=0;i<number;i++){
        amount+=arr[i];
       }

       avg = amount/number;
       return avg;
    }
    else{
        if(arr[0]<arr[1]){
          min = arr[0];max=arr[1];
        }
        else{
          min=arr[1];max=arr[0];
        }

       for(i=2;i<number;i++){
         if(arr[i]<min){
           amount+=min;        //arr<min
           min=arr[i];
         }else {
           if(arr[i]>max){
             amount+=max;    //arr>max
             max=arr[i];
           }else{
             amount+=arr[i]; //min<=arr<=max
           }
         }//if
       }
      avg = (double)amount/(number-2);
    }

    return avg;
}

float pHConversion(float input, float cal_1, float cal_2, float cal_3, float temp, float temp_cal){
    float value;
    float zero_value;
    float sensitivity;

    if( (temp < 0)||(temp > 100) )
    {
        return -1.0;
    }
    if((temp_cal < 0)||(temp_cal > 100))
    {
        return -2.0;
    }

    // The value at pH 7.0 is taken as reference
    zero_value = cal_2;

    // The sensitivity is calculated using the other two calibration values
    sensitivity = (cal_3-cal_1)/6;

    // Add the change in the conductivity owed to the change in temperature
    sensitivity = sensitivity + (temp - temp_cal)*Cal_Factor;

    // pH value calculated from the calibration values
    value = 7.0 + (zero_value-input)/sensitivity;

    return value;
}
