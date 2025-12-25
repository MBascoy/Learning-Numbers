#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#include "constants.h"
#include "learning_numbers.h"
#include "common/globals.h"

int main(void) {
    SPI_init();

    inputs_init();
    
    init_timer1();

    while(1) {
    }
}
