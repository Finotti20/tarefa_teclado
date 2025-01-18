#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h" 
#include "hardware/clocks.h" 
 
// Definições das portas GPIO dos LEDs 
#define GREEN_LED_PIN 11 
#define BLUE_LED_PIN 12 
#define RED_LED_PIN 13 
 
//Definição da porta GGPIO do BUZZER 
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
