#ifndef DISPLAY_SSD1306_H
#define DISPLAY_SSD1306_H

#include "hardware/i2c.h"
#include "ssd1306/ssd1306.h"
#include "hardware/gpio.h"


#define I2C_PORT i2c1
#define I2C_SDA 14
#define I2C_SCL 15
#define SSD1306_ADDRESS 0x3C

ssd1306_t oled;


void displayInit() {
    i2c_init(I2C_PORT, 400 * 1000);
    gpio_set_function(I2C_SDA, GPIO_FUNC_I2C);
    gpio_set_function(I2C_SCL, GPIO_FUNC_I2C);
    gpio_pull_up(I2C_SDA);
    gpio_pull_up(I2C_SCL);

    ssd1306_init(&oled, 128, 64, I2C_PORT, SSD1306_ADDRESS);
    ssd1306_clear(&oled);
    ssd1306_update(&oled);
}

void displayMensagem(const char *mensagem) {
    ssd1306_clear(&oled);
    ssd1306_draw_string(&oled, mensagem, 10, 20);
    ssd1306_update(&oled);
}

#endif


 /* segundo codigo
#ifndef DISPLAY_SSD1306_H
#define DISPLAY_SSD1306_H

#include "hardware/i2c.h"
#include "ssd1306/ssd1306.h"

#define I2C_PORT i2c1
#define I2C_SDA 14
#define I2C_SCL 15
#define SSD1306_ADDRESS 0x3C

ssd1306_t oled;

void displayInit() {
    i2c_init(I2C_PORT, 400 * 1000);
    gpio_set_function(I2C_SDA, GPIO_FUNC_I2C);
    gpio_set_function(I2C_SCL, GPIO_FUNC_I2C);
    gpio_pull_up(I2C_SDA);
    gpio_pull_up(I2C_SCL);

    ssd1306_init(&oled, 128, 64, I2C_PORT, SSD1306_ADDRESS);
    ssd1306_clear(&oled);
    ssd1306_update(&oled);
}

// Exibe uma mensagem na tela
void displayMensagem(const char *mensagem) {
    ssd1306_clear(&oled);
    ssd1306_draw_string(&oled, mensagem, 10, 20);
    ssd1306_update(&oled);
}

// Exibe "Hora do Remédio!"
void exibirAlertaMedicamento() {
    displayMensagem("Hora do Remedio!");
}

// Exibe "Ingestão Confirmada!"
void exibirConfirmacao() {
    displayMensagem("Remedio tomado!");
}

#endif
*/
/*
#ifndef DISPLAY_SSD1306_H
#define DISPLAY_SSD1306_H

#include "hardware/i2c.h"
#include "ssd1306/ssd1306.h"

#define I2C_PORT i2c1
#define I2C_SDA 14
#define I2C_SCL 15
#define SSD1306_ADDRESS 0x3C

ssd1306_t oled;

void displayInit() {
    i2c_init(I2C_PORT, 400 * 1000);
    gpio_set_function(I2C_SDA, GPIO_FUNC_I2C);
    gpio_set_function(I2C_SCL, GPIO_FUNC_I2C);
    gpio_pull_up(I2C_SDA);
    gpio_pull_up(I2C_SCL);

    ssd1306_init(&oled, 128, 64, I2C_PORT, SSD1306_ADDRESS);
    ssd1306_clear(&oled);
    ssd1306_update(&oled);
}

// Exibe uma mensagem corretamente formatada no display
void displayMensagem(const char *mensagem) {
    ssd1306_clear(&oled);
    ssd1306_draw_string(&oled, 10, 20, mensagem);  // Ajustado para usar a assinatura correta
    ssd1306_update(&oled);
}

#endif
*/