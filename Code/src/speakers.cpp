//here will be the code for the speakers
#include <Arduino.h>

#define SpeakerPin 9

void InitSpeakers()
{
    pinMode(SpeakerPin, OUTPUT);

    Serial.println("done init Speakers");
}

void MainSpeakers()
{
    int delayTime = 300;

    tone(SpeakerPin, 33, 500);
    delay(delayTime);

    tone(SpeakerPin, 37, 500);
    delay(delayTime);

    tone(SpeakerPin, 41, 500);
    delay(delayTime);

    tone(SpeakerPin, 49, 500);
    delay(delayTime);

    tone(SpeakerPin, 55, 500);
    delay(delayTime);

    tone(SpeakerPin, 62, 500);
    delay(delayTime);

    //Serial.println("main speakers");
}