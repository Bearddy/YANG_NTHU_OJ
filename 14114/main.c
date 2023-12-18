#include <stdio.h>
#include <string.h>

int N;
char key[1005];
char sentence[100005];
int ans_count = 0;
char ans[100005];
char result_name[1000] = {'\0'};
char dfdfd[100005];
char *name = {'\0'};

int main() {
    int check = 0;
    char *result;
    int id = 10000;
    scanf("%d %s", &N, key);
    getchar();
    for(int i = 0; i < N; i++){
        check = 0;
        fgets(sentence, 100005, stdin);
        char temp[100005];
        strcpy(temp, sentence);
        result = strtok(temp, ":");
        name = result;
        result = strtok(NULL, " ,.?!");
        while(result != NULL){
            //printf("i : %d, result : %s, key: %s\n", i, result, key);
            if(strcasecmp(result, key) == 0) {
                check++;
            }
            result = strtok(NULL, " ,.?!");
        }
        if(check > ans_count) {
            strcpy(result_name, name);
            strcpy(ans, &sentence[strlen(result_name)+1]);
            ans_count = check;
        }

    }
    // printf("%d\n", strlen(name));
    // printf("%c\n", sentence[strlen(name)+1]);
    // printf("%s\n", sentence);
    printf("%s: %s", result_name, ans);


}
