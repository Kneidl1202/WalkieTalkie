//code for the monitor

#include <Arduino.h>
#include "TFT.h"
#include <SPI.h>
#include "global.h"

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

    // set display font color (255, 255, 255 is white)
    TFTscreen.stroke(255, 255, 255);

    //set text for display
    Serial.println("done init display");
}

//call this method to update the Channel displayed on the screen
void setChannel()
{
    char channel[sizeof(displayedChannel)];

    for (int i = 0; i < int(sizeof(displayedChannel)); i++)
    {
        channel[i] = displayedChannel[i];
    }
    TFTscreen.text(channel, 6, 6);

    Serial.print("channel: ");
    Serial.println(channel);
}

void printRXD()
{
    char rxd[sizeof(readBuffer)];

    for (int i = 0; i < int(sizeof(readBuffer)); i++)
    {
        rxd[i] = readBuffer[i];
    }

    TFTscreen.text(rxd, 6, 100);

    Serial.print("rxd: ");
    Serial.println(rxd);
}

void printTXD()
{
    char txd[sizeof(sendBuffer)];

    for (int i = 0; i < int(sizeof(sendBuffer)); i++)
    {
        txd[i] = sendBuffer[i];
    }

    TFTscreen.text(txd, 6, 50);

    Serial.print("txd: ");
    Serial.println(txd);
}
//Main method. called every loop round. manages the display
void MainDisplay()
{
    //call methods which have to be updated every time
    //call setChannel everytime to update displayed frequency
    setChannel();

    //to print the read stuff on the display
    printRXD();

    //to print te send stuff on the display
    printTXD();

    Serial.println("main display");
}