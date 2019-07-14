#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "cirList.h"

struct node {
    Item data;
    struct node *next;
};

struct CirList_node {
    struct node *head;
    int length;
};

LinkList InitList(void) {
    LinkList L = (struct CirList_node *)malloc(sizeof(struct CirList_node));   
    if (L == NULL) {
        return NULL;
    }
    L->head = NULL;
    L->length = 0;

    return L;
}

int ListLength(LinkList L) {
    /**
    int i = 0;
    struct node *p = L->head;
    while (p != NULL) {
        p = p->next;
        i++;
    }

    return i;
    **/
    return L->length;
}

bool GetNode(LinkList L, int i, Item *e) {
    struct node *p = L->head;

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
    struct node *p = L->head, *head = p, *new_node = NULL;

    j = 1;
    while (p != NULL && p->next != head && (i - 1) > j) {
        p = p->next;
        j++;
    }
    if (j > i || i < 1) {
        return false;
    }
    new_node = (struct node *)calloc(1, sizeof(struct node));
    if (new_node == NULL) {
        return false;
    }
    new_node->data = e;

    if (L->head == NULL) {
        L->head = new_node;
        new_node->next = L->head;
    } else {
        new_node->next = p->next;
        p->next = new_node;
    }
    L->length++;

    return true;
}

bool deleteList(LinkList L, int i, Item *e) {
    int j;
    struct node *p = L->head, *head = p, *q;
    
    if (i < 1 || ListLength(L) == 0) {
        return false;
    }

    j = 1;
    while (p->next != head && (i - 1) > j) {
        p = p->next;
        j++;
    }
    if (p == NULL) {
        return false;
    }

    q = p->next;
    p->next = q->next;
    *e = q->data;
    free(q);
    L->length--;

    return true;
}

void createListHead(LinkList L, int n) {
    int i;
    struct node *p = L->head, *new_node;   

    for (i = 0; i < n; i++) {
        new_node = malloc(sizeof(struct node));
        if (new_node == NULL) {
            fprintf(stderr, "Memory not enough.\n");
            exit(0);
        }
        new_node->data = i;

        new_node->next = p;
        p = new_node;
        L->length++;
    }
    L->head = new_node;
}

void createListTail(LinkList L, int n) {
    int i;
    struct node *p, *head, *new_node;   

    p = malloc(sizeof(struct node));
    if (p == NULL) {
        fprintf(stderr, "not enough for memory.\n");
        exit(0);
    }
    p->data = 0;
    head = p;
    
    for (i = 1; i < n; i++) {
        //printf("%d ", i);
        new_node = malloc(sizeof(struct node));
        if (new_node == NULL) {
            fprintf(stderr, "not enough for memory.\n");
            exit(0);
        }
        new_node->data = i;
        
        p->next = new_node;
        p = new_node;
        L->length++;
    }
    L->head = head;
}

void clearList(LinkList L)
{
    struct node *p, *head, *q = NULL;
    p = L->head;
    head = p;
    
    while (p != NULL && p->next != head && L->length > 0)  { 
        q = p;
        p = p->next;
        free(q);
        L->length--;
    }

    free(p);
    L->length--;
    L->head = NULL;

    free(L);
}
