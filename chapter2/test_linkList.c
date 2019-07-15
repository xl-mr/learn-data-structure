#include <stdio.h>
#include <stdbool.h>
#include "LinkList.h"

int main(void)
{
    int i, len;
    Item e;
    bool check;
    LinkList L;

    L = InitList();

    createListTail(L, 10);
    //createListHead(L, 10);

    len = ListLength(L);
    printf("len = %d\n", len);

    for (i = 0; i < ListLength(L); i++) {
        check = GetNode(L, i + 1, &e);
        if (check) {
            printf("%d ", e);
        } else {
            printf("not found\n");
        }
    }

    printf("\n");

    for (i = 1; i < 10; i++) {
        InsertList(L, i, i);
    }

    deleteList(L, 3, &e);
    deleteList(L, 5, &e);
    deleteList(L, 7, &e);
    
    len = ListLength(L);
    printf("len = %d\n", len);

    for (i = 0; i < ListLength(L); i++) {
        check = GetNode(L, i + 1, &e);
        if (check) {
            printf("%d ", e);
        } else {
            printf("not found\n");
        }
    }   

    printf("\n");

    clearList(L);

    return 0;
}
