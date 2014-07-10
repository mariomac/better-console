#include "color.h"

int main() {
	int f,c,fa=0, ca=0;
	int ff,cc;
	borrar_pantalla();
	while(1) {
		f = max_filas(); c = max_columnas();
		if(fa != f || ca != c) {
			color_fondo(NEGRO);
			borrar_pantalla();
			color(AZUL); color_fondo(BLANCO);
			for(ff=1;ff<=f;ff++) {
				posicion(ff,1); printf("*");
				posicion(ff,c); printf("*");
			}
			for(cc=1;cc<=c;cc++) {
				posicion(1,cc); printf("*");
				posicion(f,cc); printf("*");
			}
			posicion(1,c/2-11);
			color(NEGRO);
			printf(" Demostracion consola ");
			color(MAGENTA); color_fondo(NEGRO);
			posicion(f/2-2,c/2-4);  printf("Prueba a");
			posicion(f/2-1,c/2-5);  printf("cambiar el");
			posicion(f/2,c/2-4); 	printf("tamaño de");
			posicion(f/2+1,c/2-6); 	printf("esta ventana");
			color(VERDE);
			posicion(f-1,2);
			printf("Tamaño ventana: %d x %d\n",f,c);
		}
		fa = f; ca = c;
	}
    return 0;
    	
}