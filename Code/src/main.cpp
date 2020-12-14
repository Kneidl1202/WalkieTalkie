#include <Arduino.h>

void InitDisplay();
void InitFunkTransmitter();
void InitMicrophone();

void MainDisplay();
void MainFunkTransmitter();
void MainMicrophone();

void setup()
{
  Serial.begin(9600);

  //microphone
  InitMicrophone();

  //display
  InitDisplay();

  //funkTransmitter
  InitFunkTransmitter();
}

void loop()
{
  //microphone
  MainMicrophone();

  //display
  MainDisplay();

  //funkTransmitter
  MainFunkTransmitter();
}