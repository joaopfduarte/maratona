#include <stdio.h>

long long int recursiva (int k, int n);

int main() {
    int t;
    scanf("%d", &t);
    
    int k = 0, n = 0;
    long long int resultado = 0;
    while (t--) {
        scanf("%d %d", &k, &n);
        resultado = recursiva(k, n);
        printf("lld\n", resultado);
    }
    return 0;
}

long long int recursiva (int k, int n) {
    long long int resultado = 0;

    long long int vetor[k];
    for (int i = 0; i < k; i++) {vetor[i] = 1;}
    long long int acumulador[n];
    for (int i = 0; i < k; i++) {acumulador[k] = 1;}

    long long int a = 0,b = 0,c = 0;
    for (int i = 0; i < n; i++) {


    }

    return resultado; 
}

