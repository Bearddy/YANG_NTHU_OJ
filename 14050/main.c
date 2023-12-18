#include <stdio.h>
#include <string.h>

int map[110][110];
int size[5];

int get_direction(int pos_x, int pos_y){
    int result;
    int max = -3;
    for(int i = 0; i < 4; i++){
        if(size[i] > max){
            max = size[i];
            result = i;
        }
    }
    return result;
}

int main(){
    memset(map, -1, sizeof(map));
    int result = 0;
    int N, M;
    int direction = 0; //0: right, 1: down, 2: left, 3: up
    int mode = 1; //0: go straight until find higher, 1: find each block 
    int highest = 0;
    int going = 14;
    int pos_x = 1, pos_y = 1;
    scanf("%d %d", &N, &M);

    for(int i = 1; i < N+1; i++){
        for(int j = 1; j < M+1; j++){
            scanf("%d", &map[i][j]);
        }
    }
    //result += map[1][1];
    while(going){
        size[0] = map[pos_x][pos_y+1];
        size[1] = map[pos_x+1][pos_y];
        size[2] = map[pos_x][pos_y-1];
        size[3] = map[pos_x-1][pos_y];
        if(mode == 1){
            direction = get_direction(pos_x, pos_y);
            highest = size[direction];
            mode = 0;
        }

        result += map[pos_x][pos_y] != -2 ? map[pos_x][pos_y] : 0;

        printf("|| right: %d down: %d left: %d up: %d ||\n", size[0], size[1], size[2], size[3]);
        printf("--%d %d--\n", size[direction], highest);
        printf("now : %d pos : %d %d direction : %d\n\n", map[pos_x][pos_y], pos_x, pos_y, direction);
        
        map[pos_x][pos_y] = -2;

        if((size[0] == -1 || size[0] == -2) && (size[1] == -1 || size[1] == -2) && (size[2] == -1 || size[2] == -2) && (size[3] == -1 || size[3] == -2)){
            break;
        }

        if(size[direction] > highest){
            mode = 1;
        }

        if(direction == 0){
            if(pos_y == M){
                printf("test1");
                direction = get_direction(pos_x, pos_y);
                printf("test2     %d\n", direction);
                if(get_direction(pos_x, pos_y) == 1){
                    printf("test");
                    pos_x++;
                }
                else if(get_direction(pos_x, pos_y) == 2){
                    pos_y--;
                }
                else if(get_direction(pos_x, pos_y) == 3){
                    pos_x--;
                }
                highest = map[pos_x][pos_y];
                
            }
            else{
                pos_y++;
            }
        }
        else if(direction == 1){
            if(pos_x == N){
                direction = get_direction(pos_x, pos_y);
                if(get_direction(pos_x, pos_y) == 0){
                    pos_y++;
                }
                else if(get_direction(pos_x, pos_y) == 2){
                    pos_y--;
                }
                else if(get_direction(pos_x, pos_y) == 3){
                    pos_x--;
                }
                highest = map[pos_x][pos_y];
            }
            else{
                pos_x++;
            }
        }
        else if(direction == 2){
            if(pos_y == 1){
                direction = get_direction(pos_x, pos_y);
                if(get_direction(pos_x, pos_y) == 1){
                    pos_x++;
                }
                else if(get_direction(pos_x, pos_y) == 0){
                    pos_y++;
                }
                else if(get_direction(pos_x, pos_y) == 3){
                    pos_x--;
                }
                highest = map[pos_x][pos_y];
            }
            else{
                pos_y--;
            }
        }
        else if(direction == 3){
            if(pos_x == 1){
                direction = get_direction(pos_x, pos_y);
                if(get_direction(pos_x, pos_y) == 1){
                    pos_x++;
                }
                else if(get_direction(pos_x, pos_y) == 2){
                    pos_y--;
                }
                else if(get_direction(pos_x, pos_y) == 0){
                    pos_y++;
                }
                highest = map[pos_x][pos_y];
            }
            else{
                pos_x--;
            }
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

    // for(int i = 0; i < N+2; i++){
    //     for(int j = 0; j < M+2; j++){
    //         printf("%d ", map[i][j]);
    //     }
    //     printf("\n");
    // }
    printf("%d\n", result);
    if(!not_print){
        printf("Road Roller Da!!\n");
    }
    return 0;
}

