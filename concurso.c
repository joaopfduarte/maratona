#include <stdio.h>
#include <string.h>

int main() {
   
    int N = 0, L = 0, C = 0;
    char palavra[1000][71] = {0};
    int linha = 0, coluna = 0;

    scanf("%d %d %d", &N, &L, &C);

    int tamanhoLinha = 0;

    for (int i = 0; i < N; i++) {
        scanf("%s", palavra[i]);
    }

    for (int i = 0; i < N; i++) {
        tamanhoLinha += strlen(palavra[i]) + 1;
        int tamanhoHorizontal = strlen(palavra[i]) + 1;
        
        if ((tamanhoLinha >= C) && (palavra[i][tamanhoHorizontal] == ' ')) {
            linha++;
            tamanhoLinha = 0;
        } else if ((tamanhoLinha >= C) && !(palavra[i][tamanhoHorizontal] == ' ')) {
            linha++;
            tamanhoLinha = 0;
            continue;
        }
    }

    int numPaginas = 0;
   
    if (L < linha) {
        float dif = linha / L;
        numPaginas = (int)dif + 1;
    } else {
        numPaginas = 1;
    }

    printf("%d\n", numPaginas);

    return 0;
}







