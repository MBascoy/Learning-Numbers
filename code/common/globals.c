#include <avr/io.h>
#include "globals.h"
#include "digits.h"

uint16_t inputs_reset = 0xFFFF;
uint16_t inputs_state=0;

uint8_t count_row = 0;
uint8_t game_mode = 0;
uint8_t delay_mode = 0;
uint8_t animation_number = 0;

volatile uint8_t *numbers[][2] = {
    {digits[10], digits[0]},
    {digits[10], digits[1]},
    {digits[10], digits[2]},
    {digits[10], digits[3]},
    {digits[10], digits[4]},
    {digits[10], digits[5]},
    {digits[10], digits[6]},
    {digits[10], digits[7]},
    {digits[10], digits[8]},
    {digits[10], digits[9]},
    {digits[1], digits[0]},
    {digits[1], digits[1]},
    {digits[1], digits[2]},
    {digits[1], digits[3]},
    {digits[1], digits[4]},
    {digits[1], digits[5]},
    {digits[1], digits[6]},
    {digits[10], digits[11]},
};