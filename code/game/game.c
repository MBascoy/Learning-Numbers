#include <avr/io.h>

#include "../learning_numbers.h"
#include "../common/globals.h"

void set_new_level(){
    uint8_t new_number;

    new_number = get_random(min_number, max_number);

    if(new_number == random_number){
        if(new_number == max_number)
            new_number--;
        else
            new_number++;
    }

    random_number = new_number;
}