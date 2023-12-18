#include <stdio.h>

int main(){
    long long int ans[1000000];
    long long int addition[1000000] = {0};
    int N, M;

    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++){
        scanf("%lld", &ans[i]);
    }
    int L, R, X;
    for(int i = 0; i < M; i++){
        scanf("%d %d %d", &L, &R, &X);
        addition[L-1] += X;

        if(R < N){
            addition[R] -= X;
        }
    }

    for (int i = 1; i < N; i++){
        addition[i] += addition[i - 1];
    }
    
    for(int i = 0; i < N; i++){
        printf("%lld", ans[i]+addition[i]);
        if(i < N - 1){
            printf(" ");
        }
    }
    printf("\n");
}