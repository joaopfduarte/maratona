#include <stdio.h>

int main() {
    float h = 0;
    float p = 0;

    scanf("%d", &h);
    scanf("%d", &p);

    float div = (h/p);
    printf("%.2f", div);

    return 0;
}