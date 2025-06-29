#include <stdio.h>

int main() {
    int T = 0, N = 0;

    while(scanf("%d %d", &T, &N) == 2 & T>= 2 & N >= 0) {

        int S = 0;

        for (int i = 0; i < T; i++){
            char nome[11];
            int ponto;
            scanf("%s %d", nome, &ponto);
            S += ponto;
        }

        int E = (3 * N) - S;
        printf("%d\n", E);
    }
    return 0;
}
