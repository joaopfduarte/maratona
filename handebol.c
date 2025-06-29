#include <stdio.h>

int main() {

    int n = 0; int m = 0;
    scanf("%d %d", &n, &m);

    int gols[m];
    int contador = 0;
    int somador = 0;

    for (int j = 0; j < n; j++ ){
        for (int i = 0; i < m; i++) {
            scanf("%d", &gols[i]);
        }

        for (int k = 0; k < m; k++) {
            if (gols[k] == 0) {
                contador++;
            }
        }

        if (contador != 0){
            contador = 0;} else {somador++;}
    }

    printf("%d\n", somador); 
    return 0;
}
