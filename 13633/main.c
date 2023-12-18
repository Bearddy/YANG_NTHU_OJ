#include <stdio.h>
int main(){
    char code[1000];
    while(scanf("%[^\n]s", code) != EOF){
        //getchar();
        int i = 0;
        while(code[i] == ';'){
            code[i++] = ' ';
        }
        (code[strlen(code) - 1] == '{' || (code[i] == '}' && i==strlen(code)-1) || code[0] == '#') ? printf("%s\n", code) : printf("%s;\n", code);
    } 
    return 0;
}