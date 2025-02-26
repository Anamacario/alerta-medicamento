 #ifndef SSD1306_H
#define SSD1306_H

#include <stdint.h>
#include "hardware/i2c.h"

typedef struct {
    int width;
    int height;
    uint8_t address;
    i2c_inst_t *i2c_port;
} ssd1306_t;

// Inicializa o display
void ssd1306_init(ssd1306_t *display, int width, int height, i2c_inst_t *i2c_port, uint8_t addr);

// Limpa a tela
void ssd1306_clear(ssd1306_t *display);

// Escreve um caractere na tela
void ssd1306_draw_char(ssd1306_t *display, char c, int x, int y);

// Escreve uma string na tela
void ssd1306_draw_string(ssd1306_t *display, const char *message, int x, int y);

// Atualiza a tela
void ssd1306_update(ssd1306_t *display);

#endif
/*

#ifndef SSD1306_H
#define SSD1306_H

#include <stdint.h>
#include "hardware/i2c.h"

// Estrutura do display
typedef struct {
    int width;
    int height;
    uint8_t address;
    i2c_inst_t *i2c_port;
} ssd1306_t;

// Inicializa o display
void ssd1306_init(ssd1306_t *display, int width, int height, i2c_inst_t *i2c_port, uint8_t addr);

// Limpa o display
void ssd1306_clear(ssd1306_t *display);

// Exibe um único caractere na tela
void ssd1306_draw_char(ssd1306_t *display, int x, int y, char c);

// Exibe uma string na tela
void ssd1306_draw_string(ssd1306_t *display, int x, int y, const char *message);

// Atualiza a tela
void ssd1306_update(ssd1306_t *display);

#endif
*/