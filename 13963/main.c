#include <stdio.h>

int main(void){
    int x = 0;
    scanf("%d", &x);
    printf("%.2f\n", (double)((x / 1000) + ((x / 10) % 10)) / (double)(((x / 100) % 10) + (x % 10))); 
    return 0;
}