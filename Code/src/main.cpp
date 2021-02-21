#include <Arduino.h>
#include <global.h>
#include <init.h>

String readBuffer;
String sendBuffer;
String displayedChannel;

int channelBuffer;

void setup()
{
  Serial.begin(9600);

  //microphone
  //InitMicrophone();

  //display
  InitDisplay();

  //funkTransmitter
  InitFunkTransmitter();

  //speakers
  InitSpeakers();

  Serial.println("done inits \n");
}

void PrintResults()
{
  Serial.print("RXD: \"");
  Serial.print(readBuffer);
  Serial.println("\"");
  //readbuffer = "";

  Serial.print("TXD: \"");
  Serial.print(sendBuffer);
  Serial.println("\"");
  //sendBuffer = "";

  Serial.print("Channel: ");
  Serial.println(channelBuffer);

  Serial.print("displayedChannel: ");
  Serial.println(displayedChannel);
}

void loop()
{
  //microphone
  //MainMicrophone();

  //since micro not working here serial read
  mainSerialRead();

  //display
  MainDisplay();

  //funkTransmitter
  MainFunkTransmitter();

  //speakers
  //MainSpeakers();

  //print results after each loop round
  PrintResults();

  Serial.println();
  delay(1000);
}