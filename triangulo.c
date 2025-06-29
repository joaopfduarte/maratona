#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b, c, d = 0;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    int auxBigger = 0;
    int soma = 0;

    int acum[] = {a, b, c, d};
    for (int i = 0; i < 4; i++)
    {
        if (acum[i] > auxBigger)
        {
            auxBigger = acum[i];
        }
    }

    for (int i = 0; i < 4; i++)
    {
        if (acum[i] != auxBigger)
        {
            soma += acum[i];
        }
    }

    for (int i = 0; i < 4; i++)
    {
        if (acum[i] != auxBigger)
        {
            if (!(soma - acum[i] > acum[i]))
            {
                printf("N");
                exit(0);
            }
        }
    } 
    printf("S");

    return 0;
}
