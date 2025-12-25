#include <avr/io.h>
#include "constants.h"

void latch() {
    // Pulso en LATCH para actualizar salidas
    PORTB |= (1 << LATCH_PIN);
    //_delay_us(1); // Opcional? descomentar en caso de que el latch no funcione
    PORTB &= ~(1 << LATCH_PIN);
}

uint16_t read_74HC165() {
    uint16_t data;

    // 1. Pulso en PL para cargar los datos paralelos
    PORTB &= ~(1 << PL_PIN);
    PORTB |= (1 << PL_PIN);

    // 2. Iniciar transmisión SPI (enviamos dummy data para recibir)
    SPDR = 0x00;

    // Esperar a que termine la transferencia
    while(!(SPSR & (1 << SPIF)));

    data = SPDR;

    // 2. Iniciar transmisión SPI (enviamos dummy data para recibir)
    SPDR = 0x00;

    // Esperar a que termine la transferencia
    while(!(SPSR & (1 << SPIF)));
    

    data = data | (uint16_t)SPDR << 8;

    return data;
}