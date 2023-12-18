#include <stdio.h>

void hanoi(int n, char from, char to, char temp);


int main(){
    int n;
    scanf("%d", &n);
    hanoi(n, 'A', 'C', 'B');

}

void hanoi(int n, char from, char to, char temp) {
    if (n == 1){
        //printf("debug1 %d\n", n);
		//printf("move disk 1 from rod %c to %c\n", from, to);
        printf("1\n");
    }
	else {
        //printf("debug2 %d\n", n);
		hanoi(n - 1, from, temp, to);
		//printf("move disk %d from rod %c to %c\n", n, from, to);
        printf("%d\n", n);
        //printf("debug3 %d\n", n);
		hanoi(n - 1, to, from, temp);
	}

}