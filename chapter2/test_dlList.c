#include <stdio.h>
#include "DLinkList.h"

int main(void) 
{
    int i, len;
    Item e;
    LinkList L;
    L = InitList();
    
    for (i = 1; i <= 10; i++) {
        InsertList(L, i, i);
    }

    len = ListLength(L);
    printf("Len = %d\n", len);

    for (i = 1; i <= 10; i++) {
        if (GetNode(L, i, &e)) {
            printf("%d ", e);
        } else {
            printf("not found!\n");
        }
    }
    printf("\n");

    clearList(L);

    return 0;
}
