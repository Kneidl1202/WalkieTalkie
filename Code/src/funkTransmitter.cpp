//here will be the code for the funk module

#include <Arduino.h>
#include <SoftwareSerial.h>
#include <global.h>
#include "ezButton.h"

#define higherButtonPin 5
#define lowerButtonPin 6
#define setPin 7

SoftwareSerial HC12(A1, A0); //HC-12 TX-PIN, HC-12 RX-PIN

ezButton higherButton(higherButtonPin);
ezButton lowerButton(lowerButtonPin);

void InitFunkTransmitter()
{
    HC12.begin(9600);

    sendBuffer = "";
    readBuffer = "";

    higherButton.setDebounceTime(50);
    lowerButton.setDebounceTime(50);

    pinMode(setPin, OUTPUT);
    digitalWrite(setPin, HIGH);

    Serial.println("done init funktransmitter");
}

//TODO sendign is an Array if I'm right
void TXD()
{
    int i;

    for (i = 0; i < sizeof(sendBuffer); ++i) //TODO not sure if it does what it has to do
    {
        HC12.write(byte(sendBuffer[i])); // Send that data to HC-12
    }

    sendBuffer = "";
}

//TODO return should be a array if I'm right. create an array in global.h and use that one to store the read dataset.
void RXD()
{
    int i = 0;

    while (HC12.available())
    {
        readBuffer += char(HC12.read()); //gets the data and stores it in buffer
        ++i;
    }
}

void sendATCommand(String channel)
{
    HC12.print(channel);
    delay(100);

    digitalWrite(setPin, LOW);
    delay(100);

    HC12.print(channel);
    delay(200);

    digitalWrite(setPin, HIGH);
    delay(200);
}

void higherChannel()
{
    if (channelBuffer != 100)
        channelBuffer++;

    if (channelBuffer < 10)
        sendATCommand("AT+C00" + channelBuffer);

    else if (channelBuffer < 100)
        sendATCommand("AT+C0" + channelBuffer);

    else
        sendATCommand("AT+C" + channelBuffer);
}

void lowerChannel()
{
    if (channelBuffer != 0)
        channelBuffer--;

    if (channelBuffer < 10)
        sendATCommand("AT+C00" + channelBuffer);

    else if (channelBuffer < 100)
        sendATCommand("AT+C0" + channelBuffer);

    else
        sendATCommand("AT+C" + channelBuffer);
}

void changeChannel()
{
    if (lowerButton.isPressed())
        lowerChannel();
    else if (higherButton.isPressed())
        higherChannel();

    displayedChannel = channelBuffer;
}

//main Function for Funk Transmitter. get called every loop round. sends data over and recieves data.
void MainFunkTransmitter()
{
    //call first TXD and send datas. then read datas
    changeChannel();
    TXD();
    RXD();

    //Serial.println("main Funktransmitter");
}