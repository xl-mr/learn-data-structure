#include <stdio.h>

#define n 4
#define m 2 * n - 1

typedef struct {
    float weight;
    int lchild, rchild, parent;
} HTNode;

typedef HTNode HuffmanTree[m+1];

void select(HuffmanTree T, int k, int *s1, int *s2) {
    int i, j, min;

    min = T[1].weight;
    for (i = 1; i <= k; i++) {
        if (T[i].weight < min && T[i].parent == 0) {
            j = i;
            min = T[i].weight;
        }
    }
    *s1 = j;

    min = T[1].weight;
    for (i = 1; i <= k; i++) {
        if (T[i].weight < min && T[i].parent == 0 && i != *s1) {
            j = i;
            min = T[i].weight;
        }
    }
    *s2 = j;
}

void createHuffmanTree(HuffmanTree T) 
{
    int s1, s2, i;

    //init 0
    for (i = 1; i <= m; i++) {
        T[i].weight = 0;
        T[i].lchild = 0;
        T[i].rchild = 0;
        T[i].parent = 0;
    }

    for (i = 1; i <= n; i++) {
        scanf("%f", &T[i].weight);
    }

    for (i = n + 1; i <= m; i++) {
        select(T, i - 1, &s1, &s2);
        T[s1].parent = i;
        T[s2].parent = i;
        T[i].lchild = s1;
        T[i].rchild = s2;
        T[i].weight = T[s1].weight + T[s2].weight;
    }
}

int main(void)
{
    int i;
    HuffmanTree HT;
    createHuffmanTree(HT);
    
    for (i = 1; i <= m; i++) {
        printf("%.2f ", HT[i].weight);
    }
    printf("\n");
    
    return 0;
}
