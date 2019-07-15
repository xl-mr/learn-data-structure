#ifndef SORTEDLIST_H
#define SORTEDLIST_H

#include <stdbool.h>

typedef int Item;
typedef struct DLinkList_node *LinkList;

LinkList InitList(void);
int ListLength(LinkList L);
bool GetNode(LinkList L, int i, Item *e);
int LocateNode(LinkList L, Item x);
bool InsertList(LinkList L, int i, Item e); 
bool deleteList(LinkList L, int i, Item *e);
void createListHead(LinkList L, int n);
void createListTail(LinkList L, int n);
void clearList(LinkList L);

#endif
