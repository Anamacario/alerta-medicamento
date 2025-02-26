/* #include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/i2c.h"
#include "hardware/pwm.h"
#include "inc/display_ssd1306.h"

// Definição dos pinos
#define LED 13
#define BUZZER 21
#define BOTAO 5

void ativar_alarme() {
    printf(" Hora do medicamento! \n");
    displayMensagem("Tome o remedio!");
    gpio_put(LED, 1);
    gpio_set_function(BUZZER, GPIO_FUNC_PWM);
    uint slice_num = pwm_gpio_to_slice_num(BUZZER);
    
    pwm_config config = pwm_get_default_config();
    pwm_config_set_clkdiv(&config, 4.0f);
    pwm_config_set_wrap(&config, 2500);
    pwm_init(slice_num, &config, true);
    
    pwm_set_gpio_level(BUZZER, 1250);
}

void desativar_alarme() {
    printf(" Medicamento confirmado!\n");
    displayMensagem("Remedio tomado!");
    
    gpio_put(LED, 0);
    uint slice_num = pwm_gpio_to_slice_num(BUZZER);
    pwm_set_enabled(slice_num, false);
}

void esperar_confirmacao() {
    while (1) {
        if (gpio_get(BOTAO) == 0) {
            desativar_alarme();
            break;
        }
        sleep_ms(100);
    }
}

int main() {
    stdio_init_all();
    gpio_init(LED);
    gpio_set_dir(LED, GPIO_OUT);

    gpio_init(BUZZER);
    gpio_set_dir(BUZZER, GPIO_OUT);

    gpio_init(BOTAO);
    gpio_set_dir(BOTAO, GPIO_IN);
    gpio_pull_up(BOTAO);

   displayInit(); 

   
    printf("Sistema iniciado. Aguardando horário do alarme...\n");

    sleep_ms(5000);
    ativar_alarme();

    esperar_confirmacao();

    printf("Sistema finalizado.\n");
    return 0;
}*/

/* #include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/i2c.h"
#include "hardware/pwm.h"
#include "inc/display_ssd1306.h"

// Definição dos pinos
#define LED 13
#define BUZZER 21
#define BOTAO 5

/*void ativar_alarme() { o segundo certo
    printf("Hora do medicamento!\n");
    exibirAlertaMedicamento();  // Exibe "Hora do Remédio!"

    gpio_put(LED, 1);
    gpio_set_function(BUZZER, GPIO_FUNC_PWM);
    uint slice_num = pwm_gpio_to_slice_num(BUZZER);
    
    pwm_config config = pwm_get_default_config();
    pwm_config_set_clkdiv(&config, 4.0f);
    pwm_config_set_wrap(&config, 2500);
    pwm_init(slice_num, &config, true);
    
    pwm_set_gpio_level(BUZZER, 1250);
}

void desativar_alarme() {
    printf("Medicamento confirmado!\n");
    exibirConfirmacao();  // Exibe "Ingestão Confirmada!"

    gpio_put(LED, 0);
    uint slice_num = pwm_gpio_to_slice_num(BUZZER);
    pwm_set_enabled(slice_num, false);
}*//*
void ativar_alarme() {
    printf("Hora do medicamento!\n");

    // Exibir mensagem na tela
    ssd1306_clear(&oled);
    ssd1306_draw_string(&oled, "Tome o remedio!", 10, 20);
    ssd1306_update(&oled); // Atualiza a tela apenas uma vez

    gpio_put(LED, 1);
    gpio_set_function(BUZZER, GPIO_FUNC_PWM);
    uint slice_num = pwm_gpio_to_slice_num(BUZZER);
    
    pwm_config config = pwm_get_default_config();
    pwm_config_set_clkdiv(&config, 4.0f);
    pwm_config_set_wrap(&config, 2500);
    pwm_init(slice_num, &config, true);
    
    pwm_set_gpio_level(BUZZER, 1250);
}
void desativar_alarme() {
    printf("Medicamento confirmado!\n");

    // Exibir mensagem de confirmação
    ssd1306_clear(&oled);
    ssd1306_draw_string(&oled, "Ingestao confirmada", 10, 20);
    ssd1306_update(&oled); // Atualiza a tela apenas uma vez

    gpio_put(LED, 0);
    uint slice_num = pwm_gpio_to_slice_num(BUZZER);
    pwm_set_enabled(slice_num, false);
}


void esperar_confirmacao() {
    while (1) {
        if (gpio_get(BOTAO) == 0) {
            desativar_alarme();
            break;
        }
        sleep_ms(100);
    }
}

int main() {
    stdio_init_all();
    gpio_init(LED);
    gpio_set_dir(LED, GPIO_OUT);

    gpio_init(BUZZER);
    gpio_set_dir(BUZZER, GPIO_OUT);

    gpio_init(BOTAO);
    gpio_set_dir(BOTAO, GPIO_IN);
    gpio_pull_up(BOTAO);

    displayInit();  // Inicializa o display OLED

    printf("Sistema iniciado. Aguardando horário do alarme...\n");

    sleep_ms(5000);
    ativar_alarme();

    esperar_confirmacao();

    printf("Sistema finalizado.\n");
    return 0;
}
*/


#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/i2c.h"
#include "hardware/pwm.h"
#include "inc/display_ssd1306.h"

// Definição dos pinos
#define LED 13
#define BUZZER 21
#define BOTAO 5

/*void ativar_alarme() {
    printf("Hora do medicamento!\n");
    displayMensagem("Tome o remedio!");

    gpio_put(LED, 1);
    gpio_set_function(BUZZER, GPIO_FUNC_PWM);
    uint slice_num = pwm_gpio_to_slice_num(BUZZER);
    
    pwm_config config = pwm_get_default_config();
    pwm_config_set_clkdiv(&config, 4.0f);
    pwm_config_set_wrap(&config, 2500);
    pwm_init(slice_num, &config, true);
    
    pwm_set_gpio_level(BUZZER, 1250);
}
*/
void ativar_alarme() {
    printf("Hora do medicamento!\n");
    displayMensagem("Tome o remedio!");

    int i;
    for (i = 0; i < 10; i++) { // O LED piscará 10 vezes
        gpio_put(LED, 1);  // Liga o LED
        sleep_ms(500);     // Espera 500ms
        gpio_put(LED, 0);  // Desliga o LED
        sleep_ms(500);     // Espera 500ms
    }

    // Após piscar, manter o LED ligado até o usuário confirmar
    gpio_put(LED, 1);

    // Configuração do buzzer
    gpio_set_function(BUZZER, GPIO_FUNC_PWM);
    uint slice_num = pwm_gpio_to_slice_num(BUZZER);
    
    pwm_config config = pwm_get_default_config();
    pwm_config_set_clkdiv(&config, 4.0f);
    pwm_config_set_wrap(&config, 2500);
    pwm_init(slice_num, &config, true);
    
    pwm_set_gpio_level(BUZZER, 1250);
}

void desativar_alarme() {
    printf("Medicamento confirmado!\n");
    displayMensagem("Ingestao confirmada!");

    gpio_put(LED, 0);
    uint slice_num = pwm_gpio_to_slice_num(BUZZER);
    pwm_set_enabled(slice_num, false);
}


void esperar_confirmacao() {
    while (1) {
        if (gpio_get(BOTAO) == 0) {
            desativar_alarme();
            break;
        }
        sleep_ms(100);
    }
}

int main() {
    stdio_init_all();
    gpio_init(LED);
    gpio_set_dir(LED, GPIO_OUT);

    gpio_init(BUZZER);
    gpio_set_dir(BUZZER, GPIO_OUT);

    gpio_init(BOTAO);
    gpio_set_dir(BOTAO, GPIO_IN);
    gpio_pull_up(BOTAO);

    displayInit();  // Inicializa o display OLED

    printf("Sistema iniciado. Aguardando horário do alarme...\n");

    sleep_ms(5000);
    ativar_alarme();

    esperar_confirmacao();

    printf("Sistema finalizado.\n");
    return 0;
}
