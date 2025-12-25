#include <avr/interrupt.h>

void init_timer1() {
    TCCR1B |= (1 << WGM12); // Modo CTC
    TCCR1B |= (1 << CS12) | (1 << CS10); // Prescaler 1024

    TIMSK1 |= (1 << OCIE1A); // Habilitar interrupción por OCR1A

    OCR1A = 1;

    sei();
}
