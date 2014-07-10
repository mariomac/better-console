#include "color.h"

void main() {
	printf("Pulsa INTRO para borrar pantalla");
	scanf("%*c");
	borrar_pantalla();
	printf("Pantalla borrada. Pulsa INTRO para salir");
	scanf("%*c");	
}