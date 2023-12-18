#include <stdio.h>

int main(){

    char A[6];
    scanf("%s", &A);

    for(int i = 0; i < 5; i++){
        A[i] = 97 - 6 - (A[i] - 96);
    }

    printf("%s", A);

    return 0;
}