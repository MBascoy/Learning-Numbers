#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <avr/power.h>

#include "constants.h"
#include "learning_numbers.h"
#include "common/globals.h"
#include "audio/audio.h"

int main(void) {
    clock_prescale_set(clock_div_1);

    uart_init();

    SPI_init();

    inputs_init();
    
    init_timers();


    // 2. Enviar comandos de inicialización y configuración

    // Reiniciar/Inicializar el módulo
    dfplayer_send_command(DFPLAYER_INIT, 0);
    _delay_ms(1000); // Esperar que el reset termine

    // Poner volumen a 20 (de 0 a 30)
    dfplayer_set_volume(15);
    _delay_ms(50);

    // 3. Reproducir el archivo 0001.mp3 de la carpeta /mp3/
    dfplayer_play_track(1);

    while(1) {
    }
}
