void init_timer1();
void latch();
void SPI_send(uint8_t data);
uint16_t check_inputs();
uint8_t count_active();

void SPI_init();

uint16_t read_74HC165();

void inputs_init();