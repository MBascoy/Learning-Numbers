#include <avr/io.h>
#include <avr/interrupt.h>

#include "../learning_numbers.h"
#include "../common/globals.h"

ISR(TIMER1_COMPA_vect) {
    show_display();
}

ISR(TIMER0_COMPA_vect) {

    if(animation_active != 0)
        timer0_counter++;

    if(animation_active == 1 && timer0_counter%50 == 0){
        animation_number++;
        if (animation_number == 10){
            animation_number = 0;
        }
    }

    if(animation_active == 1 && timer0_counter >= 500){
        timer0_counter = 0;
        animation_active = 0;
    }

    if(animation_active == 2 && timer0_counter >= 1500){
        timer0_counter = 0;

        if(result == 1){
            animation_active = 1;
        }
        else{
            animation_active = 0;
        }
    }
}