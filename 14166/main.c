#include <stdio.h>
long long int profit = 0, n, p[100005];
int main() {
    scanf("%lld", &n);
    for (int i=0; i<n; i++) scanf("%lld", &p[i]);
    for (int i=1; i<n; i++) profit += (p[i] - p[i-1] > 0) ? (p[i] - p[i-1]) : 0;
    printf("%lld\n", profit);
}