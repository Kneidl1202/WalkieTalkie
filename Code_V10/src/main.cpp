#include <Arduino.h>
#include "ezButton.h"

ezButton button(7);
bool RA = true;

void setRA(bool RA);
void readOut();

void setup()
{
  Serial.begin(9600);
  button.setDebounceTime(50);
}


void loop()
{   
    if(button.isPressed()){
      RA = !RA;
    }

    readOut();
    setRA(RA);
    delay(1000);
}