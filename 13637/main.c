#include <stdio.h>
int N,chess[30][30]={0},win=0,input[230][3],K; 
void scan(int x,int y,int player){//x,y==input[i][0]+5,input[i][1]+5
    for(int i=0; i<5; i++){//horizontal
        for(int j=0; j<5; j++){
            win=player;
            if(chess[x-4+i+j][y]!=player){
                win=0;
                break;
            }
        }
        if(win==player){
            break;
        }
    }
    if(win==0){
        for(int i=0; i<5; i++){//vertical
            for(int j=0; j<5; j++){
                win=player;
                if(chess[x][y-4+i+j]!=player){
                    win=0;
                    break;
                }
            }
            if(win==player){
                break;
            }
        }
    }
    if(win==0){
        for(int i=0; i<5; i++){
            for(int j=0; j<5; j++){
                win=player;
                if(chess[x-4+i+j][y-4+i+j]!=player){
                    win=0;
                    break;
                }
            }
            if(win==player){
                break;
            }
        }
    }
    if(win==0){
        for(int i=0; i<5; i++){
            for(int j=0; j<5; j++){
                win=player;
                if(chess[x+4-i-j][y-4+i+j]!=player){
                    win=0;
                    break;
                }
            }
            if(win==player){
                break;
            }
        }
    }
}


int main(){
    scanf("%d",&N);
    for(int i=0; i<N; i++){
        scanf("%d %d",&input[i][0],&input[i][1]);
    }
    for(int i=0; i<N; i++){
        if(i%2==0){
            chess[input[i][0]+7][input[i][1]+7]=1;//0 0=6 6
            scan(input[i][0]+7,input[i][1]+7,1);
        }
        else{
            chess[input[i][0]+7][input[i][1]+7]=2;
            scan(input[i][0]+7,input[i][1]+7,2);
        }
        if(win!=0){
            K=i+1;
            break;
        }
    }
    if(win==0){
        printf("There's no winner.\n");
    }
    else if(win==1){
        printf("LSC wins at the %dth step.\n",K);
    }
    else{
        printf("TSC wins at the %dth step.\n",K);
    }
}