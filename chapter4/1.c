#include <stdio.h>
#include <stdlib.h>

typedef int dataType;
typedef struct node {
    dataType data;
    struct node *lchild, *rchild;
} BinTNode;

typedef BinTNode *BinTree;

void createBinTree(BinTree *T)
{
    char ch;
    scanf("%c", &ch);

    if (ch == '#') {
        *T = NULL;
    } else {
        *T = malloc(sizeof(struct node));
        if (*T == NULL) {
            exit(EXIT_FAILURE);
        }
        (*T)->data = ch;
        createBinTree(&(*T)->lchild);
        createBinTree(&(*T)->rchild);
    }
}

//前序 DLR
void preOrder(BinTree *T)
{
    if (*T != NULL) {
        printf("%c", (*T)->data);
        preOrder(&(*T)->lchild);
        preOrder(&(*T)->rchild);
    }
}

//中序 LDR
void inOrder(BinTree *T)
{

    if (*T != NULL) {
        inOrder(&(*T)->lchild);
        printf("%c", (*T)->data);
        inOrder(&(*T)->rchild);
    }
}

//后序 LRD
void postOrder(BinTree *T)
{
    if (*T != NULL) {
        postOrder(&(*T)->lchild);
        postOrder(&(*T)->rchild);
        printf("%c", (*T)->data);
    }

}



int main(void)
{
    BinTree T;
    createBinTree(&T);

    preOrder(&T);
    printf("\n");

    inOrder(&T);
    printf("\n");

    postOrder(&T);
    printf("\n");

    return 1;
}
