//here will be the code for the funk module

#include <SoftwareSerial.h>
#include <global.h>

SoftwareSerial HC12(10, 11); //HC-12 TX-PIN, HC-12 RX-PIN

void InitFunkTransmitter()
{
    HC12.begin(9600);

    int i;

    for (i = 0; i < 8; ++i)
    {
        txd[i] = 0;
    }
}

//TODO sendign is an Array if I'm right
void TXD()
{
    int i;

    for (i = 0; i < 8; ++i) //TODO not sure if it does what it has to do
    {
        HC12.write(txd[i]); // Send that data to HC-12
    }

    for (i = 0; i < 8; ++i)
    {
        txd[i] = 0;
    }
}

//TODO return should be a array if I'm right. create an array in global.h and use that one to store the read dataset.
void RXD()
{
    int i = 0;

    while (HC12.available())
    {
        rxd[i] = HC12.read(); // return the data to MainFunkTransmitter
        ++i;
    }
}

//main Function for Funk Transmitter. get called every loop round. sends data over and recieves data.
void MainFunkTransmitter()
{
    //call first TXD and send datas. then read datas
    TXD();
    RXD();
}