#include <avr/io.h>
#include <avr/interrupt.h>

#include "../learning_numbers.h"
#include "../common/globals.h"

uint16_t timer0_counter = 0;

ISR(TIMER1_COMPA_vect) {

    if(game_mode != 0 && (delay_mode == 0 || delay_mode==2) ){
            entradas = check_inputs();
            // Aquí 'entradas' contiene el estado de los 8 switches

            count_row++;
            if(count_row >= 8)
                count_row=0;

            SPI_send(~(1 << count_row));
            SPI_send(numbers[random_number][1][count_row]);
            SPI_send(numbers[random_number][0][count_row]);


            SPI_send((uint8_t)(entradas>>8));
            SPI_send((uint8_t)entradas);

            latch();

            //PORTD=count_active(entradas);
    }
    if(delay_mode == 1){
        count_row++;
        if(count_row >= 8)
            count_row=0;

        SPI_send(~(1 << count_row));
        SPI_send(numbers[9 - animation_number][1][count_row]);
        SPI_send(numbers[animation_number][1][count_row]);
        SPI_send(0); //Dummy bytes
        SPI_send(0);
        latch();
    }
}

ISR(TIMER0_COMPA_vect) {

    if(delay_mode != 0)
        timer0_counter++;

    if(delay_mode == 1 && timer0_counter%50 == 0){
        animation_number++;
        if (animation_number == 10){
            animation_number = 0;
        }
    }

    if(delay_mode != 0 && timer0_counter == 2000){
        timer0_counter = 0;
        delay_mode = 0;
        random_number= get_random(1, 5);
    }
}