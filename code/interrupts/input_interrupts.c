#include <avr/io.h>
#include <avr/interrupt.h>

#include "../common/globals.h"
#include "../learning_numbers.h"

ISR(PCINT1_vect) {

    if(bit_is_clear(PINC, PC3)){
        game_mode = 1;
        random_number = TCNT1%5; //show 1
    }

    if(bit_is_clear(PINC, PC0)){
        uint8_t active_count = count_active(entradas);

        if(active_count == random_number){
            PORTD = 1;
        }
        else{
            PORTD = 2;
        }
    }
}