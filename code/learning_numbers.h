void init_timers();
void latch();
void SPI_send(uint8_t data);
uint16_t check_inputs();
uint8_t count_active();

void SPI_init();

uint16_t read_74HC165();

void inputs_init();

int get_random(int a, int b);

void set_new_level();

void show_display();