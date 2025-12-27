# Configuración principal
MCU   = atmega168pa
F_CPU = 8000000UL
BAUD  = 9600UL

PROGRAMMER = usbasp

CC = avr-gcc
OBJCOPY = avr-objcopy
AVRDUDE = avrdude

# Carpeta de salida para el ejecutable
OUT_DIR = bin

CFLAGS = -mmcu=$(MCU) -DF_CPU=$(F_CPU) -DBAUD=$(BAUD) -Os -Wall
LDFLAGS = -mmcu=$(MCU)

# Archivos fuente y objetos
HELPERS = helpers/74hc165.c helpers/SPI.c helpers/input_functions.c helpers/random.c
INITS = inits/timer_init.c inits/SPI_init.c inits/inputs_init.c
INTERRUPTS = interrupts/input_interrupts.c interrupts/timer_interrupts.c
SRC = learning_numbers.c common/globals.c $(INITS) $(HELPERS) $(INTERRUPTS) display/display.c common/digits.c common/icons.c game/game.c
OBJ = $(SRC:.c=.o)

TARGET_NAME = learning_numbers
TARGET = $(OUT_DIR)/$(TARGET_NAME)

# Reglas de compilación
all: $(OUT_DIR) $(TARGET).hex

# Crear la carpeta bin si no existe
$(OUT_DIR):
	mkdir -p $(OUT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET).elf: $(OBJ)
	$(CC) $(LDFLAGS) -o $@ $^

$(TARGET).hex: $(TARGET).elf
	$(OBJCOPY) -O ihex -R .eeprom $< $@

# Flasheo al microcontrolador
flash: $(TARGET).hex
	$(AVRDUDE) -c $(PROGRAMMER) -p $(MCU) -U flash:w:$(TARGET).hex:i

# Limpieza: borra los .o repartidos y la carpeta bin/
clean:
	rm -f $(OBJ)
	rm -rf $(OUT_DIR)
