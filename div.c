#include <stdio.h>

int main() {
    float value = 0;
    float div = 0;

    scanf("%f", &value);
    scanf("%f", &div);

    float divT = value / div;

    printf("%.2f", divT);
    return 0;
}