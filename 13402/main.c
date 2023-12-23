#include <stdio.h>

int map[20][20];
int T, N, M;
int MIN, cnt;

int check();
int calc(int i);
void dfs(int id);
void flip(int x, int y);

int main() {
    scanf("%d", &T);
    while(T--){
        MIN = 100000;
        cnt = 0;
        scanf("%d %d", &N, &M);
        for(int i = 1; i < N+1; i++){
            for(int j = 1; j < M+1; j++){
                char temp[2];
                scanf(" %c", &temp[0]);
                map[i][j] = temp[0] == 'b' ? 0 : 1;
            }
        }

        dfs(0);

        if(MIN == 100000) printf("oops\n");
        else printf("%d\n", MIN);
    }
    return 0;
}

int check(){
    int add = 0;
    for(int i = 1; i < N+1; i++){
        for(int j = 1; j < M+1; j++){
            add += map[i][j];
        }
    }
    return (add == 0 || add == N*M);
}

void dfs(int id){
    if(check() && MIN > cnt) MIN = cnt;
    if(id == M*N) return;
    dfs(id+1);
    if(cnt+1 >= MIN) return;
    flip(id/M + 1, id%M + 1);
    cnt++;
    dfs(id+1);
    flip(id/M + 1, id%M + 1);
    cnt--;
}

void flip(int x, int y){
    map[x][y] = calc(map[x][y]);
    map[x+1][y] = calc(map[x+1][y]);
    map[x-1][y] = calc(map[x-1][y]);
    map[x][y+1] = calc(map[x][y+1]);
    map[x][y-1] = calc(map[x][y-1]);

//    printf("x : %d, y : %d\n", x, y);
//    for(int i = 1; i < N+1; i++){
//        for(int j = 1; j < M+1; j++){
//            printf("%d ", map[i][j]);
//        }
//        printf("\n");
//    }
//    printf("\n");

}

int calc(int i){
    return i == 0 ? 1 : 0;
}

