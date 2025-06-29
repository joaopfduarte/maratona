#include <stdio.h>

int main() {
    int r = 0;

    scanf("%d", &r);
    while(r != 0) {
        int vetM[10] = {0}, vetL[10] = {0};
        int somaM = 0, somaL = 0;
        char nome;
        int verM = -1, verL = -1;

        for(int i = 0; i < r; i++) {
            scanf("%d", &vetM[i]);
        }
        for (int i = 0; i < r; i++) {
            scanf("%d", &vetL[i]);
        }

        for (int i = 0; i < r; i++) {
            if ((i + 2) < r) {
                if ((vetM[i] == vetM[i+1]) && (vetM[i+1] == vetM[i+2])){
                    if(verM == -1){verM = i;}
                }
                if ((vetL[i] == vetL[i+1]) && (vetL[i+1] == vetL[i+2])) {
                    if (verL == -1){verL = i;}
                }
            }
            somaM += vetM[i];
            somaL += vetL[i];
        } 

        if (verM != -1 || verL != -1) {
            if (verM != -1 && verL != -1){
                if (verM < verL) {
                    somaM += 30;
                } else if (verL < verM){
                    somaL += 30;
                } 


            } else {
                if (verM != -1) {somaM += 30;}
                if (verL != -1) {somaL += 30;}
            }
        }

        if (somaM > somaL) {nome = 'M';}
        if (somaL > somaM) {nome = 'L';}
        if (somaL == somaM) {nome = 'T';}
        printf(" %c\n", nome);
        scanf("%d", &r);
    }
    return 0;
}
