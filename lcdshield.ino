// project 25 
// this project allows you to press the up and down buttons on the DFROBOT LCD keypad shield v 1.1 to change a face from happy to sad or vise versa 
// majority of this code is from this website: https://forum.arduino.cc/t/dfrobot-lcd-keypad-shield-v1-1-problems/245593/2
// up = smiley face & down = sad face
#include <LiquidCrystal.h>                      // this library must be included 

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);           // select the pins used on the LCD panel

// define some values used by the panel and buttons
int lcd_key     = 0;
int adc_key_in  = 0;

#define btnUP     1
#define btnDOWN   2
#define btnNONE   5

int read_LCD_buttons(){               // read the buttons
    adc_key_in = analogRead(0);       // read the value from the sensor 

    // *AUTHOR NOTES*
    // "my buttons when read are centered at these valies: 0, 144, 329, 504, 741"
    // "we add approx 50 to those values and check to see if we are close"
    // "We make this the 1st option for speed reasons since it will be the most likely result"

    if (adc_key_in < 250 && adc_key_in > 144 )  return btnUP;    // I modifed mv values so pressing other buttons will not change the face
    if (adc_key_in < 450 && adc_key_in > 251)  return btnDOWN; 
    else return btnNONE;    
}

void setup(){
   lcd.begin(16, 2);               // start the library
   lcd.setCursor(0,0);             // set the LCD cursor position 
   lcd.print("Push up or down!");  // print a simple message on the LCD
   analogWrite(10, 255);
   delay(500); 
} 
void loop()
{
   lcd.setCursor(0,1);             // move to the begining of the second line  
   lcd_key = read_LCD_buttons();   // read the buttons

   switch (lcd_key){               // depending on which button was pushed, we perform an action

      case btnUP:{
             lcd.print(":)    ");  //  push button "UP" and show the :) on the screen
             break;
       }
      case btnDOWN:{
             lcd.print(":(    ");  //  push button "DOWN" and show the :( on the screen
             break;
       }
      case btnNONE:{
             lcd.print("  ");  //  No action  will show "None" on the screen
             break;
       }
   }
}
