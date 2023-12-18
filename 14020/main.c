#include <stdio.h>
#include <string.h>


int calc(char* str) {
    int n = strlen(str);
    int maxLength = 1;

    for (int i = 0; i < n; i++) {
        int left = i;
        int right = i;
        while (left >= 0 && right < n && str[left] == str[right]) {
            if (right - left + 1 > maxLength) {
                maxLength = right - left + 1;
            }
            left--;
            right++;
        }

        left = i;
        right = i + 1;

        while (left >= 0 && right < n && str[left] == str[right]) {
            if (right - left + 1 > maxLength) {
                maxLength = right - left + 1;
            }
            left--;
            right++;
        }
    }

    return maxLength;
}

int main() {
    char str[10001];
    while (scanf("%s", str) != EOF) {
        printf("%d\n", calc(str));
    }

    return 0;
}


