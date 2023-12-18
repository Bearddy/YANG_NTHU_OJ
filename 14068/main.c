#include <stdio.h>


int nums[505];
int ans[100];

int N, M, K;

void comb(int cur_index, int count, int sum) {

    if (count == M) {
        if (sum == K) {
            for (int i = 0; i < M; i++) {
                printf("%d ", ans[i]);
            }
            printf("\n");
        }
        return;
    }

    if (cur_index == N || count >= M) {
        return;
    }

    for (int i = cur_index; i < N; i++) {
        ans[count] = nums[i];
        comb(i + 1, count + 1, sum + nums[i]);
        while (i < N - 1 && nums[i] == nums[i + 1]) {
            i++;
        }
    }
}

void bubble_sort(int ap[], int n) {
    int i, j, temp;

    for (i=0; i<n-1; i++) {
        for (j=0; j<n-1-i; j++) {
            if (ap[j]>ap[j + 1]) {
                temp=ap[j];
                ap[j]=ap[j+1];
                ap[j+1]=temp;
            }
        }
    }
}
int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        scanf("%d %d %d", &N, &M, &K);

        for (int i = 0; i < N; i++) {
            scanf("%d", &nums[i]);
        }

        bubble_sort(nums, N);

        comb(0, 0, 0);
    }

    return 0;
}