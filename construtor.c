#include <stdio.h>
#include <string.h>
#include <ctype.h>

int conversor(char digito);

int main() {
    char separador[14] = "-------------";
    char labirinto[10000];

    while (scanf(" %[^\n]", labirinto) != EOF) {
        int i = 0;
        int tem_saida = 0;
        int len = strlen(labirinto);

        while (i < len) {
            if (labirinto[i] == '!') {
                printf("\n");
                i++;
                continue;
            }

            int total = 0;

            while (i < len && isdigit(labirinto[i])) {
                total += conversor(labirinto[i]);
                i++;
            }

            if (total > 0 && i < len) {
                char atual = labirinto[i];
                if (atual == 'b') atual = ' ';
                if (atual == '!') atual = '\n';
                for (int j = 0; j < total; j++) {
                    printf("%c", atual);
                    tem_saida = 1;
                }
                i++;
            } else {
                i++;
            }
        }

        if (!tem_saida) printf("Entrada errada");
        printf("\n%s\n", separador);

        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    }
    return 0;
}

int conversor(char digito)
{
    switch (digito)
    {
    case '1': return 1;
    case '2': return 2;
    case '3': return 3;
    case '4': return 4;
    case '5': return 5;
    case '6': return 6;
    case '7': return 7;
    case '8': return 8;
    case '9': return 9;
    default:  return 0;
    }
}
