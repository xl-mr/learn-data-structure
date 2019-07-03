#include "SortedList.h"

#define LIST_SIZE 100

struct List {
    Item data[LIST_SIZE];   
    int length;
};

void InitList(SqList L)
{
    L->length = 0;
}

int ListLength(SqList L)
{
    return L->length;
}

Item GetNode(SqList L, int i)
{

}

int LocateNode(SqList L, Item x)
{

}

bool InsertList(SqList L, int i, Item x)
{

}

bool deleteList(SqList L, int i)
{
    
}
