#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#include "../constants.h"
#include "../common/globals.h"
#include "../learning_numbers.h"

ISR(PCINT1_vect) {

    if(debounce_switch == 1){
        return;
    }

    debounce_switch = 1;
    debounce_timer0_counter = 0;

    if(bit_is_clear(PINC, PC1)){
        game_mode = 1;

        min_number = 1;
        max_number = 5;

        inputs_state = 0;
        animation_active = 1;
        set_new_level();
        TCNT0 = 0;
        timer0_counter = 0;

        dfplayer_play_track(EASY_MODE_AUDIO);
    }

    if(bit_is_clear(PINC, PC2)){
        game_mode = 1;

        min_number = 6;
        max_number = 16;

        inputs_state = 0;
        animation_active = 1;
        set_new_level();
        TCNT0 = 0;
        timer0_counter = 0;

        dfplayer_play_track(HARD_MODE_AUDIO);
    }

    if(bit_is_clear(PINC, PC3)){
        inputs_state = 0;
        game_mode = 2;

        dfplayer_play_track(PRACTICE_MODE_AUDIO);
    }

    if(bit_is_clear(PINC, PC0)){     
        uint8_t active_count = count_active(entradas);

        if(game_mode == 1){
            result = (active_count == random_number) ? 1 : 2;

            if (result == 1){
                inputs_state = 0;
                set_new_level();
            }

            animation_active = 2;
        }
        else if(game_mode == 2){
            dfplayer_play_track(active_count);
        }
    }
}