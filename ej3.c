#include "color.h"

void main() {
	int i, filas, columnas, f,c;
	borrar_pantalla();
	posicion(1,1);
	filas = max_filas();
	columnas = max_columnas();
	printf("Pulsa INTRO 10 veces");
	f = filas/2; c = columnas/2;
	for(i = 1 ; i <= 10 ; i++) {
		scanf("%*c");
		posicion(f,c);
		printf("%d",i);
		f = (f * f)%filas + 1;
		c = (c*c)%columnas + 1;
	}
}
