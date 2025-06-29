#include <stdio.h>

int main(){
    int numA = 0; int numB = 0; int numC = 0;
    scanf("%d %d %d", &numA, &numB, &numC);

    int i, j, tempNum, tempPos;
    int n = 3;

    int vetNum [] = {numA, numB, numC};
    int vetPos [] = {1, 2, 3};

    for (i = 0; i < n -1; i++) {
        for (j = 0; j< n- i -1; j++) {
            if (vetNum[j] > vetNum[j + 1]) {
                tempNum = vetNum[j];
                tempPos = vetPos[j];

                vetNum[j] = vetNum[j + 1];
                vetPos[j] = vetPos[j + 1];

                vetNum [j + 1] = tempNum;
                vetPos [j + 1] = tempPos;
            }
        }
    }

    for (int a = 0; a < 3; a++) {
        printf("%d\n", vetPos[a]);
    }
    return 0;
}
