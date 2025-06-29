#include <stdio.h>
#include <stdlib.h>

int main(){

    int n = 0;
    scanf("%d", &n);

    if (n % 2 != 0){exit(0);}
    
    int tamanho[n];
    char pe[n];
    int usado[n];

    for (int i = 0; i < n; i++) {usado[i] = 0;}

    for (int i = 0; i < n; i++) {
        scanf("%d", &tamanho[i]);
        scanf(" %c", &pe[i]);
    //    printf("Lido: %d %c\n", tamanho[i], pe[i]);
    }

    int contador = 0;

    for (int j = 0; j < n; j++) {
        if (usado[j]) {continue;}
        
        for(int i = j + 1; i < n; i++) {
            if((!usado[i]) &&(tamanho[j] == tamanho[i]) && (pe[j] != pe[i])){
                usado[j] = 1;
                usado[i] = 1;
                contador++;
                break;
            }
        }

    }
    
    printf("%d\n", contador);    

    return 0;
}
