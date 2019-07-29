#include <stdio.h>

#define N 5

void create(int (*arr)[5], int n);

int main(void)
{
    int i, j;
    int arr[5][5];
    create(arr, 5);

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("%d  ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}

void create(int (*arr)[5], int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = i; j < n; j++) {
            arr[i][j] = arr[j][i] = j;
        }
    }
}
