#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, m, k;
        scanf("%d %d %d", &n, &m, &k);

        int A[501][501], B[500][500];
        int after = n - m + 1;
        int count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = n - 1; j >= 0; j--) {
                scanf("%d", &A[i][j]);
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d", &B[i][j]);
            }
        }

        for (int i = 0; i < after; i++) {
            for (int j = 0; j < after; j++) {
                int sum = 0;
                for (int x = 0; x < m; x++) {
                    for (int y = 0; y < m; y++) {
                        sum += A[i + x][j +y] * B[x][y];
                    }
                }
            if (sum > k){
                count++;
            }
        }
        printf("%d\n", count);
    }
    return 0;
}