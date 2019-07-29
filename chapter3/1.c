#include <stdio.h>

#define N 5

void create(int (*arr)[N], int n);
void print_r(int arr[][N]);

int main(void)
{
    int len = N * (N + 1) / 2;
    int arr[N][N], arr1[len];
    create(arr, N);
    print_r(arr);


    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i > j) {
                //arr1[i * (i + 1) / 2 + j] = arr[i][j];
            } else {
                //printf("i = %d j = %d, j * (j + 1) / 2 + i = %d \n ", i , j, j * (j + 1) / 2 + i);
                arr1[j * (j + 1) / 2 + i] = arr[i][j];
            }
        }
    }

    for (int k = 0; k < len; k++) {
        printf("%d ", arr1[k]);
    }
    printf("\n");

    return 0;
}

void create(int (*arr)[N], int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = i; j < n; j++) {
            arr[i][j] = arr[j][i] = j;
        }
    }
}

void print_r(int arr[][N])
{
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("%d  ", arr[i][j]);
        }
        printf("\n");
    }
}
