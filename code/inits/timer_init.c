#include <avr/interrupt.h>

void init_timers() {
    //TIMER 1
    TCCR1B |= (1 << WGM12); // Modo CTC
    TCCR1B |= (1 << CS11) | (1 << CS10); // Prescaler 1024

    TIMSK1 |= (1 << OCIE1A); // Habilitar interrupción por OCR1A

    OCR1A = 50;

    //TIMER 0
    TCCR0A |= (1 << WGM01);
    TCCR0B |= (1 << CS02); // Prescaler de 256
    TIMSK0 |= (1 << OCIE0A);
    OCR0A = 4; // Interrupción cada 1 milisegundo

    sei();
}