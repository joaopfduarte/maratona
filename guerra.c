#include <stdio.h>
#include <string.h>

/* Algoritmo Euclidiano Estendido */
int inverso_modular(int a, int m)
{
    int m0 = m;
    int x0 = 0, x1 = 1;
    int q, temp;

    if (m == 1)
        return 0;

    while (a > 1)
    {
        q = a / m;
        temp = m;

        m = a % m;
        a = temp;

        temp = x0;
        x0 = x1 - q * x0;
        x1 = temp;
    }

    if (x1 < 0)
        x1 += m0;

    return x1;
}


int main()
{
    char mensagem[50];
    int primos[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
    char alfabeto[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ ";
    int primo = 0;
    int indiceTabular = 0;

    for (int i = 0; i < 50; i++)
    {
        mensagem[i] = 0;
    }

    int chave = 0, posLetra = 0;

    while (scanf(" %[^\n]", mensagem) != EOF && scanf("%d", &chave) != EOF)
    {
        int inverso = inverso_modular(chave, 27);

        for (int i = 0; i < strlen(mensagem); i++)
        {
            if (mensagem[i] == ' ')
                posLetra = 26;
            else
                posLetra = mensagem[i] - 'A';

            indiceTabular = (inverso * posLetra) % 27;

            if (indiceTabular < 0)
                indiceTabular += 27;

            printf("%c", alfabeto[indiceTabular]);
        }

        printf("\n");
    }

    return 0;
}