/* digits_h_inverted.h - 0..9, cada número 8 bytes, LSB = columna izquierda */
#include <stdint.h>

volatile uint8_t icons[][8] =
{
  // Happy face
  {
    0b11111111,
    0b10000001,
    0b10100101,
    0b10000001,
    0b10100101,
    0b10011001,
    0b10000001,
    0b11111111,
  },
  // Sad face
  {
    0b11111111,
    0b10000001,
    0b10100101,
    0b10000001,
    0b10011001,
    0b10100101,
    0b10000001,
    0b11111111,
  },
  // Chess pattern
  {
    0b10101010,
    0b01010101,
    0b10101010,
    0b01010101,
    0b10101010,
    0b01010101,
    0b10101010,
    0b01010101
  },
};
