#include <stdio.h>
#include <stdlib.h>
#include "SortedList.h"

int main(void)
{
    SqList L;
    L = InitList();
    free(L);

    return 0;
}
