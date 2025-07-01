#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

typedef struct {
    char nome[50];
    int idade;
    float nota;
} Pessoa;

typedef struct {
    char letra;
    int valor;
} TopCinco;

int comparar(const void *a, const void *b) {
    TopCinco *x = (TopCinco *)a;
    TopCinco *y = (TopCinco *)b;
    return y->valor - x->valor;
}

TopCinco *contar_letras(char *iniciais, int totalAlunos);

int main() {
    Pessoa aluno;
    int totalAlunos = 0;
    float totalNotas = 0.0;
    int capacidade = 10;
    char *iniciais = malloc(capacidade * sizeof(char));

    if (iniciais == NULL) {
        printf("Erro ao alocar memória!\n");
        return 1;
    }

    while (scanf("%s %d %f", aluno.nome, &aluno.idade, &aluno.nota) == 3) {
        if (totalAlunos >= capacidade) {
            capacidade *= 2;
            char *novo = realloc(iniciais, capacidade * sizeof(char));
            if (novo == NULL) {
                printf("Erro ao realocar memória!\n");
                free(iniciais);
                return 1;
            }
            iniciais = novo;
        }

        printf("Dados do aluno:\n");
        printf("Nome: %s\n", aluno.nome);
        printf("Idade: %d\n", aluno.idade);
        printf("Nota: %.2f\n", aluno.nota);

        iniciais[totalAlunos] = aluno.nome[0];
        totalAlunos++;
        totalNotas += aluno.nota;
    }

    printf("\nEstatisticas Finais:\n");
    printf("Total de alunos: %d\n", totalAlunos);
    printf("Media das notas: %.2f\n", totalNotas / totalAlunos);

    TopCinco *top5 = contar_letras(iniciais, totalAlunos);

    printf("Top 5 letras mais frequentes:\n");
    for (int i = 0; i < 5 && top5[i].valor > 0; i++) {
        float percentual = (top5[i].valor * 100.0f) / totalAlunos;
        printf("%c: %d (%.1f%%)\n", top5[i].letra, top5[i].valor, percentual);
    }

    free(iniciais);
    free(top5);

    return 0;
}

TopCinco *contar_letras(char *iniciais, int totalAlunos) {
    int contador[26] = {0};  
    for (int i = 0; i < totalAlunos; i++) {
        char ch = toupper(iniciais[i]);
        if (ch >= 'A' && ch <= 'Z') {
            contador[ch - 'A']++;
        }
    }

    TopCinco *top = malloc(26 * sizeof(TopCinco));
    if (top == NULL) {
        printf("Erro ao alocar memória para TopCinco!\n");
        exit(1);
    }

    for (int i = 0; i < 26; i++) {
        top[i].letra = 'A' + i;
        top[i].valor = contador[i];
    }

    qsort(top, 26, sizeof(TopCinco), comparar);

    return top;  
}
