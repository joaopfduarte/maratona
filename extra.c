#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long int L = 0; 
    long long int C = 0; 
    long long int x = 0; 
    long long int y = 0;

    scanf("%lld %lld %lld %lld", &L, &C, &x, &y);

    if ((L == 0) && (C == 0)){exit(0);}

    if (x < 0 || x >= L || y < 0 || y >= C){exit(0);}

    /*if (((x + y) % 2) == 0) {
        printf("Direita\n");
    } else {
        printf("Esquerda\n");
    }*/

    int num = 0;
    for (int xi = 0; xi < L; xi++) {
        for (int yi = 0; yi < C; yi++){
            num++;
            if ((xi == x) && (yi == y)){goto fim;}
        }
    }

    fim:

    if (num % 2 == 0){printf("Esquerda\n");} else {printf("Direita\n");}
    
    return 0;
}
