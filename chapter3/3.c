#include <stdio.h>
#include <stdlib.h>

typedef int dataType;
typedef enum {atom, list} NodeTag;

typedef struct GLNode {
    NodeTag tag;
    union {
        dataType data;
        struct GLNode *slink;        
    };
    struct GLNode *next;
} *Glist;

Glist createGList(Glist GL)
{
    char ch;
    scanf("%c", &ch);

    if (ch != ' ') {
        GL = (struct GLNode *)malloc(sizeof(struct GLNode));
        if (ch == '(') {
            GL->tag = list;
            GL->slink = createGList(GL->slink);
        }  else {
            GL->tag = atom;
            GL->data = ch;
        }
    } else {
        GL = NULL;
    }
    
    if (GL != NULL) {
        scanf("%c", &ch);
        if (ch == ',') {
            GL->next = createGList(GL->next);
        } else {
            GL->next = NULL;
        }
    }

    return GL;
}

void printGList(Glist GL)
{
    if (GL != NULL) {
        if (GL->tag == list) {
            printf("(");
            if (GL->slink != NULL) {
                printGList(GL->slink);
            } else {
                printf(" ");
            }
        } else {
            printf("%c", GL->data);
        }

        if (GL->tag == list) {
            printf(")");
        }
        if (GL->next != NULL) {
            printf(",");
            printGList(GL->next);
        }
    }
}

int main(void)
{
    Glist GL = NULL;
    GL = createGList(GL);

    printGList(GL);
    printf("\n");

    return 0;
}
