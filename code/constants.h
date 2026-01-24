// Definiciones de pines
#define DDR_SPI  DDRB
#define DD_MISO  PB4
#define DD_SCK   PB5
#define DD_MOSI    PB3 // El pin SS debe ser salida para modo Master
#define PL_PIN   PB2  // Pin para Parallel Load
#define LATCH_PIN   PB1  // Pin para Parallel Load

#define ANIMATION_DELAY 90 // Miliseconds for animation steps
#define ANIMATION_DURATION 1000 // How much Animation lasts
#define DEBOUNCE_DURATION 70 // Miliseconds for button debounce
#define RESULT_DURATION 1500 // Miliseconds to show result before next level

#define START_AUDIO 17 // Track to play when starting a game
#define EASY_MODE_AUDIO 18
#define HARD_MODE_AUDIO 19
#define PRACTICE_MODE_AUDIO 20
#define SUCCESS_AUDIO 21 // Track to play on success
#define FAILURE_AUDIO 22 // Track to play on failure