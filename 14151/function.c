#include <stdio.h>
#include <stdlib.h>
#include "function.h"




Table* createTable(){

    Table *newTable = (Table*)malloc(sizeof(Table));
    scanf("%d", &newTable->tableSize);
    newTable->leaveTime = 0;
    newTable->guest = NULL;
    return newTable;
}


Guest* createGuest(){
    Guest *newGuest = (Guest*)malloc(sizeof(Guest));
    newGuest->guestName = (char*)malloc(11 * sizeof(char));

    scanf("%s %d %d %d", newGuest->guestName, &newGuest->groupSize, &newGuest->arriveTime, &newGuest->diningTime);

    return newGuest;
}

Guest* checkLeave(Table **table, int tableCount, int currentTime){
    for (int i = 0; i < tableCount; i++) {
        if (table[i]->guest != NULL && table[i]->leaveTime == currentTime) {
            Guest *leavingGuest = table[i]->guest;
            table[i]->guest = NULL;
            return leavingGuest;
        }
    }
    return NULL;
}

int assignTable(Table **table, int tableCount, int currentTime, Guest *guest){
    for (int i = 0; i < tableCount; i++) {
        if (table[i]->guest == NULL && table[i]->tableSize >= guest->groupSize) {
            table[i]->leaveTime = currentTime + guest->diningTime;
            table[i]->guest = guest;
            return 1;
        }
    }
    return 0;
}