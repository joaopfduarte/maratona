#include <stdio.h>
#include <stdlib.h>

void direcao (int num, char *dirVet);

int main(){
    int num = -10;
    while (num != 0) {
        scanf("%d", &num);
        if (num == 0) {exit(0);}
        char dirVet[num];

        for (int i = 0; i < num; i++) {
            scanf(" %c" , &dirVet[i]);
        }
        direcao(num, dirVet);
    }
    exit(0);
    return 0;
}

void direcao(int num, char *dirVet) {
    int vetPos[4] = {1,2,3,4};
    int actPos = 0;

    for (int i = 0; i < num; i++) {
        if (dirVet[i] == 'D') {
            actPos++;
            if (actPos > 3) {actPos = 0;}
        } else {actPos--;
            if (actPos < 0){actPos = 3;}}
    }

    switch (actPos) {
        case 0: printf("N\n");
                break;
        case 1: printf("L\n");
                break;
        case 2: printf("S\n");
                break;
        case 3: printf("O\n");
                break;

        default: printf("N/");
    }

}
