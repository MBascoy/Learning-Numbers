#include <avr/io.h>
#include <util/delay.h>
#include <util/setbaud.h>

#include "audio.h"

// Array que contendrá los 10 bytes del paquete de comando.
unsigned char dfplayer_command[10] = {0x7E, 0xFF, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xEF};

// Función para inicializar el UART
void uart_init(void) {
    // Configurar la velocidad de baudios
    UBRR0H = UBRRH_VALUE;
    UBRR0L = UBRRL_VALUE;

    // Habilitar el transmisor (TXEN0) y el receptor (RXEN0)
    UCSR0B = (1 << TXEN0) | (1 << RXEN0);

    // Formato: 8 bits de datos, sin paridad, 1 bit de parada
    UCSR0C = (1 << UCSZ01) | (1 << UCSZ00); // 8-bit data
}

// Función para enviar un byte a través del UART
void uart_transmit(unsigned char data) {
    // Esperar a que el buffer de transmisión esté vacío (UDRE0 = 1)
    while (!(UCSR0A & (1 << UDRE0)));

    // Poner los datos en el buffer y enviarlos
    UDR0 = data;
}

// Función para calcular e insertar el Checksum
void dfplayer_calculate_checksum() {
    // Usar uint16_t (o unsigned short) para garantizar 16 bits
    uint16_t sum = 0;

    // Sumar Bytes 2 a 7 (índices 1 a 6)
    for (int i = 1; i <= 6; i++) {
        // Al sumar, los bytes se promueven a int, pero la variable sum es segura.
        sum += dfplayer_command[i];
    }

    // Checksum = 0x10000 - sum
    uint16_t checksum = 0x10000 - sum; // La resta en complemento a dos es más simple

    // Insertar el Checksum en los bytes 8 y 9
    dfplayer_command[7] = (unsigned char)(checksum >> 8); // Byte Alto
    dfplayer_command[8] = (unsigned char)checksum;        // Byte Bajo
}

// Función para enviar el paquete de 10 bytes
void dfplayer_send_command(unsigned char command, unsigned int param) {
    // 1. Cargar los bytes específicos del comando
    dfplayer_command[3] = command;       // Código del comando
    dfplayer_command[5] = (unsigned char)(param >> 8); // Parámetro Alto
    dfplayer_command[6] = (unsigned char)param;        // Parámetro Bajo

    // 2. Calcular e insertar el Checksum
    dfplayer_calculate_checksum();

    // 3. Transmitir los 10 bytes del paquete
    for (int i = 0; i < 10; i++) {
        uart_transmit(dfplayer_command[i]);
    }
    _delay_ms(50); // Pequeña espera para que el módulo procese el comando
}

void dfplayer_play_track(unsigned int track_number) {
    // track_number: 1 a 255 (para archivos 0001.mp3 a 0255.mp3 en la carpeta /mp3/)
    dfplayer_send_command(DFPLAYER_PLAY_TRACK, track_number);
}

void dfplayer_set_volume(unsigned char volume) {
    // Enviar el comando 0x06 con el valor del volumen
    dfplayer_send_command(DFPLAYER_SET_VOLUME, (unsigned int)volume);
}