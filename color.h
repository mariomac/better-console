#include<sys/ioctl.h>
#include<stdio.h>

#define NEGRO 0
#define ROJO 1
#define VERDE 2
#define MARRON 3
#define AZUL 4
#define MAGENTA 5
#define CIAN 6
#define BLANCO 7

#define FG_INDEX 30
#define BG_INDEX 40

// http://man7.org/linux/man-pages/man4/console_codes.4.html
void borrar_pantalla() {
	printf("\033[2J");
}

void posicion(int fila, int col) {
	printf("\033[%d;%dH",fila,col);
}

void color(int col) {
	printf("\033[%dm",col+FG_INDEX);
}

void color_fondo(int col) {
	printf("\033[%dm",col+BG_INDEX);
}

void colorrva(int r, int g, int b) {
    printf("\033[38;2;255;255;1m");
}

int max_filas() {
    struct winsize w;
    ioctl(0, TIOCGWINSZ, &w);
    return w.ws_row;
}

int max_columnas() {
    struct winsize w;
    ioctl(0, TIOCGWINSZ, &w);
    return w.ws_col;
}