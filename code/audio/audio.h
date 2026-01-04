// Comandos de alto nivel para el DFPlayer
#define DFPLAYER_PLAY_TRACK     0x03
#define DFPLAYER_STOP           0x16
#define DFPLAYER_SET_VOLUME     0x06
#define DFPLAYER_INIT           0x0C // Initialize (reset)

extern unsigned char dfplayer_command[10];

void uart_init();

void dfplayer_send_command(unsigned char command, unsigned int param);

void dfplayer_play_track(unsigned int track_number);

void dfplayer_set_volume(unsigned char volume);