#include <avr/io.h>
#include "../constants.h"

void SPI_init() {
    // Configura MISO como entrada, SCK, SS y PL como salida
    DDR_SPI |= (1 << DD_SCK) | (1 << DD_MOSI) | (1 << PL_PIN) | (1 << LATCH_PIN);
    DDR_SPI &= ~(1 << DD_MISO);

    // Habilita SPI, Modo Maestro, Velocidad fck/16
    SPCR = (1 << SPE) | (1 << MSTR) | (1 << SPR0);
}