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

typedef struct 
{
    char *letra;
    int valor;
} TopCinco;

typedef int idade;
typedef float nota;
typedef char *nome;

char *alocar(nome no);

int main()
{
    Pessoa aluno;
    int totalAlunos = 0;
    float totalNotas = 0.0;
    int capacidade = 10;
    char *iniciais = (char *)malloc(capacidade * sizeof(char));

    for (int i = 0; i < 5; i++)
    {
        iniciais[i] = 0;
    }

    for (int i = 0; i < 50; i++)
    {
        aluno.nome[i] = 0;
    }

    for (int i = 0; scanf("%[^\n] %d %f", aluno.nome, &aluno.idade, &aluno.nota) == 3; i++)
    {
        int c;

        if (totalAlunos >= capacidade)
        {
            capacidade *= 2;
            char *novo = realloc(iniciais, capacidade * sizeof(char));
            if (novo == NULL)
            {
                printf("Erro ao realocar memória!\n");
                free(iniciais);
                exit(1);
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
        while ((c = getchar()) != '\n' && c != EOF)
            ;
    }
    free(iniciais);
    iniciais = alocar(aluno.nome);

    
    return 0;
}

char *alocar(nome no)
{
    int *contador = (int *)malloc(26 * sizeof(int));
    char *top5 = (char *)malloc(5 * sizeof(char));

    const char *letras = "abcdefghijklmnopqrstuvwxyz";
    const char *encontrado;

    int posicao = 0;
    int iteradorAlfabetico = 0;

    for (int i = 0; i < (sizeof(contador) / sizeof(contador[0])); i++)
    {
        contador[0] = 0;
    }

    if (no == NULL)
    {
        printf("Log Error: informação nula\n");
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

    free(contador);
    contador = NULL;
    return top5;
}