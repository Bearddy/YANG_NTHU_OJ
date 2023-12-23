#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int ans[10005];
int big[10005];
int N, M;

typedef struct{
    char name[33];
    char ocp[13];
    int big;
    int age;
} Cats;


int compare(const void* a, const void* b){
    Cats* c1 = (Cats*) a;
    Cats* c2 = (Cats*) b;

    if(c1->big != c2->big) return c1->big - c2->big;
    if(c1->age != c2->age){
        if(c1->big == 5) return c1->age - c2->age;
        return c2->age - c1->age;
    }
    return strcasecmp(c1->name, c2->name);
}

int rate(char *s);

int main() {

    while(~scanf("%d %d", &N, &M)){
        Cats *cats = (Cats*)malloc(sizeof(Cats)*N);
        for(int i = 0; i < N; i++){
            scanf("%s %s %d", cats[i].name, cats[i].ocp, &cats[i].age);
            cats[i].big = rate(cats[i].ocp);
        }
        qsort(cats, N, sizeof(Cats), compare);
        int temp = M > N ? N : M;
        for(int i = 0; i < temp; i++){
            printf("%s\n", cats[i].name);
        }
        free(cats);
    }
    return 0;
}


int rate(char *s){
    if(strcmp(s, "elder") == 0) return 1;
    if(strcmp(s, "nursy") == 0) return 2;
    if(strcmp(s, "kitty") == 0) return 3;
    if(strcmp(s, "warrior") == 0) return 4;
    if(strcmp(s, "apprentice") == 0) return 5;
    if(strcmp(s, "medicent") == 0) return 6;
    if(strcmp(s, "deputy") == 0) return 7;
    if(strcmp(s, "leader") == 0) return 8;
}
