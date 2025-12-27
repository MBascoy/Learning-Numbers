#include <avr/io.h>
#include "../learning_numbers.h"
#include "../common/globals.h"

void next_screen_row(){
    count_row++;
    
    if(count_row >= 8)
        count_row=0;
}

void show_display(){
    entradas = check_inputs();
    next_screen_row();

    if(game_mode == 0){
        SPI_send(~(1 << count_row));
        SPI_send(icons[2][count_row]);
        SPI_send(icons[2][count_row]);

        SPI_send((uint8_t)(entradas>>8));
        SPI_send((uint8_t)entradas);

        latch();
    }
    
    if(game_mode == 1 && animation_active == 0 ){
        
        SPI_send(~(1 << count_row));
        SPI_send(numbers[random_number][1][count_row]);
        SPI_send(numbers[random_number][0][count_row]);

        SPI_send((uint8_t)(entradas>>8));
        SPI_send((uint8_t)entradas);

        latch();
    }

    if(game_mode == 2){
        uint8_t current_input_count = count_active(entradas);
        
        SPI_send(~(1 << count_row));
        SPI_send(numbers[current_input_count][1][count_row]);
        SPI_send(numbers[current_input_count][0][count_row]);

        SPI_send((uint8_t)(entradas>>8));
        SPI_send((uint8_t)entradas);

        latch();
    }

    if(animation_active == 1){
        SPI_send(~(1 << count_row));
        SPI_send(numbers[9 - animation_number][1][count_row]);
        SPI_send(numbers[animation_number][1][count_row]);
        
        SPI_send((uint8_t)(entradas>>8));
        SPI_send((uint8_t)entradas);
        
        latch();
    }

    if(animation_active == 2){
        SPI_send(~(1 << count_row));

        if(result == 1){
            SPI_send(icons[0][count_row]);
            SPI_send(digits[10][count_row]);
        }
        else if (result == 2){
            SPI_send(icons[1][count_row]);
            SPI_send(digits[10][count_row]);
        }

        SPI_send((uint8_t)(entradas>>8));
        SPI_send((uint8_t)entradas);
        
        latch();
    }
}