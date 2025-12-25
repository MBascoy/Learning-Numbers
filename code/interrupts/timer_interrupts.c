#include <avr/io.h>
#include <avr/interrupt.h>

#include "learning_numbers.h"
#include "../common/globals.h"

#include "../common/digits.h"

volatile uint8_t *numbers[][2] =
    {
        {digits[10], digits[0]},
        {digits[10], digits[1]},
        {digits[10], digits[2]},
        {digits[10], digits[3]},
        {digits[10], digits[4]},
        {digits[10], digits[5]},
        {digits[10], digits[6]},
        {digits[10], digits[7]},
        {digits[10], digits[8]},
        {digits[10], digits[9]},
        {digits[1], digits[0]},
        {digits[1], digits[1]},
        {digits[1], digits[2]},
        {digits[1], digits[3]},
        {digits[1], digits[4]},
        {digits[1], digits[5]},
        {digits[1], digits[6]},
    };

ISR(TIMER1_COMPA_vect) {

        entradas = check_inputs();
        // Aquí 'entradas' contiene el estado de los 8 switches

        count_row++;
        if(count_row >= 8)
            count_row=0;

        SPI_send(~(1 << count_row));
        SPI_send(numbers[12][1][count_row]);
        SPI_send(numbers[12][0][count_row]);


        SPI_send((uint8_t)(entradas>>8));
        SPI_send((uint8_t)entradas);

        latch();

        //PORTD=count_active(entradas);
}
