#include <stdio.h>
char letter[1000002];
void solution(char arr[], int now){
    int index = 0, check = 0;
    while (letter[index] != '\0'){
        if(letter[index] == now){
            if(check == 0){
                printf("%c:", now);
                check++;
            }
            printf(" %d", index);
        }
        index++;
    }
    if(check == 1){
        printf("\n");
    }
}
int main(){ 
    scanf("%s", letter);  
    for(int i = 0; i < 52; i++){
        solution(letter, i < 26 ? 'A' + i : 'a' + (i- 26));
    }
    return 0;
}