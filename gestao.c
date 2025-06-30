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

char *alocar(nome no);
char *redimensionarVetorChar(char *vetor, int novo_tamanho);

int main()
{
    Pessoa aluno;
    int totalAlunos = 0;
    float totalNotas = 0.0;
    char *topIniciais = (char *)malloc(5 * sizeof(char));
    int capacidade = 10;
    char *iniciais = (char *)malloc(capacidade * sizeof(char));

    for (int i = 0; i < 5; i++)
    {
        topIniciais[i] = 0;
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
            char *novo = realloc(topIniciais, capacidade * sizeof(char));
            if (novo == NULL)
            {
                printf("Erro ao realocar memória!\n");
                free(topIniciais);
                exit(1);
            }
            topIniciais = novo;
        }

        printf("Dados do aluno:\n");
        printf("Nome: %s\n", aluno.nome);
        printf("Idade: %d\n", aluno.idade);
        printf("Nota: %.2f\n", aluno.nota);

        topIniciais[totalAlunos] = aluno.nome[0];
        totalAlunos++;
        totalNotas += aluno.nota;
        totalAlunos++;

        while ((c = getchar()) != '\n' && c != EOF)
            ;
    }
    free(iniciais);
    topIniciais = alocar(aluno.nome);

    int freq[26] = {0};
    for (int i = 0; i < totalAlunos; i++)
        if (iniciais[i] >= 'A' && iniciais[i] <= 'Z')
            freq[iniciais[i] - 'A']++;

    char top5[5] = {0};
    int rep[5] = {0};

    for (int k = 0; k < 5; k++)
    {
        int max = 0, idx = -1;
        for (int j = 0; j < 26; j++)
            if (freq[j] > max)
            {
                max = freq[j];
                idx = j;
            }
        if (idx == -1 || max == 0)
        {
            break;
        }
        top5[k] = 'A' + idx;
        rep[k] = max;
        freq[idx] = 0;
    }

    printf("Estatísticas Finais:\n");
    printf("Total de alunos: %d\n", (int)totalAlunos);
    printf("Média das notas: %.2f\n", (totalNotas / (float)totalAlunos));
    printf("\nTop 5 letras mais frequantes: \n");

    for (int i = 0; i < 5 && topIniciais[i] != 0; i++)
    {
        printf(" %c: %d (%.1f%%)\n", toupper(top5[i]), rep[i], 100.0 * rep[i] / totalAlunos);
    }
    free(topIniciais);
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

char *redimensionarVetorChar(char *vetor, int novo_tamanho)
{
    char *novo_vetor = realloc(vetor, novo_tamanho * sizeof(char));

    if (novo_vetor == NULL)
    {
        printf("Log Error: Não foi possível realocar o vetor");
        return vetor;
    }
    else
    {
        return novo_vetor;
    }
}