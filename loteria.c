#include <stdio.h>

void lerNumeros(int *array)
{
    for (int i = 0; i < 6; i++)
    {
        scanf("%d", &array[i]);
    }
}

int calcularAcertos(int *arrayFlav, int *arrayAposta)
{
    int count = 0;
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (arrayFlav[i] == arrayAposta[j])
            {
                count++;
            }
        }
    }
    return count;
}

int main()
{
    int arrayFlav[6];
    int arrayAposta[6];

    lerNumeros(arrayFlav);

    lerNumeros(arrayAposta);

    int acertos = calcularAcertos(arrayFlav, arrayAposta);

    switch (acertos)
    {
    case 3:
        printf("terno");
        break;
    case 4:
        printf("quadra");
        break;
    case 5:
        printf("quina");
        break;
    case 6:
        printf("sena");
        break;
    default:
        printf("azar");
    }
    return 0;
}
