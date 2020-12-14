#include <Arduino.h>
#include "ezButton.h"

ezButton button(7);
bool RA = true;

void setRA(bool RA);
void readOut();

/****************************************
  Example Sound Level Sketch for the
  Adafruit Microphone Amplifier
****************************************/

const int sampleWindow = 50; // Sample window width in mS (50 mS = 20Hz)
unsigned int sample;

#define RA_Pin 3

void InitMicrophone()
{
  button.setDebounceTime(50);
}

void MainMicrophone()
{
  if (button.isPressed())
  {
    RA = !RA;
  }

  //readOut();
  //setRA(RA);
  //delay(1000);
}

void readOut()
{

  unsigned long startMillis = millis(); // Start of sample window
  unsigned int peakToPeak = 0;          // peak-to-peak level

  unsigned int signalMax = 0;
  unsigned int signalMin = 1024;

  // collect data for 50 mS
  while (millis() - startMillis < sampleWindow)
  {
    sample = analogRead(0);
    if (sample < 1024) // toss out spurious readings
    {
      if (sample > signalMax)
      {
        signalMax = sample; // save just the max levels
      }
      else if (sample < signalMin)
      {
        signalMin = sample; // save just the min levels
      }
    }
  }
  peakToPeak = signalMax - signalMin;       // max - min = peak-peak amplitude
  double volts = (peakToPeak * 5.0) / 1024; // convert to volts
  Serial.print("out: ");
  Serial.println(volts);
}

void setRA(bool RA)
{
  Serial.print("RA Level: ");

  if (RA)
  {

    digitalWrite(RA_Pin, LOW);
    Serial.println(0);
  }
  else
  {
    digitalWrite(RA_Pin, HIGH);
    Serial.println(1);
  }
}