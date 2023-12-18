#include <stdio.h>
#include <string.h>

#define MAX 550

char input[MAX];
int len = 0;
int cursor = 0;


int main()
{
    char temp[MAX], content[MAX] ={'\0'};

    fgets(input, MAX, stdin);

    len = strlen(input);
    for (int i = 0; i < len; i++) {

        if(input[i] == '/') {
            if(input[i+1] == 'b') {
                i += 9;
                if(cursor != 0){
                    strcpy(temp, content+cursor);
                    cursor--;
                    strcpy(content+cursor, temp);
                }
            }
            else if(input[i+1] == 'l') {
                i += 4;
                if(cursor != 0) cursor--;
            }
            else if(input[i+1] == 'r') {
                i += 5;
                if(cursor != 0) cursor++;
            }
            else if(input[i+1] == 'n') {
                i += 7;
                strcpy(temp, content+cursor);
                strcpy(content+cursor+1, temp);
                content[cursor++] = '\n';
            }
        }
        else {
            strcpy(temp, content+cursor);
            strcpy(content+cursor+1, temp);
            content[cursor++] = input[i];
        }
    }



    printf("%s", content);

    return 0;
}