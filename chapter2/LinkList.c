#include <stdlib.h>
#include <stdbool.h>
#include "LinkList.h"

struct node {
    Item data;
    struct node *next;
};

struct LinkList_node {
    struct node *head;
    //int length;
};

LinkList InitList(void) {
    LinkList L = malloc(sizeof(struct LinkList_node));   
    if (L == NULL) {
        return NULL;
    }
    L->head = NULL;

    return L;
}

int ListLength(LinkList L) {
    int i = 0;
    struct node *p = L->head;
    while (p != NULL) {
        p = p->next;
        i++;
    }

    return i;
}

bool GetNode(LinkList L, int i, Item *e) {
    struct node *p = L->head;

    if (i < 1 || i > ListLength(L)) {
        return false;
    }

    while (i-- > 1 && p != NULL) {
        p = p->next;
    }

    if (p == NULL) {
        return false;
    }
    *e = p->data;

    return true;
}

int LocateNode(LinkList L, Item x)
{
    int index = 0;
    struct node *p = L->head;
    while (p != NULL) {
        index++;
        if (p->data == x) {
            return index;
        }
        p = p->next;
    }

    return index;
}

bool InsertList(LinkList L, int i, Item e) {
    int j;
    struct node *p = L->head, *head = p;
    if (i < 1 || i > ListLength(L)) {
        return false;
    }

    i--;
    j = 1;
    while (p != NULL && i > j) {
        p = p->next;
        j++;
    }
    if (p == NULL) {
        return false;
    }
    struct node *new_node = malloc(sizeof(struct node));
    new_node->data = e;

    if (head == p) {
        new_node->next = p;
        L->head = new_node;
    } else {
        p->next = new_node;
    }

    return true;
}

bool deleteList(LinkList L, int i, Item *e) {

}
void createListHead(LinkList L, int n) {

}

void createListTail(LinkList L, int n) {

}

