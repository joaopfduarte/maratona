#include <stdio.h>

int main() {
	int a = 0; int b = 0; int c = 0; int d = 0;
	scanf("%d %d %d %d", &a, &b, &c, &d);

	int soma = (a + b + c + d) - 3;

	printf("%d\n", soma);
	return 0;
}
