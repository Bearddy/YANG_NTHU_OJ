#include <stdio.h>

int main(){
    char letter[4];
    int n = 0;
    scanf("%s %d", &letter, &n);

    for(int i = 0; i < 3; i++){
        letter[i] += n % 26;
        if(letter[i] < 65){
            letter[i] += 26;
        }
        else if(letter[i] > 90){
            letter[i] -= 26;
        }

    }

    printf("%s\n", letter);
    return 0;
}