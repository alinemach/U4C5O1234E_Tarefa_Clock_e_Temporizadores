🚦 Semáforo com Temporizador Periódico no Raspberry Pi Pico

Este projeto implementa um semáforo utilizando um Raspberry Pi Pico W com temporização de 3 segundos para cada alteração de sinal (vermelho, amarelo, verde). O sistema alterna entre os sinais a cada 3 segundos utilizando a função add_repeating_timer_ms() da ferramenta Pico SDK.
📌 Requisitos

    Placa: Raspberry Pi Pico W
    Linguagem: C
    Bibliotecas:
        pico/stdlib.h
        hardware/timer.h
    Hardware:
        3 LEDs: Vermelho (GPIO 13), Verde (GPIO 11), Amarelo (GPIO 12)
        3 Resistores de 330 Ω
        Fios de conexão para os LEDs e resistores

⚙️ Funcionalidades

✅ Temporização de 3 segundos entre os estados do semáforo
✅ Estados do semáforo:

    Vermelho aceso sozinho
    Vermelho e Verde acesos (Amarelo)
    Verde aceso sozinho
    Reinício do ciclo
    ✅ Mudança de estado dos LEDs implementada na função de call-back do temporizador
    ✅ Impressão de informações a cada segundo via comunicação serial
    ✅ Controle com LEDs RGB (GPIO 11, 12, 13)

🚀 Como Executar

    Conectar os LEDs e resistores conforme a pinagem especificada:
        LED Vermelho: GPIO 13
        LED Amarelo: GPIO 12
        LED Verde: GPIO 11
        Resistores: 330Ω em série com cada LED

    Configuração do ambiente de desenvolvimento:
        Instalar o Pico SDK.
        Configurar o CMake para compilar o projeto.

    Compilar e carregar o código no Raspberry Pi Pico:
        Utilize o VSCode ou qualquer outro ambiente compatível com o Raspberry Pi Pico para compilar e carregar o código.

    Executar o programa:
        O semáforo inicia com o sinal vermelho aceso.
        A cada 3 segundos, ele alterna para os próximos estados (vermelho + verde, verde, e reinício).

🎥 Demonstração

🔗 Assista ao vídeo da simulação aqui (Substituir pelo link real)