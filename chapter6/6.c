#include <stdio.h>

void heapAdjust(int arr[], int i, int len)
{
    int j, temp;
    temp = arr[i];

    for (j = 2 * i; j <= len; j *= 2) {
        if (j < len && arr[j] < arr[j+1]) {
            j++;
        }

        if (temp >= arr[j]) {
            break;
        }
        arr[i] = arr[j];
        i = j;
    }
    arr[i] = temp;
}

void heapSort(int arr[], int n) 
{
    int i;

    for (i = n / 2; i > 0; i--) {
        heapAdjust(arr, i, n);
    }

    for (i = n; i > 1; i--) {
        int temp = arr[i];
        arr[i] = arr[1];
        arr[1] = temp;
        //for (i = 1; i < n; i++) {
        //    printf("%d ", arr[i]);
        //}
        //printf("\n");
        heapAdjust(arr, 1, i - 1);
        //for (i = 1; i < n; i++) {
        //    printf("%d ", arr[i]);
        //}
        //printf("\n");
    }
}


int main(void)
{
    int i, n = 9;
    int arr[] = {0,47, 33, 11, 56, 72, 61, 25, 47};
    printf("sort before: ");
    for (i = 1; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    heapSort(arr, 8);

    printf("sort  after: ");
    for (i = 1; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
