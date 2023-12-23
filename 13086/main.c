#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Fib {
    char word[2048];
    long long int len;
    struct _Fib *a;
    struct _Fib *b;
} Fib;

int main() {
    int T;
    scanf("%d", &T);

    while(T--){
        Fib *sentence = (Fib*)malloc(sizeof(Fib)*60);
        sentence[0].a = NULL;
        sentence[1].a = NULL;

        long long int prt_idx, arr_idx;

        scanf("%s %s", sentence[0].word, sentence[1].word);

        for(int i = 0; i < 2; i++){
            sentence[i].len = strlen(sentence[i].word);
        }

        scanf("%lld %lld", &arr_idx, &prt_idx);

        for(int i = 2; i <= arr_idx; i++){
            sentence[i].len = sentence[i-1].len + sentence[i-2].len;
            sentence[i].a = &sentence[i-2];
            sentence[i].b = &sentence[i-1];
        }

        Fib *cur = &sentence[arr_idx];
        while(cur->a != NULL){
            if(cur->a->len > prt_idx){
                cur = cur->a;
            }
            else{
                prt_idx -= cur->a->len;
                cur = cur->b;
            }
        }

        printf("%c\n", cur->word[prt_idx]);
        free(sentence);

    }
    return 0;
}
