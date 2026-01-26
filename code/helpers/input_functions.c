#include <avr/io.h>
#include <util/delay.h>

#include "../common/globals.h"
#include "../learning_numbers.h"
#include "../audio/audio.h"

uint16_t check_inputs(){
    if(debounce_switch == 0){
        uint16_t inputs=0;

        inputs = read_74HC165();

        for(uint8_t i = 0; i<16; i++){
            uint16_t current_input = inputs & 1<<i;

            if(current_input ==0){
                continue;
            }

            if(current_input & (inputs_reset & 1<<i)){
                debounce_switch = 1;
                inputs_state ^= (1<<i);
            }
        }

        inputs_reset = ~inputs;
    }
    return inputs_state;
}

uint8_t count_active(uint16_t inputs){

    uint8_t counter = 0;

    for(uint8_t i=0; i<16; i++){
        if(inputs & (1<<i))
            counter++;
    }

    return counter;
}