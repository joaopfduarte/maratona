#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

typedef struct
{
    char nome[50];
    int idade;
    float nota;
} Pessoa;

typedef int idade;
typedef float nota;
typedef char *nome;

void desalocar();
void alocar(int i, nome *no, idade id, nota nt);
int calculoMedia();

int main()
{
    Pessoa aluno;
    float totalAlunos = 0.0;
    float totalNotas = 0.0;

    for (int i = 0; i < 50; i++)
    {
        aluno.nome[i] = 0;
    }

    for (int i = 0; scanf("%[^\n] %d %f", aluno.nome, &aluno.idade, &aluno.nota) == 3; i++)
    {
        int c;
        printf("Dados do aluno:\n");
        printf("Nome: %s\n", aluno.nome);
        printf("Idade: %d\n", aluno.idade);
        printf("Nota: %.2f\n", aluno.nota);

        totalNotas += aluno.nota;
        alocar(i, aluno.nome, aluno.idade, aluno.nota);
        totalAlunos++;

        while ((c = getchar()) != '\n' && c != EOF);
    }

    printf("Estatísticas Finais:\n");
    printf("Total de alunos: %d\n", totalAlunos);
    printf("Média das notas: %.2f\n", (totalNotas / totalAlunos));

    return 0;
}

void alocar(int i, nome *no, idade id, nota nt)
{
    nome *inicial = (char *)malloc(26 * sizeof(char));
    int *contador = (int *)malloc(26 * sizeof(int));

    const char *letras = "abcdefghijklmnopqrstuvwxyz";
    const char *encontrado;

    int posicao = 0;
    int iteradorAlfabetico = 0;

    for (int i = 0; i < (sizeof(contador) / sizeof(contador[0])); i++) {
        contador[0] = 0;
    }

    if (no == NULL || id == NULL)
    {
        printf("[Log Error]: informação nula\n");
        return;
    }

    encontrado = strchr(letras, tolower(no[0]));
    posicao = encontrado - letras;
    if (!encontrado)
    {
        posicao = 0;
    }
    else if (posicao == 26)
    {
        posicao = 0;
    }
    else
    {
        posicao++;
    }

    iteradorAlfabetico = contador[posicao];
    contador[posicao] = iteradorAlfabetico++;
}

void desalocar()
{
}

int calculoMedia()
{
}