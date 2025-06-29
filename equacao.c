#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void calculadora(int a, int b, int c);

int main () {

    int a = 0; int b = 0; int c = 0;

    while (scanf("%d %d %d", &a, &b, &c) == 3){

        if (a != 0) {
            calculadora(a,b,c);
        } else {
            printf("Nao e uma equacao de grau 2\n"); 
        }
    }
    return 0;
}    

void calculadora(int a, int b, int c){
    double raiz1, raiz2;
    double delta = b*b -4*a*c;

    if (delta > 0) {

        raiz1 = (-b + sqrt(delta)) / (2.0 * a);
        raiz2 = (-b -sqrt(delta)) / (2.0 * a);

        /*if (raiz1 < raiz2) {
            double temp = raiz1;
            raiz1 = raiz2;
            raiz2 = temp;
        }*/

        printf("Equacao: %d(x2) + %d(x) + %d\n", a, b, c);
        printf("Solucao com 2 raizes reais\n");
        printf("X1: %.1f\n", raiz1);
        printf("X2: %.1f\n", raiz2);
    } else if (delta == 0) {

        raiz1 = -b / (2.0 * a);

        printf("Equacao: %d(x2) + %d(x) + %d\n", a, b, c);
        printf("Solucao com 1 raiz real\n");
        printf("X1: %.1f\n", raiz1);
    } else {
        printf("Equacao: %d(x2) + %d(x) + %d\n", a, b, c);
        printf("Solucao com 0 raizes reais\n");
        printf("X1: Nao existe raiz real\n");
    }
}
