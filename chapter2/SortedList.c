#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "SortedList.h"

#define LIST_SIZE 100

struct List {
    Item data[LIST_SIZE];   
    int length;
};

SqList InitList(void)
{
    SqList L = malloc(sizeof(struct List));
    if (L == NULL) {
        return NULL;
    }
    L->length = 0;

    return L;
}

int ListLength(SqList L)
{
    return L->length;
}

Item GetNode(SqList L, int i)
{
    if (L->length == 0 || i < 1 || i > L->length) {
        //TODO 暂定-1 表示错误
        return -1;
    }
    return L->data[i - 1];
}

int LocateNode(SqList L, Item x)
{
    int i, index = -1;  //表示没有找到
    for (i = 0; i < L->length; i++) {
        if (L->data[i] == x) {
            index = i;
        }
    }

    return index;
}

bool InsertList(SqList L, int i, Item x)
{
    int j;
    if (L->length == LIST_SIZE) {
        return false;
    }
    if (i < 1 || i > L->length + 1) {
        return false;
    }
    if (i <= L->length) {
        for (j = L->length - 1; j >= 0; j--) {
            L->data[j + 1] = L->data[j];
        }
    }
    L->data[i - 1] = x;
    L->length++;

    return true;
}

bool deleteList(SqList L, int i)
{
    int j;
    if (L->length == 0) {
        return false;
    }  
    if (i < 1 || i > L->length) {
        return false;
    }
    if (i <= L->length) {       
        for (j = i - 1; j < L->length; j++) {
            L->data[j] = L->data[j + 1];
        }
    }
    L->length--;

    return true;
}

void converts(SqList L)
{
    int i, j, len, temp;
        
    len = ListLength(L);
    
    for (i = 0, j = len - 1; i < len / 2; i++, j--) {
        temp = L->data[i];
        L->data[i] = L->data[j];
        L->data[j] = temp;
    }
}
