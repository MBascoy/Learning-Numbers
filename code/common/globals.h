uint16_t inputs_reset ;
uint16_t inputs_state;

uint8_t count_row;

uint8_t game_mode;
uint8_t animation_active;
uint8_t animation_number;
uint16_t entradas;

uint8_t result;

extern volatile uint8_t digits[][8];
extern volatile uint8_t icons[][8];
extern volatile uint8_t *numbers[][2];

volatile uint8_t random_number;
volatile uint8_t min_number;
volatile uint8_t max_number;

uint16_t timer0_counter;
