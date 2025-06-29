#include <stdio.h>

int main()
{
    int linhas = 0, colunas = 0;
    int preenchidas = 0;

    scanf("%d %d", &linhas, &preenchidas);
    colunas = linhas;
    int matriz[linhas][colunas];

    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < linhas; j++)
        {
            matriz[i][j] = 0;
        }
    }

    for (int k = 0; k < preenchidas; k++)
    {
        int x, y = 0;
        scanf("%d %d", &x, &y);
        matriz[x - 1][y - 1] = 1;
    }

    int total = 0;

    for (int i = 0; i < linhas; i++)
    {
        int count = 0;
        for (int j = 0; j < linhas; j++)
        {
            if (matriz[i][j] == 0)
            {
                count++;
            }
            else
            {
                if (count >= 2)
                {
                    total += (count * (count + 1)) / 2;
                }
                count = 0;
            }
        }
        if (count >= 2)
        {
            total += (count * (count + 1)) / 2;
        }
    }

    for (int j = 0; j < linhas; j++)
    {
        int count = 0;
        for (int i = 0; i < linhas; i++)
        {
            if (matriz[i][j] == 0)
            {
                count++;
            }
            else
            {
                if (count >= 2)
                {
                    total += (count * (count + 1)) / 2;
                }
                count = 0;
            }
        }
        if (count >= 2)
        {
            total += (count * (count + 1)) / 2;
        }
    }
    total++;

    printf("%d\n", total);
    return 0;
}