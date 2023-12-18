#include <stdio.h>
#include <string.h>

int map[110][110];
int dire[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1 ,0}};


int main(){
    memset(map, -1, sizeof(map));
    int result = 0;
    int N, M;
    int direction = 0; //0: right, 1: down, 2: left, 3: up
    int pos_x = 1, pos_y = 1;
    scanf("%d %d", &N, &M);

    for(int i = 1; i < N+1; i++){
        for(int j = 1; j < M+1; j++){
            scanf("%d", &map[i][j]);
        }
    }

    while(1){
        int highest = -3;
        result += map[pos_x][pos_y] != -2 ? map[pos_x][pos_y] : 0;
        map[pos_x][pos_y] = -2;

        // printf("|| right: %d down: %d left: %d up: %d ||\n", size[0], size[1], size[2], size[3]);
        // printf("--%d %d--\n", map[pos_x][pos_y], highest);
        // printf("now : %d pos : %d %d direction : %d\n\n", map[pos_x][pos_y], pos_x, pos_y, direction);

        for(int i = 0; i < 4; i++){
            if(map[pos_x + dire[i][0]][pos_y + dire[i][1]] > highest){
                highest = map[pos_x + dire[i][0]][pos_y + dire[i][1]];
                direction = i;
            }
        }
        if(highest == -2 || highest == -1){
            break;
        }

        while(pos_y + dire[direction][1] <= M && pos_y + dire[direction][1] >= 1 && pos_x + dire[direction][0] <= N && pos_x + dire[direction][0] >= 1){
            pos_x += dire[direction][0];
            pos_y += dire[direction][1];
            result += map[pos_x][pos_y] != -2 ? map[pos_x][pos_y] : 0;
            
            if(map[pos_x][pos_y] > highest){
                map[pos_x][pos_y] = -2;
                break;
            }
            map[pos_x][pos_y] = -2;
        }

    }

    int not_print = 0;
    for(int i = 0; i < N+2; i++){
        for(int j = 0; j < M+2; j++){
            if(!(map[i][j] == -1 || map[i][j] == -2)){
                not_print = 1;
                break;
            }
        }
    }

    printf("%d\n", result);
    if(!not_print){
        printf("Road Roller Da!!\n");
    }
    return 0;
}

