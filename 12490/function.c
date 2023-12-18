#include "function.h"
#include <stdio.h>

int solver(int **ptr, int *sum, char *s){
    int temp_num = 0;
    int count = 0;
    int index = 0;
    int minus = 0;
    for(int i = 0; s[i] != '\0'; i++){
        
        if(isdigit(s[i]) || s[i] == '-'){
            if(isdigit(s[i])){
                temp_num = temp_num*10 + s[i] - '0';
            }
            else{
                minus = 1;
            }
            
            if(isdigit(s[i+1]) != 1){
                if(minus == 1){
                    temp_num *= -1;
                    minus = 0;
                }
                count++;
                *ptr[index++] = temp_num;
                *sum += temp_num;
                temp_num = 0;
            }
        }
        
        //printf("temp : %d\n", temp_num);
    }

    return count;

}