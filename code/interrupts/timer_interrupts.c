#include <avr/io.h>
#include <avr/interrupt.h>

#include "../learning_numbers.h"
#include "../common/globals.h"
#include "../constants.h"

ISR(TIMER1_COMPA_vect) {
    show_display();
}

ISR(TIMER0_COMPA_vect) {

    if(animation_active != 0)
        timer0_counter++;

    if(debounce_switch == 1){
        debounce_timer0_counter++;
    }

    if(debounce_switch == 1 && debounce_timer0_counter >= DEBOUNCE_DURATION){
        debounce_switch = 0;
        debounce_timer0_counter = 0;
    }

    if(animation_active == 1 && (timer0_counter % ANIMATION_DELAY == 0)){
        animation_number++;
        if (animation_number == 10){
            animation_number = 0;
        }
    }

    if(animation_active == 1 && timer0_counter >= ANIMATION_DURATION){
        timer0_counter = 0;
        animation_active = 0;
    }

    if(animation_active == 2 && timer0_counter >= RESULT_DURATION){
        timer0_counter = 0;

        if(result == 1){
            animation_active = 1;
        }
        else{
            animation_active = 0;
        }
    }
}