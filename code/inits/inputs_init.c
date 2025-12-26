#include <avr/io.h>

void inputs_init(){
    //set PC0, PC1, PC2, PC3 as inputs
    DDRC &= ~((1 << PC0) | (1 << PC1) | (1 << PC2) | (1 << PC3));

    // TEMPORAL !!!!!!!!!!!!
    DDRD = 0b00000011;

    //pull-up resistors
    PORTC |= (1 << PC0) | (1 << PC1) | (1 << PC2) | (1 << PC3);

    PCICR |= (1 << PCIE1);
    PCMSK1 |= (1 << PC0) | (1 << PC1) | (1 << PC2) | (1 << PC3);
}