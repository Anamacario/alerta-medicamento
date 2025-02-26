 #include <stdio.h>
#include "ssd1306.h"
#include "hardware/i2c.h"
#include "font.h"

void ssd1306_init(ssd1306_t *display, int width, int height, i2c_inst_t *i2c_port, uint8_t addr) {
    display->width = width;
    display->height = height;
    display->i2c_port = i2c_port;
    display->address = addr;

    // Sequência de inicialização do SSD1306
    uint8_t init_cmds[] = {
        0xAE, 0xD5, 0x80, 0xA8, height - 1,
        0xD3, 0x00, 0x40, 0x8D, 0x14,
        0x20, 0x00, 0xA1, 0xC8, 0xDA, 0x12,
        0x81, 0xCF, 0xD9, 0xF1, 0xDB, 0x40,
        0xA4, 0xA6, 0xAF
    };
    i2c_write_blocking(display->i2c_port, display->address, init_cmds, sizeof(init_cmds), false);
}

void ssd1306_clear(ssd1306_t *display) {
    uint8_t clear_screen[1025] = {0};
    clear_screen[0] = 0x40; // Comando para enviar dados gráficos
    i2c_write_blocking(display->i2c_port, display->address, clear_screen, sizeof(clear_screen), false);
}

void ssd1306_draw_char(ssd1306_t *display, char c, int x, int y) {
    if (c < ' ' || c > 'z') return;  // Ignora caracteres fora do intervalo ASCII

    int char_index = (c - ' ') * 8;  // Cada caractere ocupa 8 bytes na tabela

    uint8_t buffer[9];
    buffer[0] = 0x40;  // Comando para enviar dados gráficos

    for (int i = 0; i < 8; i++) {
        buffer[i + 1] = font[char_index + i];
    }

    i2c_write_blocking(display->i2c_port, display->address, buffer, sizeof(buffer), false);
}

void ssd1306_draw_string(ssd1306_t *display, const char *message, int x, int y) {
    while (*message) {
        ssd1306_draw_char(display, *message, x, y);
        x += 8;  // Move para a próxima posição horizontal
        message++;
    }
}
void ssd1306_update(ssd1306_t *display) {
    // Se necessário, pode-se enviar um comando extra para atualizar a tela.
    printf("DISPLAY ATUALIZADO\n");
}

/*
#include <stdio.h>
#include "ssd1306.h"
#include "hardware/i2c.h"
#include "font.h"

void ssd1306_init(ssd1306_t *display, int width, int height, i2c_inst_t *i2c_port, uint8_t addr) {
    display->width = width;
    display->height = height;
    display->i2c_port = i2c_port;
    display->address = addr;

    // Sequência de inicialização corrigida
    uint8_t init_cmds[] = {
        0xAE,        // Desliga o display
        0xD5, 0x80,  // Ajuste do clock
        0xA8, height - 1,
        0xD3, 0x00,  // Deslocamento vertical
        0x40,        // Linha inicial
        0x8D, 0x14,  // Habilita bomba de carga
        0x20, 0x00,  // Modo de endereçamento horizontal
        0xA1,        // Inversão horizontal
        0xC8,        // Inversão vertical
        0xDA, 0x12,  // Configuração de hardware
        0x81, 0x7F,  // Contraste
        0xD9, 0xF1,  // Ajuste da pré-carga
        0xDB, 0x40,  // Ajuste do nível de descarregamento
        0xA4,        // Ativa exibição normal
        0xA6,        // Modo normal (não invertido)
        0xAF         // Liga o display
    };
    i2c_write_blocking(display->i2c_port, display->address, init_cmds, sizeof(init_cmds), false);
}

void ssd1306_clear(ssd1306_t *display) {
    uint8_t clear_screen[1025] = {0};
    clear_screen[0] = 0x40; // Comando para enviar dados gráficos
    i2c_write_blocking(display->i2c_port, display->address, clear_screen, sizeof(clear_screen), false);
}

// Corrigida para exibir texto corretamente
/*void ssd1306_draw_char(ssd1306_t *display, int x, int y, char c) {
    if (c < ' ' || c > 'z') return;  // Ignora caracteres fora do intervalo ASCII
    int char_index = (c - ' ') * 8;  // Cada caractere ocupa 8 bytes na tabela

    uint8_t buffer[9];
    buffer[0] = 0x40;  // Comando para enviar dados gráficos

    for (int i = 0; i < 8; i++) {
        buffer[i + 1] = font[char_index + i];
    }

    i2c_write_blocking(display->i2c_port, display->address, buffer, sizeof(buffer), false);
}*/
/*void ssd1306_draw_char(ssd1306_t *display, int x, int y, char c) {
    if (c < ' ' || c > 'z') return;  // Ignora caracteres fora do intervalo ASCII

    int char_index = (c - ' ') * 5;  // Ajuste correto para fonte 5x7
    uint8_t buffer[6];  
    buffer[0] = 0x40;  // Comando para enviar dados gráficos

    for (int i = 0; i < 5; i++) {  
        buffer[i + 1] = font5x7[char_index + i];  // Obtém os bytes corretos da fonte
    }

    i2c_write_blocking(display->i2c_port, display->address, buffer, sizeof(buffer), false);
}

// Corrigida para iterar sobre os caracteres corretamente
void ssd1306_draw_string(ssd1306_t *display, int x, int y, const char *message) {
    while (*message) {
        if (x + 6 >= display->width) {  // Se ultrapassar a largura do display, pula para a próxima linha
            x = 0;
            y += 8;
        }
        if (y + 8 >= display->height) {  // Se ultrapassar a altura, para
            break;
        }

        ssd1306_draw_char(display, *message, x, y);
        x += 6;  // Ajustado para largura real do caractere
        message++;
    }
    ssd1306_update(display);  // Atualiza o display somente após desenhar todas as letras
}

void ssd1306_update(ssd1306_t *display) {
    printf("DISPLAY ATUALIZADO\n");
}
*/