#include <stdio.h>

int main(){
    int x;
    scanf("%d",&x);
    printf("%d\n", spect(x));
    return 0;
}

int spect(int n){
    int num = 0;
    for(int i = 1; i <= n; i++){
        num = 1 + num * 8;
    }

    return num;
}