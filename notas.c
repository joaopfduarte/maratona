#include <stdio.h>

void avaliador (int nota);

int main(){
	int nota = 0;
	scanf("%d", &nota);
	avaliador(nota);
	return 0;
}

void avaliador (int nota) {
	if (nota != 0) {
		if ((nota >= 1) && (nota <= 35)){printf("D\n");}
		if ((nota >= 36) && (nota <= 60)){printf("C\n");}
		if ((nota >= 61) && (nota <= 85)){printf("B\n");}
		if ((nota >= 86) && (nota <= 100)){printf("A\n");}
	} else {printf("E\n");}

}
