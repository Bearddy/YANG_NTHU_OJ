#include <stdio.h>

int solve();

char brackets[505];

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        scanf("%s", brackets);
        int record = 0;
        printf(solve() ? "Yes\n" : "No\n");
    }
    return 0;
}

int solve(){
    int record = 0;
    for(int i = 0; brackets[i] != '\0'; i++){
        if(brackets[i] == '(') record++;
        else if(brackets[i] == ')') record--;

        if(record < 0) return 0;
    }

    if(record == 0) return 1;
    else return 0;
}