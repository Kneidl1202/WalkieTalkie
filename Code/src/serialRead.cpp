#include <Arduino.h>
#include <global.h>

void mainSerialRead()
{
    while (Serial.available())
    {
        sendBuffer += String(Serial.read());
        sendBuffer += ' ';
        Serial.print("sendBuffer in loop: \" \n");
        Serial.println(sendBuffer);
        Serial.println("\"");
    }
}