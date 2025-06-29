#include <stdio.h>
#include <string.h>

int main() {
    int N = 0, L = 0, C = 0;
    char palavra[1000][71] = {0};

    scanf("%d %d %d", &N, &L, &C);

    for (int i = 0; i < N; i++) {
        scanf("%s", palavra[i]);
    }

    int linha = 1;
    int tamanhoLinha = 0;

    for (int i = 0; i < N; i++) {
        int len = strlen(palavra[i]);
        if (tamanhoLinha == 0) {
            tamanhoLinha = len;
        } else if (tamanhoLinha + 1 + len <= C) {
            tamanhoLinha += 1 + len;
        } else {
            linha++;
            tamanhoLinha = len;
        }
    }

    int numPaginas = (linha + L - 1) / L;
    printf("%d\n", numPaginas);

    return 0;
}








