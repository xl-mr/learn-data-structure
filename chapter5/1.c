#include <stdio.h>
#include <limits.h>

#define MAX_VERTEX_NUM 50

typedef char vertexType;
typedef int edgeType;

typedef struct {
    vertexType vexs[MAX_VERTEX_NUM];
    edgeType arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
    int edgeNums, vertexNum;
} MGraph;

void createMGraph(MGraph *G)
{
    int i, j, k, w;

    scanf("%d,%d", &G->vertexNum, &G->edgeNums);
    printf("v = %d, e = %d\n", G->vertexNum, G->edgeNums);

    for (i = 0; i < G->vertexNum; i++) {
        scanf(" %c", &G->vexs[i]);
        //printf("%c, i = %d", G->vexs[i], i);
    }

    for (i = 0; i < G->vertexNum; i++) {
        for (j = 0; j < G->vertexNum; j++) {
            G->arcs[i][j] = INT_MAX;
        }
    }

    for (k = 0; k < G->edgeNums; k++) {
        printf("输入边(vi, vj)上的下标i,下标j和权:\n");
        scanf("%d,%d,%d", &i, &j, &w);
        G->arcs[i][j] = w;
        G->arcs[j][i] = w;
    }
}

int main(void)
{
    int i, j;
    MGraph G;
    createMGraph(&G);

    for (i = 0; i < G.vertexNum; i++) {
        for (j = 0; j < G.vertexNum; j++) {
            printf("%d ", G.arcs[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
