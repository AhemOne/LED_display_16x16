#ifndef defs_h
#define defs_h

#include <Arduino.h>

using pin_t = unsigned int;

union v16_t {
  struct {
    byte low;
    byte high;
  };
  uint16_t value;
};

#endif
