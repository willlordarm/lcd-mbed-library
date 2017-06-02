#ifndef MBED_LCD_H
#define MBED_LCD_H
/** Classe Lcd, utilisée par l'IOGS pour afficher des informations sur l'ecran.
 *
 * Example:
 * @code
 * #include "mbed.h"
 * #include "Lcd.h"
 * Lcd ecran(D9,D13,D12,D11,D10);
 * 
 * int main()
 * {
 *     ecran.init_LCD();
 *     char i=1,j=1;
 *     char str[]="J'affiche quelque\0";
 *     while(1) {
 *         ecran.writeStr_LCD(str,i,j);
 *     }
 * }
 * @endcode
 */
#include "mbed.h"
 
class Lcd {
public:
        /** Déclare un écran LCD
         *
         * @param rs Broche de la carte Nucleo L476RG reliée à la broche rs du LCD
         * @param sck Broche de la carte Nucleo L476RG reliée à la broche sck du LCD
         * @param miso Broche de la carte Nucleo L476RG reliée à la broche miso du LCD
         * @param mosi Broche de la carte Nucleo L476RG reliée à la broche mosi du LCD
         * @param cs Broche de la carte Nucleo L476RG reliée à la broche cs du LCD
         */
    Lcd(PinName rs, PinName sck, PinName miso, PinName mosi,PinName cs);
        /** Fonction d'initialisation de l'écran LCD
         * @note l'appel de cette fonction est essentiel pour afficher quelque chose sur le LCD
         * @code
         */
    void init_LCD(void);

    void write_LCD(char c);

    void writeStr_LCD(char c[], char ligne, char colonne);

    
private:
    DigitalOut RS_LCD;
    SPI spi; // mosi, miso, sclk
    DigitalOut CS;
    void writeCmd_LCD(char c);
    void setPosition(char ligne, char colonne);
    void init_SPI(void);
};

#endif