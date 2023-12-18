#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "function.h"

Item* CreateList(int N){
    return (Item*)malloc(N*sizeof(Item));
}
void AddItem( Item* L, int idx, char* name, int price, int discount, int quality ){
    L[idx].name = (char*)malloc(sizeof(char)* 101);
    strcpy(L[idx].name, name);
    L[idx].price = price;
    L[idx].discount = discount;
    L[idx].quality = quality;
}
void DeleteList(Item* L, int N){
    for (int i = 0; i < N; i++) {
        free(L[i].name);
    }
    free(L);
}

int price_cmp(const void* lhs, const void* rhs) {
    return (((Item*)lhs)->price - ((Item*)lhs)->discount) - (((Item*)rhs)->price - ((Item*)rhs)->discount);
}

int discount_cmp(const void* lhs, const void* rhs) {
    return ((Item*)rhs)->discount - ((Item*)lhs)->discount;
}

int quality_cmp(const void* lhs, const void* rhs) {
    return ((Item*)rhs)->quality - ((Item*)lhs)->quality;
}
