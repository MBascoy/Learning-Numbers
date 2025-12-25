#include <avr/io.h>

void SPI_send(uint8_t data) {
    SPDR = data;                     // Cargar dato en el registro de SPI
    while (!(SPSR & (1 << SPIF)));   // Esperar que termine la transmisión
}