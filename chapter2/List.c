#include <stdio.h>
#include <stdlib.h>
#include "SortedList.h"

int main(void)
{
    int i;
    SqList L;
    L = InitList();

    for (i = 0; i < 10; i++) {
        InsertList(L, i + 1, i);       
    }

    deleteList(L, 5);

    for (i = 0; i < ListLength(L); i++) {
        printf("%d ", GetNode(L, i + 1));
    }
    printf("\n");

    printf("converts\n");
    for (i = 0; i < ListLength(L); i++) {
        printf("%d ", GetNode(L, i + 1));
    }
    printf("\n");

    free(L);

    return 0;
}
