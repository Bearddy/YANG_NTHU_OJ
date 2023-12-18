#include <stdio.h>

int main(){

    char c[27];
    char pass[4];

    scanf("%s", c);
    scanf("%s", pass);
    for(int i = 0; i < 3; i++){
        printf("%c", (pass[i] <= 'Z' ? (c[pass[i] - 'A']) : (c[pass[i] - 'a'] + 'a' - 'A')));
    }
    
    // for(int i = 0; i < 3; i++){
    //     for(int j = 0; j < 26; j++){
    //         if(pass[i] <= 'Z'){
    //             if('A' + j == pass[i]){
    //                 pass[i] = c[j];
    //                 break;
    //             }
    //         }
    //         if(pass[i] >= 'A'){
    //             if('a' + j == pass[i]){
    //                 pass[i] = c[j] + 32;
    //                 break;
    //             }
    //         }
    //     }
    // }

    // printf("%s", pass);
    return 0;
}