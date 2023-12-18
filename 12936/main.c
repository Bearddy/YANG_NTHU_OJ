#include <stdio.h>


int T, N, M;


int main() {
    scanf("%d", &T);

    while(T--){
        int row_len[50], col_len[50];
        int check = 1;
        int row[50][50], col[50][50];
        char map[50][50];
        scanf("%d %d", &N, &M);

        for(int i = 0; i < N; i++){

            scanf("%d", &row_len[i]);
            for(int j = 0; j < row_len[i]; j++) {
                scanf("%d", &row[i][j]);
            }
        }
        for(int i = 0; i < M; i++){
            int temp;
            scanf("%d", &col_len[i]);
            for(int j = 0; j < col_len[i]; j++) {
                scanf("%d", &col[i][j]);
            }
        }

        for(int i = 0; i < N; i++){
            scanf("%s", map[i]);
        }

        //check
        for(int i = 0; i < N; i++){
            int count = 0;
            int now = 0;
            for(int j = 0; j < M; j++){

                if(map[i][j] == 'o'){
                    now++;
                }
                else{
                    if(now != 0){
                        if(now != row[i][count]){
                            check = 0;
                        }
                        now = 0;
                        count++;
                    }
                }
            }

            if(now != 0){
                if(now != row[i][count]){
                    check = 0;
                }
                now = 0;
                count++;
            }

            if(count != row_len[i]){
                check = 0;
            }
        }

        for(int j = 0; j < M; j++){
            int count = 0;
            int now = 0;
            for(int i = 0; i < N; i++){
                if(map[i][j] == 'o'){
                    now++;
                }
                else{
                    if(now != 0){
                        if(now != col[j][count]){
                            check = 0;
                        }
                        now = 0;
                        count++;
                    }
                }
            }

            if(now != 0){
                if(now != col[j][count]){
                    check = 0;
                }
                now = 0;
                count++;
            }

            if(count != col_len[j]){
                check = 0;
            }
        }

        printf(check ? "Yes\n" : "No\n");
    }
    return 0;
}
