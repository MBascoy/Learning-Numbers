#include <avr/io.h>
#include <avr/interrupt.h>

#include "../learning_numbers.h"
#include "../common/globals.h"

ISR(TIMER1_COMPA_vect) {

    if(game_mode != 0){
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
}
