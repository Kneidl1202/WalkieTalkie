#include <Arduino.h>
#include "ezButton.h"

//display
#include <TFT.h>
#include <SPI.h>

#define cs 10
#define dc 9
#define rst 8

TFT TFTscreen = TFT(cs, dc, rst);

//microphone
ezButton button(7);
bool RA = true;

void setRA(bool RA);
void readOut();

void setup()
{
  Serial.begin(9600);

  //microphone
  button.setDebounceTime(50);

  //display
  TFTscreen.begin();
  TFTscreen.background(0, 0, 0);
  TFTscreen.setTextSize(2);
}

void loop()
{
  //microphone
  if (button.isPressed())
  {
    RA = !RA;
  }

  //readOut();
  //setRA(RA);
  //delay(1000);

  //display

  //generate a random color
  int redRandom = random(0, 255);
  int greenRandom = random(0, 255);
  int blueRandom = random(0, 255);

  // set a random font color
  TFTscreen.stroke(redRandom, greenRandom, blueRandom);

  // print Hello, World! in the middle of the screen
  TFTscreen.text("Hello, World!", 6, 57);

  // wait 200 miliseconds until change to next color
  delay(200);
}