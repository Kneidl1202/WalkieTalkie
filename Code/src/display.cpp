//code for the monitor

#include <Arduino.h>
#include "global.cpp"
#include "TFT.h"
#include <SPI.h>

#define cs 10
#define dc 9
#define rst 8

TFT TFTscreen = TFT(cs, dc, rst);

//initial the display
void InitDisplay()
{
    TFTscreen.begin();
    TFTscreen.background(0, 0, 0);
    TFTscreen.setTextSize(2);
}

//Main method. called every loop round. manages the display
void MainDisplay()
{
    //call methods which have to be updated every time
    //call setFrequency everytime to update displayed frequency
}

//call this method to update the frequency displayed on the screen
void setFrequency(char freq[])
{
    TFTscreen.text(freq, 6, 6);
}