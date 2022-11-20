/*
  Analog input, analog output, serial output

  Reads an analog input pin, maps the result to a range from 0 to 255 and uses
  the result to set the pulse width modulation (PWM) of an output pin.
  Also prints the results to the Serial Monitor.

  The circuit:
  - potentiometer connected to analog pin 0.
    Center pin of the potentiometer goes to the analog pin.
    side pins of the potentiometer go to +5V and ground
  - LED connected from digital pin 9 to ground through 220 ohm resistor

  created 29 Dec. 2008
  modified 9 Apr 2012
  by Tom Igoe

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/AnalogInOutSerial
*/
#include <MemoryFree.h>
// on UDOO: 11040 Bytes free memory

// These constants won't change. They're used to give names to the pins used:
const int analogInPin = A0;  // Analog input pin that the potentiometer is attached to
const int analogOutPin = 6;  // Analog output pin that the LED is attached to
const int SIZE = 500;        // Number of samples for moving average
const int ZERO = 414;        // offset voltage of sensor in millivolts for zero wind speed

int sensorValue = 0;  // value read from the pot
int u_in = 0;  // value output to the PWM (analog out)
int u_avg = 0;
int led_value = 0;
int arrNumbers[SIZE] = {0};
int pos = 0;
int newAvg = 0;
long sum = ZERO*SIZE;
int len = sizeof(arrNumbers) / sizeof(int);

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
  for (int i = 0; i < SIZE; i++) {
    arrNumbers[i] = ZERO;
  }
}

int movingAvg(int *ptrArrNumbers, long *ptrSum, int pos, int len, int nextNum)
{
  //Subtract the oldest number from the prev sum, add the new number
  *ptrSum = *ptrSum - ptrArrNumbers[pos] + nextNum;
  //Assign the nextNum to the position in the array
  ptrArrNumbers[pos] = nextNum;
  //return the average
  return *ptrSum / len;
}

void loop() {
  float v_wind;     // m/s
  float v_wind_avg; // m/s, average over 100s
  // read the analog in value:
  sensorValue = 0;
  for (int i = 0; i < 500; i++) {
      sensorValue += analogRead(analogInPin);
      delay(2);
  }
  sensorValue -= 250*5;
  sensorValue /= 500;
  // map it to the range of the analog out:
  u_in = map(sensorValue, 0, 1020, 0, 3300);
  led_value = map(sensorValue, 0, 1020, 0, 255);
  // change the analog out value:
  analogWrite(analogOutPin, led_value);
  u_avg = movingAvg(arrNumbers, &sum, pos, len, u_in);

  v_wind = ((float)u_in/1000.0 - 0.414) / 1.6 * 32.4;
  v_wind_avg = ((float)u_avg/1000.0 - 0.414) / 1.6 * 32.4;
  pos++;
  if (pos >= len){
    pos = 0;
  }

  // print the results to the Serial Monitor:
  Serial.print("voltage: ");
  Serial.print(u_in);
  Serial.print("\t v_wind: ");
  Serial.print(v_wind);
  Serial.print("\t v_wind_avg: ");
  Serial.println(v_wind_avg);
  // Serial.println(freeMemory(), DEC);
  // Serial.println(pos, DEC);
}
