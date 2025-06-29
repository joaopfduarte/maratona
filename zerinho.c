#include <stdio.h>
#include <stdlib.h>

int main(){
	int a = 0; int b = 0; int c = 0;
	scanf("%d %d %d", &a, &b, &c);
	if ((a == b) && b == (c)) {printf("*\n"); exit(0);}

	//Verificação aninhada
	if ((a == b) && b != (c)) {printf("C\n"); exit(0);}
	if ((a == c) && c!= (b)) {printf("B\n"); exit(0);}
	if ((b == c) && c != (a)) {printf("A\n"); exit(0);}
	return 0;
}
