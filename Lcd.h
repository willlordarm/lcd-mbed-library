#ifndef MBED_LCD_H
#define MBED_LCD_H
 
#include "mbed.h"
 
class Lcd {
public:
    Lcd(PinName rs, PinName sck, PinName miso, PinName mosi,PinName cs);
    void write_LCD(char c);
    void writeStr_LCD(char c[], char ligne, char colonne);
    void writeCmd_LCD(char c);
    void setPosition(char ligne, char colonne);
    void init_SPI(void);
    void init_LCD(void);
    
private:
    DigitalOut RS_LCD;
    SPI spi; // mosi, miso, sclk
    DigitalOut CS;
};

#endif