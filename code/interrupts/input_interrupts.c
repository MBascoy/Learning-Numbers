#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#include "../common/globals.h"
#include "../learning_numbers.h"

ISR(PCINT1_vect) {

    if(bit_is_clear(PINC, PC3)){
        game_mode = 1;
        delay_mode = 1;
        random_number = 7;
        TCNT0 = 0;
    }

    if(bit_is_clear(PINC, PC0)){
        uint8_t active_count = count_active(entradas);

        if(active_count == random_number){
            PORTD = 1;
            random_number = 17;
            delay_mode = 2;
        }
        else{
            PORTD = 2;
        }
    }
}