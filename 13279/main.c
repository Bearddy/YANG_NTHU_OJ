#include <stdio.h>

int main(){
    int N, M;
    int a, b;
    int seats[1000];
    for(int i = 0; i < 1000; i++){
        seats[i] = i+1;
    }

    scanf("%d %d", &N, &M);
    for(int i = 0; i < M; i++){
        scanf("%d %d", &a, &b);
        for(int j = 0; j < N; j++){
            int temp = 0;
            if(seats[j] == a){
                for(int k = 0; k < N; k++){
                    if(seats[k] == b){
                        seats[k] = a;
                        seats[j] = b;
                        break;
                    }
                }
                break;
            }
        }
        
    }

    for(int i = 0; i < N; i++){
        if(i < N - 1){
            printf("%d ", seats[i]);
        }
        else{
            printf("%d\n", seats[i]);
        }
        
    }


    return 0;
}