#ifndef Plex_4x16_h
#define Plex_4x16_h

#include <defs.h>

template <pin_t A, pin_t B, pin_t C, pin_t D>
struct plex4x16 {
  plex4x16() {
    pinMode(A, OUTPUT);
    pinMode(B, OUTPUT);
    pinMode(C, OUTPUT);
    pinMode(D, OUTPUT);
  }
  
  void select(unsigned int line) {
    digitalWrite(A, line & 0x01);
    digitalWrite(B, line & 0x02);
    digitalWrite(C, line & 0x04);
    digitalWrite(D, line & 0x08);
  }
};

#endif
