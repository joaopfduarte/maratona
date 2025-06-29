#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double pitagoras (int a, int b, int c);

int main() {
    int a = 2; int b = 2; int c = 2;
    double valor = 0;

    while(a != 0) {
        scanf("%d %d %d", &a, &b, &c);

        if ((a == 0) && (b == 0) && (c == 0)) {goto prox;}

        valor = pitagoras(a, b, c);

        if (valor == (int) valor) {printf("%.0f\n", valor);}
        else{
            double numTrunc = (int)(valor*1000)/1000.0;
            printf("%.3lf\n", numTrunc);
        }
    }
prox:

    exit(0);
    return 0;
}

double pitagoras (int a, int b, int c) {
    double valor = 0.0;

    if (a == -1) {
        valor = sqrt((c*c) - (b*b));        
    } else if (b == -1) {
        valor = sqrt((c*c) - (a*a));
    } else {
        valor = sqrt((a*a) + (b*b));
    }
    return valor;
}
