#include "color.h"

void dibuja_bmp(int posF, int posC, char *desc) {
	int f = posF, c = posC;
	int i = 0;
	while(desc[i] != '\0') {
		if(desc[i] == '\n') {
			f++; c = posC;
		} else {
			if(desc[i] == ' ') color_fondo(NEGRO);
			else if(desc[i] == 'R') color_fondo(ROJO);
			else if(desc[i] == 'V') color_fondo(VERDE);
			else if(desc[i] == 'M') color_fondo(MARRON);
			else if(desc[i] == 'C') color_fondo(CIAN);
			else if(desc[i] == 'A') color_fondo(AZUL);
			else if(desc[i] == 'G') color_fondo(MAGENTA);
			else if(desc[i] == 'B') color_fondo(BLANCO);
			posicion(f,c);
			printf(" ");
			c++;			
		}
		i++;
	}	
	color_fondo(NEGRO);
}

void main() {
	dibuja_bmp(1,1,
		"              \n"
		"    VVVVV     \n"
		"   VVVVVVVVVV \n"
		"   RRRMMRM    \n"
		"  RMRMMMRMMM  \n"
		"  RMRRMMMRMMM \n"
		"  RRMMMMRRRR  \n"
		"    MMMMMMM   \n"
		"   RRVRRR     \n"
		"  RRRVRRVRRR  \n"
		" RRRRVVVVRRRR \n"
		" MMRVMVVMVRMM \n"
		" MMMVVVVVVMMM \n"
		" MMVVVVVVVVMM \n"
		"   VVV  VVV   \n"
		"  RRR    RRR  \n"
		" RRRR    RRRR \n"
		"              ");
	printf("\n\n\n");
	
}
