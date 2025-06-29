#include <stdio.h>

int main()
{
    int hourOne = 0;
    int minuteOne = 0;

    int hourTwo = 0;
    int minuteTwo = 0;

    int sumHour = 0;
    int sumMinute = 0;
    int sumTotal = 0;

    scanf("%d %d %d %d", &hourOne, &minuteOne, &hourTwo, &minuteTwo);

    // Verificar range de valor
    if (hourOne < 0 || hourOne > 24 || hourTwo < 0 || hourTwo > 24 ||
        minuteOne < 0 || minuteOne > 59 || minuteTwo < 0 || minuteTwo > 59)
    {
        exit(1);
    }

    if (hourOne == 0 && minuteOne == 0 && hourTwo == 0 && minuteTwo == 0) {
        exit(1);
    }

    // Verificar ciclo hora
    int totalMinutesOne = hourOne * 60 + minuteOne;
    int totalMinutesTwo = hourTwo * 60 + minuteTwo;

    if (totalMinutesTwo < totalMinutesOne)
    {
        totalMinutesTwo += 24 * 60;
    }

    sumTotal = totalMinutesTwo - totalMinutesOne;

    printf("%d\n", sumTotal);

    return 0;
}