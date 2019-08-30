#include <stdio.h>
//#include "sort.h"

void insertSort(int R[], int n) 
{
    int i,j, temp;
    for (i = 1; i < n; i++) {
        if (R[i] < R[i - 1]) {
            temp = R[i];
            for (j = i - 1; temp < R[j]; j--) {
                R[j + 1] = R[j];
            }   
            R[j + 1] = temp;
        }
    }
}

int main(void)
{
    int i;
    int arr[] = {46, 39, 17, 23, 28, 55, 18, 46};
    printf("sort before: ");
    for (i = 0; i < 8; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    insertSort(arr, 8);

    printf("sort  after: ");
    for (i = 0; i < 8; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
