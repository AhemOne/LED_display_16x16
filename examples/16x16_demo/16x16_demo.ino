// Arduino headers
#include <SPI.h>

// Our headers
#include <defs.h>
#include <LED_Display_16x16.h>

display16x16<8, 9, 10, 11, 7, 6> display;
uint16_t displayBuffer[16];

// timer:
// timer4 of the Atmega32u4 is used to time when we update our frame. The screen is updated line by line in regular intervals. on a 16 MHz chip the frame rate is around 60 fps, which means there are 960 lines to update each second. We use the timer to divide the clock ratio by 8. Each divided clock pulse is then counted to 512 before the interupt function is called which then updates the next line on the screen.

// timer interupt function
ISR(TIMER4_OVF_vect) {
  unsigned char sreg = SREG;
  cli();
  
  static size_t linecounter = 0;
  
  // update screen
  display.write(displayBuffer[linecounter], linecounter);
  
  // increment, roll over to zero on 16
  linecounter = ++linecounter < 16 ? linecounter : 0;
  
  SREG = sreg;
}

void setup() {
  v16_t v16;
  
  Serial.begin(9600);
  
  // set up clock
  TCCR4B = 0x00;
  TCCR4A = 0x00;
  TCCR4C = 0x00;
  TCCR4D = 0x00;
  TCCR4E = 0x00;
  // timer trigger value
  v16.value = 521;
  TC4H = v16.high;
  OCR4C = v16.low;
  // timer starting value
  v16.value = 0;
  TC4H = v16.high;
  TCNT4 = v16.low;
  // enable clock
  TIMSK4 = 0x05;
  TCCR4B = 0x03;
}

void loop() {
  // wait for a long enough stream of data to come in
  if ( Serial.available() >= 32 ) {
    for ( size_t i = 0; i < 16; ++i ) {
      v16_t v16;
      v16.low = Serial.read();
      v16.high = Serial.read();
      
      // place data into the buffer
      displayBuffer[i] = v16.value;
    }
  }
}
