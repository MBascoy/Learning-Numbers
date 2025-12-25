#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#include "constants.h"
#include "learning_numbers.h"
#include "common/globals.h"

uint8_t count_active(uint16_t inputs){

    uint8_t counter = 0;

    for(uint8_t i=0; i<16; i++){
        if(inputs & (1<<i))
            counter++;
    }

    return counter;
}

int main(void) {
    SPI_init();
    
    init_timer1();

    while(1) {


    }
}
