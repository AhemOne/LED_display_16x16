#ifndef LED_Display_16x16_h
#define LED_Display_16x16_h

#include <defs.h>
#include <Plex_4x16.h>

template <pin_t A, pin_t B, pin_t C, pin_t D, pin_t LAT, pin_t BLANK>
class display16x16 {
  plex4x16<A, B, C, D> plex;
  
public:
  display16x16() {
    pinMode(A, OUTPUT);
    pinMode(B, OUTPUT);
    pinMode(C, OUTPUT);
    pinMode(D, OUTPUT);
    pinMode(LAT, OUTPUT);
    digitalWrite(LAT, HIGH);
    pinMode(BLANK, BLANK);
    digitalWrite(BLANK, LOW);
    SPI.begin();
  }
  
  void write(uint16_t data, unsigned int line) {
    data = ~data;
    char * d = (char *) &data;
    
    
    SPI.beginTransaction(SPISettings(1000000, LSBFIRST, SPI_MODE0));
    {
      digitalWrite(LAT, LOW);
      SPI.transfer(d[1]);
      SPI.transfer(d[0]);
      digitalWrite(BLANK, HIGH);
      plex.select(line);
      digitalWrite(LAT, HIGH);
      digitalWrite(BLANK, LOW);
    }
    SPI.endTransaction();
    
  }
  
  void update() {
  }
};

#endif
