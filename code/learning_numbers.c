#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <avr/power.h>

#include "constants.h"
#include "learning_numbers.h"
#include "common/globals.h"

int main(void) {
    clock_prescale_set(clock_div_1);

    SPI_init();

    inputs_init();
    
    init_timers();

    while(1) {
    }
}
