#include <stdio.h>
#include <stdlib.h>

#define MAX_GRID_SIZE 201
#define FULL 1
#define EMPTY 0
#define MARK 2

int dx[8] = {0, 0, 1, -1, 1, 1, -1, -1};
int dy[8] = {1, -1, 0, 0, 1, -1, -1, 1};
int **matriz = NULL;

int **alocaMatriz(int totalLinhas, int totalColunas)
{
    int **matriz = (int **)malloc(totalLinhas * sizeof(int *));
    for (int i = 0; i < totalLinhas; i++)
    {
        matriz[i] = (int *)malloc(totalColunas * sizeof(int));
        for (int j = 0; j < totalColunas; j++)
        {
            matriz[i][j] = 0;
        }
    }
    return matriz;
}

void desalocaMatriz(int **matriz, int totalLinhas)
{
    for (int i = 0; i < totalLinhas; i++)
    {
        free(matriz[i]);
    }
    free(matriz);
    matriz = NULL;
}

int preenche(int x, int y)
{
    int totalPreenchido = 1;

    if (x < 0 || x >= MAX_GRID_SIZE || y < 0 || y >= MAX_GRID_SIZE)
    {
        return 0;
    }
    if (matriz[x] == NULL)
    {
        return 0;
    }
    if (matriz[x][y] != EMPTY)
    {
        return 0;
    }
    matriz[x][y] = MARK;

    for (int i = 0; i < 8; i++)
    {
        int direcaoX = x + dx[i];
        int direcaoY = y + dy[i];
        totalPreenchido += preenche(direcaoX, direcaoY);
    }

    return totalPreenchido;
}

int main()
{
    int totalLinhas = 0, totalColunas = 0;
    int posLinhaIni = 0, posColunaIni = 0;

    int k = 0;

    scanf("%d %d %d %d %d", &totalLinhas, &totalColunas, &posLinhaIni, &posColunaIni, &k);

    matriz = alocaMatriz(totalLinhas, totalColunas);

    while (k--)
    {
        int a = 0, b = 0;
        scanf("%d %d", &a, &b);
        matriz[a - 1][b - 1] = FULL;
    }

    int totalPreenchido = preenche(posLinhaIni - 1, posColunaIni - 1);
    desalocaMatriz(matriz, totalLinhas);
    printf("%d\n", totalPreenchido);
    return 0;
}
