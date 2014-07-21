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

#define BRILLO 8

#define GRISES 24
#define TONOSRGB 6

// http://man7.org/linux/man-pages/man4/console_codes.4.html
void borrar_pantalla() {
	printf("\033[2J");
}

void posicion(int fila, int col) {
	printf("\033[%d;%dH",fila,col);
}

void color(int col) {
	printf("\033[38;5;%dm",col);
}

void color_fondo(int col) {
	printf("\033[48;5;%dm",col);
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

int rva(double rojo, double verde, double azul) {
    int r = (int)(rojo * (TONOSRGB));
    if(r >= TONOSRGB) r = TONOSRGB-1;
    int g = (int)(verde * (TONOSRGB));
    if(g >= TONOSRGB) g = TONOSRGB-1;
    int b = (int)(azul * (TONOSRGB));
    if(b >= TONOSRGB) b = TONOSRGB-1;
    return 16 + b + g * TONOSRGB + r * TONOSRGB * TONOSRGB ;
}
int gris(double tono) {
    int col = (int) (tono * (GRISES+2));
    printf("%d",col);
    if(col == 0) {
        return 0;
    } else if(col >= GRISES+1) {
        return 255-GRISES;
    } else {
        return (col) + (255-GRISES);
    }
}