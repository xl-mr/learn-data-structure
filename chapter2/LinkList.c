#include <stdio.h>
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

    i--;
    j = 1;
    while (p != NULL && i > j) {
        p = p->next;
        j++;
    }
    if (p == NULL || j > i) {
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
    int j;
    struct node *p = L->head, *temp;
    i--;
    j = 1;
    while (p != NULL && i > j) {
        p = p->next;
        j++;
    }
    if (p == NULL) {
        return false;
    }

    temp = p->next;
    p->next = temp->next;
    *e = temp->data;
    free(temp);

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
    }
    L->head = head;
}

