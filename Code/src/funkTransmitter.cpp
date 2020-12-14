//here will be the code for the funk module

#include <SoftwareSerial.h>

SoftwareSerial HC12(10, 11); //HC-12 TX-PIN, HC-12 RX-PIN

void InitFunkTransmitter()
{
    HC12.begin(9600);
}

int MainFunkTransmitter(int txd[] = {})
{
    //call first TXD and send datas. then read datas and return them.
    return 0;
}

//TODO sendign is an Array if I'm right
void TXD(int txd[])
{
    int i;
    for (i = 0; i < int(sizeof(txd)); ++i) //TODO not sure if it does what it has to
    {
        HC12.write(txd[i]); // Send that data to HC-12
    }
}

//TODO return should be a array if I'm right
int RXD()
{
    int ret = 0;

    while (HC12.available())
    {
        ret = HC12.read(); // return the data to Serial monitor
    }

    return ret;
}