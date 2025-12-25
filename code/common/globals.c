#include <avr/io.h>
#include "globals.h"

void init_globals(){
    inputs_reset = 0xFFFF;
    inputs_state=0;

    count_row = 0;
}