#ifndef SORTEDLIST_H
#define SORTEDLIST_H

#include <stdbool.h>

typedef int Item;
typedef struct List *SqList;

SqList InitList(void);
int ListLength(SqList L);
Item GetNode(SqList L, int i);
int LocateNode(SqList L, Item x);
bool InsertList(SqList L, int i, Item x); 
bool deleteList(SqList L, int i);

#endif
