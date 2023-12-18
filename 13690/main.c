#include <stdio.h>
long long int F[100] = {0}, G[100] = {0};

void calc_fibo(int n);
int main(){
    int a, b, c, d, n;
    scanf("%lld %lld %lld %lld %d", &F[0], &F[1], &G[0], &G[1], &n);
    for(int i = 2; i < n+1; i++){
        calc_fibo(i);
    }

    printf("%lld %lld\n", F[n], G[n]);

}

void calc_fibo(int n){
    
    if (n % 3 == 0)
        F[n] = F[n - 1] + G[(F[n / 3] % n)];
    else
        F[n] = F[n - 1] + G[n - 2];

    if (n % 5 == 0)
        G[n] = G[n - 1] + F[(G[n / 5] % n)];
    else
        G[n] = G[n - 1] + F[n - 2];
}
