/*
 *  Copyright (c) 2012 Neal Horman - http://www.wanlink.com
 *  
 *  License: MIT open source (http://opensource.org/licenses/MIT)
 *      Summary;
 *      Use / modify / distribute / publish it how you want and 
 *      if you use it, or don't, you can't hold me liable for how
 *      it does or doesn't work.
 *      If it doesn't work how you want, don't use it, or change
 *      it so that it does work.
 */
 
#include "mbed.h"
#include "Adafruit_SSD1306.h"
 
DigitalOut myled(LED1);
 
// an SPI sub-class that provides a constructed default
class SPIPreInit : public SPI
{
public:
    SPIPreInit(PinName mosi, PinName miso, PinName clk) : SPI(mosi,miso,clk)
    {
        format(8,3);
        frequency(2000000);
    };
};
 
// an I2C sub-class that provides a constructed default
class I2CPreInit : public I2C
{
public:
    I2CPreInit(PinName sda, PinName scl) : I2C(sda, scl)
    {
        frequency(400000);
        start();
    };
};
 
//SPIPreIn[it gSpi(p5,NC,p7);
//Adafruit_SSD1306_Spi gOled1(gSpi,p26,p25,p24);
 
I2CPreInit gI2C(p9,p10);
Adafruit_SSD1306_I2c gOled2(gI2C,p27);
 
int main()
{   uint16_t x=0;
 
  //  gOled1.printf("%ux%u OLED Display\r\n", gOled1.width(), gOled1.height());
	gOled2.printf("%ux%u RPM :\r\ n", gOled2.width(), gOled2.height());
    
    while(1)
    {
        myled = !myled;
    //    gOled1.printf("%u\r",x);
  //      gOled1.display();
        gOled2.printf("%u\r",x);
        gOled2.display();
        x++;
        wait(1.0);
    }
}
