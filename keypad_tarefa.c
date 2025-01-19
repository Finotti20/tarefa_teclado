#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"
#include "hardware/clocks.h"

// Definições das portas GPIO dos LEDs
#define GREEN_LED_PIN 11
#define BLUE_LED_PIN 12
#define RED_LED_PIN 13

// Definição da porta GGPIO do BUZZER
#define BUZZER_PIN 21

// Define os GPIOs para as linhas e colunas do teclado matricial 4x4
#define ROWS 4
#define COLS 4

// Mapear GPIOs para linhas e colunas
const uint8_t row_pins[ROWS] = {8, 7, 6, 5};
const uint8_t col_pins[COLS] = {4, 3, 2, 1};

// Matriz de teclas
const char key_map[ROWS][COLS] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}
};

// Inicializa as linhas como saída e colunas como entrada
void init_gpio() {
    
    for (int i = 0; i < ROWS; i++) {
        gpio_init(row_pins[i]);
        gpio_set_dir(row_pins[i], GPIO_OUT);
        gpio_put(row_pins[i], 1); // Linha inicialmente em HIGH
    }
    for (int i = 0; i < COLS; i++) {
        gpio_init(col_pins[i]);
        gpio_set_dir(col_pins[i], GPIO_IN);
        gpio_pull_up(col_pins[i]); // Ativa pull-up nas colunas
    }
}

// Verifica qual tecla foi pressionada
char scan_keypad()
{
    for (int row = 0; row < ROWS; row++)
    {
        gpio_put(row_pins[row], 0); // Configura a linha atual como LOW
        for (int col = 0; col < COLS; col++)
        {
            if (gpio_get(col_pins[col]) == 0)
            {
                while (gpio_get(col_pins[col]) == 0)
                    ;
                gpio_put(row_pins[row], 1);
                return key_map[row][col];
            }
        }
        gpio_put(row_pins[row], 1); // Restaura a linha para HIGH
    }
    return '\0';
}


void set_buzzer_frequency(uint pin, uint frequency) {
     // Obter o slice do PWM associado ao pino
     uint slice_num = pwm_gpio_to_slice_num(pin);

     // Configurar o pino como saída de PWM
     gpio_set_function(pin, GPIO_FUNC_PWM);
     
     // Configurar o PWM com frequência desejada
     pwm_config config = pwm_get_default_config();
     pwm_config_set_clkdiv(&config, clock_get_hz(clk_sys) / (frequency * 4096)); // Calcula divisor do clock
     pwm_init(slice_num, &config, true);
     pwm_set_gpio_level(pin, 0); // Inicializa com duty cycle 0 (sem som)
}

void play_buzzer(uint pin, uint frequency, uint duration_ms){

    set_buzzer_frequency(pin, frequency);
    pwm_set_gpio_level(pin, 2048);
    sleep_ms(duration_ms);
    pwm_set_gpio_level(pin, 0);
}