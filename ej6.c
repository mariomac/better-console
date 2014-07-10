#include "color.h"
#define MAX 16

int main() {
	int x, y,t;
	borrar_pantalla();
	for(t = 0 ; t < 6 ; t++) {
		for(x = 1 ; x <= max_columnas() ; x++) {
			for(y = 1 ; y <= max_filas() ; y++) {
				color_fondo(rva((double)t/(double)6,
						(double)x/(double)max_columnas(),
						(double)y/(double)max_filas()
					));
				posicion(y,x);
				printf(" ");
			}			
		}
		scanf("%*c");
	}
	

	
	return 0;
}
