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

    _delay_ms(1000); // Wait to DFPlayer to start

    // Poner volumen a 20 (de 0 a 30)
    dfplayer_set_volume(DEFAULT_VOLUME);
    _delay_ms(50);

    dfplayer_play_track(START_AUDIO);

    test_leds = 0;

    while(1) {
    }
}
