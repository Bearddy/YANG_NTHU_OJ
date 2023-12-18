#include <stdio.h>

void doSpiral(int n);

int main(){

    
    int cnt, N;
    

    scanf("%d", &cnt);
    
    for(int i = 0; i < cnt; i++){
        scanf("%d", &N);
        doSpiral(N);
    }

    return 0;
}

void doSpiral(int n){
    char spiral[5002][5002];
    int direction = 0; // 0 : right, 1 : left, 2 : up, 3 : down
    int top = 0, bottom = n - 1, left = 0, right = n - 1;

    for(int j = 0; j < n; j++){
        for(int k = 0; k < n; k++){
            spiral[j][k] = ' ';
        }
    }

    while(top <= bottom && left <= right){
        if(direction == 0){
            for(int i = left; i <= right; i++){
                spiral[top][i] = '#';
            }
            top++;
            left++;
            direction = 3; 
        }
        else if(direction == 3){
            for(int i = top; i <= bottom; i++){
                spiral[i][right] = '#';
            }
            right--;
            top++;
            direction = 1;
        }
        else if(direction == 1){
            for(int i = right; i >= left; i--){
                spiral[bottom][i] = '#';
            }
            bottom--;
            right--;
            direction = 2;
        }
        else if(direction == 2){
            for(int i = bottom; i >= top; i--){
                spiral[i][left] = '#';
            }
            left++;
            bottom--;
            direction = 0;
        }
        
    }
    for(int j = 0; j < n; j++){
        for(int k = 0; k < n; k++){
           printf("%c", spiral[j][k]);
        }
        printf("\n");
    }

}