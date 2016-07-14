//#include <Keyboard.h>

#include <Adafruit_NeoPixel.h>
#include <avr/power.h>

/*
This is code that I use in my class Costumes as Game Controllers to teach building switches using Adafruit's FLORA. 
It's a mash up of the following examples:

    DigitalInputPull example on the Arduino IDE.
    Arduino Debounce Tutorial http://arduino.cc/en/Tutorial/Debounce
    Arduino Mouse Keyboard http://arduino.cc/en/Reference/MouseKeyboard
 */

// constants won't change. They're used here to 
// set pin numbers:
const int buttonPin = 10;     // the number of the pushbutton pin
const int ledPin =  7;      // the number of the LED pin
const int glovePin = 9;     // the number of the glove pin
const int neopixelPin = 12;  //the number of the neopixel pin
  
Adafruit_NeoPixel strip = Adafruit_NeoPixel(3, neopixelPin, NEO_GRB + NEO_KHZ800);

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status
//int lastButtonState = 0;   //FOR DEBOUNCING

int gloveState = 0;         // variable for reading the glovebutton status
//int lastGloveState = 0;   //FOR DEBOUNCING

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);      
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT_PULLUP);   
    // initialize the glovebutton pin as an input:
  pinMode(glovePin, INPUT_PULLUP);   
    // start neopixels
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
 // Keyboard.begin(); // FOR KEYBOARD STROKE
}

void loop(){
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);
  
    // read the state of the glovebutton value:
  gloveState = digitalRead(glovePin);
  

  // check if the pushbutton is pressed.
  // if it is, the buttonState is LOW:                     
  if (buttonState == LOW) {     
  //if (buttonState == LOW && lastButtonState == LOW) {  //FOR DEBOUNCING 
    // turn LED on: 
   //  Keyboard.press(' '); //FOR KEYBOARD STROKE
    digitalWrite(ledPin, HIGH);  
    colorWipe(strip.Color(0, 0, 255), 50); // Blue
  } 
  else {    
    // turn LED off:
   // Keyboard.release(' ');//FOR KEYBOARD STROKE
    digitalWrite(ledPin, LOW); 
    colorWipe(strip.Color(0, 0, 0), 50); // Blue
  }
  //  lastButtonState = buttonState; ///FOR DEBOUNCING
  
  
  // check if the glovebutton is pressed.
  // if it is, the gloveState is LOW:                     
  if (gloveState == LOW) {     
  //if (gloveState == LOW && lastGloveState == LOW) {  //FOR DEBOUNCING 
    // turn LED on: 
   //  Keyboard.press('a'); //FOR KEYBOARD STROKE
    digitalWrite(ledPin, HIGH);
    colorWipe(strip.Color(255, 0, 0), 50); // Blue  
  } 
  else {    
    // turn LED off:
   // Keyboard.release('a');//FOR KEYBOARD STROKE
    digitalWrite(ledPin, LOW); 
      colorWipe(strip.Color(0, 0, 0), 50); // Blue
  }
  //  lastGloveState = gloveState; ///FOR DEBOUNCING
}  


//////////NEOPIXEL FUNCTIONS////////////////
// Fill the dots one after the other with a color
void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, c);
      strip.show();
      delay(wait);
  }
}

