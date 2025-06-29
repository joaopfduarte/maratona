#include <stdio.h>
#include <stdlib.h>

int somador(int n);
int main()
{
    int tamanho = 0;
    scanf("%d", &tamanho);

    int final = somador(tamanho);
     
    printf("%d\n", final);
    return 0;
}

int somador(int n) {
    int matriz[n][n];

    for(int j = 0; j < n; j++) {
        for(int i = 0; i < n; i++) {
            matriz[j][i] = 0;
        }
    }

    int sum = 0;
    for(int j = 0; j < n; j++) {
        for(int i = 0; i < n; i++) {
            scanf("%d", &matriz[j][i]);
            sum += matriz[j][i];
        }
    }

    int sumTotalLinear[n];
    int sumTotalHorizontal[n];
    
    for(int k = 0; k < n; k++) {
        sumTotalLinear[k] = 0;
        sumTotalHorizontal[k] = 0;
    }

    for(int i = 0; i < n; i++) {
        int sumLinha = 0, sumColuna = 0;
        
        for(int j = 0; j < n; j++) {
            sumLinha += matriz[i][j];   
            sumColuna += matriz[j][i];  
        }
        
        sumTotalLinear[i] = sumLinha;
        sumTotalHorizontal[i] = sumColuna;
    }

    int somaPadrao = sumTotalLinear[0];
    for(int i = 0; i < n; i++) {
        if(sumTotalLinear[i] != somaPadrao || sumTotalHorizontal[i] != somaPadrao) {
            return -1;
        }
    }

    int diagPrincipal = 0, diagSecundaria = 0;
    for(int j = 0; j < n; j++) {
        diagPrincipal += matriz[j][j];
        diagSecundaria += matriz[j][n - 1 - j];
    }

    return (diagPrincipal == somaPadrao && diagSecundaria == somaPadrao) ? somaPadrao : -1;
}

