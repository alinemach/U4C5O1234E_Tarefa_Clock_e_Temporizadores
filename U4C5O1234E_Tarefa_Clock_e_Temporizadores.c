#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"

// Definição dos pinos dos LEDs
#define LED_VERDE    11
#define LED_AZUL  12
#define LED_VERMELHO 13

// Variável para armazenar o estado do semáforo
volatile int estado = 0;

// Função de callback para o temporizador periódico
bool repeating_timer_callback(struct repeating_timer *t) {
    // Desliga todos os LEDs antes de ativar o próximo
    gpio_put(LED_VERMELHO, 0);
    gpio_put(LED_AZUL, 0);
    gpio_put(LED_VERDE, 0);

    // Alterna entre os estados do semáforo
    switch (estado) {
        case 0:  // Vermelho
            gpio_put(LED_VERMELHO, 1);
            printf("Semáforo: Vermelho\n");
            estado = 1;
            break;
        case 1:  // AMARELO
            gpio_put(LED_VERMELHO, 1);
            gpio_put(LED_VERDE, 1);
            printf("Semáforo: AMARELO\n");
            estado = 2;
            break;
        case 2:  // Verde
            gpio_put(LED_VERDE, 1);
            printf("Semáforo: Verde\n");
            estado = 0;
            break;
    }
    return true; // Retorna true para continuar o temporizador
}

int main() {
    stdio_init_all(); // Inicializa a comunicação serial

    // Configura os pinos dos LEDs como saída
    gpio_init(LED_VERMELHO);
    gpio_set_dir(LED_VERMELHO, GPIO_OUT);
    gpio_init(LED_AZUL);
    gpio_set_dir(LED_AZUL, GPIO_OUT);
    gpio_init(LED_VERDE);
    gpio_set_dir(LED_VERDE, GPIO_OUT);

    struct repeating_timer timer;
    
    // Configura um temporizador periódico de 3 segundos (3000ms)
    add_repeating_timer_ms(3000, repeating_timer_callback, NULL, &timer);

    // Loop principal imprimindo mensagens a cada segundo
    while (true) {
        printf("Sistema rodando...\n");
        sleep_ms(1000); // Aguarda 1 segundo
    }
}
