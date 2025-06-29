#include <stdio.h>

void coletor(int n);
void calculadora(char tipo[], int nota[], char r[], int n);
int varredor (char tipo, char contTipo[], int n);

int main() {
    int n = 0;

    scanf("%d", &n);
    while (n != 0) {
        coletor(n);        
        scanf("%d", &n);
    }
    return 0;
}

void coletor(int n){
    char tipo[n];
    int nota[n];

    char resultado[9];  
    char r[n]; 

    for (int i = 0; i < n; i++){
        scanf(" %c %d %s", &tipo[i], &nota[i], resultado);
        r[i] = resultado[0];
    }

    calculadora(tipo, nota, r, n);
}

void calculadora(char tipo[], int nota[], char r[], int n) {
    //    for (int i = 0; i < 3; i++){printf(" %c %d %c\n", tipo[i], nota[i], r[i]);}
    char contTipo[300] = {0};
    int contNota[300] = {0};

    int s = 0, p = 0;

    for (int i = 0; i < n; i++) {
        if (r[i]== 'c') {
            if (!varredor(tipo[i], contTipo, s)) {
                contTipo[s] = tipo[i];
                contNota[s] = nota[i];
                s++;
            }
        }
    }

    for (int i = 0; i < n; i++){
        if(r[i] == 'i'){ 
            if (varredor(tipo[i], contTipo, s)){
                p += 20;
            }
        }
    }

    for (int i = 0; i < s; i++) {p += contNota[i];}

    printf("%d %d\n", s, p);
}

int varredor (char tipo, char contTipo[], int tamanho){
    for (int i = 0; i < tamanho; i++) {
        if ((tipo == contTipo[i])) {
            return 1;
        } 
    }

    return 0;
}




















