#include <stdio.h>

int main(){
    int h1, h2, m1, m2;
    int dh = 0;
    int dm = 0;
    int result;
    scanf("%d:%d\n%d:%d", &h1, &m1, &h2, &m2);

    if(h2 > h1){
        dh = h2 - h1;
    }
    else if(h2 == h1){
        if(m2 < m1){
            dh = 24;
        }
        
    }
    else{
        dh = 24 + h2 - h1;
    }

    dm = m2 - m1;

    result = dh*60 + dm;

    printf("%d\n", result);
}