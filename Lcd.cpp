#include "Lcd.h"
#include "mbed.h"

Lcd::Lcd(PinName rs, PinName sck, PinName miso, PinName mosi,PinName cs) : RS_LCD(rs),spi(mosi,miso,sck),CS(cs) {};


void Lcd::write_LCD(char c)
{
    CS = 0;
    RS_LCD = 1;
    spi.write(c);
    //  wait_ms(1);
    RS_LCD = 1;
    CS = 1;
    return;
}

void Lcd::writeStr_LCD(char c[], char ligne, char colonne)
{
    char i=0;
    setPosition(ligne,colonne);
    while(c[i] != '\0') {
        write_LCD(c[i]);
        i++;
    }
    char lig = i/16 + 1;
    char col = i%16 + 1;
    setPosition(lig,col);
}

void Lcd::writeCmd_LCD(char c)
{
    CS =0;
    RS_LCD =0;
    spi.write(c);
    RS_LCD = 1;
    CS = 1;
    return;
}

void Lcd::setPosition(char ligne, char colonne)
{
    char adress = 0x80 + ((ligne-1)*16) + (colonne -1);
    writeCmd_LCD(adress);
    wait_ms(1);
    return;
}
void Lcd::init_SPI(void)
{
    // Chip must be deselected
    CS = 1;
    // Setup the spi for 8 bit data, high steady state clock,
    // second edge capture, with a 1MHz clock rate
    spi.format(8,3);
    spi.frequency(10000);
    // Select the device by seting chip select low
}

void Lcd::init_LCD(void)
{
    init_SPI();
    wait_ms(10);
    CS = 0;
    RS_LCD = 0;
    spi.write(0x29); // Function Set - Table 1
    spi.write(0x1D); // Bias Set
    spi.write(0x50); // Power Control
    spi.write(0x6C); // Follower Control
    spi.write(0x7C); // Contrast Set
    spi.write(0x03); // Function Set - Table 0
    spi.write(0x0F);
    spi.write(0x01); // Clear Display
    wait_ms(2);
    spi.write(0x06); // Display On
    wait_ms(10);
    RS_LCD=1;
    CS=1;
    wait_ms(10);
    return;
}