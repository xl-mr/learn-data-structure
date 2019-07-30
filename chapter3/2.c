#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 1000

typedef struct {
    int row;
    int col;
    int val;
} TriTupleNode;

typedef struct ts{
    TriTupleNode data[MAXSIZE];
    int m, n, t;
} TSMatrix;

int main(void)
{
    int arr[4][5] = {
        {0, 3, 0, 5, 0},
        {0, 0, -2, 0, 0},
        {1, 0, 0, 0, 6},
        {0, 0, 8, 0, 0}
    };

    int i,j,k;
    TSMatrix *b;

    b = malloc(sizeof(struct ts));
    
    k = 0;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 5; j++) {
            if (arr[i][j] != 0) {
                b->data[k].row = i;
                b->data[k].col = j;
                b->data[k].val = arr[i][j];
                k++;
            }
        }
    }
    b->m = i;
    b->n = j;
    b->t = k;

    for (i = 0; i < b->t; i++) {
        printf("%d ", b->data[i].val);
    }

    printf("\n");

    free(b);

    return 0;
}
