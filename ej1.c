#include "color.h"

void main() {
	color(AZUL); printf("Azul\n");
	color(ROJO); printf("Rojo\n");
	color(VERDE); printf("Verde\n");
	color(MARRON); printf("Marron\n");
	color(MAGENTA); printf("Magenta\n");
	color(CIAN); printf("Cian\n");
	color(BLANCO); printf("Blanco\n");
	color(ROJO); color_fondo(CIAN); printf("Rojo sobre cian\n");
	color_fondo(NEGRO); color(BLANCO);
}