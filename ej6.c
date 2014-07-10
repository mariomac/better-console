#include "color.h"
#define MAX 16

int main() {
	int x, y;
	borrar_pantalla();
	for(x = 1 ; x <= max_columnas() ; x++) {
		color_fondo(gris((double)x/(double)max_columnas()));
		for(y = 1 ; y <= 4 ; y++) {
			posicion(y,x);
			printf(" ");
		}
		printf("\n");
	}
	color_fondo(BLANCO|BRILLO);
	printf("                                                                       "
	"                                                                       "
	"                                                                       "
	"                                                                       "
	"                                                                       "
	"                                                                       "
	"                                                                       "
	"                                                                       "
	"\n");
	printf("\n");

	
	return 0;
}
