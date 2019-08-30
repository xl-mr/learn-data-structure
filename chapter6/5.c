#include <stdio.h>
#include <stdbool.h>

void selectSort(int arr[], int n) 
{
    int i,j, minIndex, temp;
    for (i = 0; i < n; i++) {
        minIndex = i;
        for (j = i + 1; j < n; j++) {
            if (arr[minIndex] > arr[j]) {
                minIndex = j;
            }
        }
        if (i != minIndex) {
            temp = arr[minIndex];
            arr[minIndex] = arr[i];
            arr[i] = temp;
        }
    }
}

int main(void)
{
    int i, n = 8;
    int arr[] = {38, 33, 65, 82, 76, 38, 24, 11};
    printf("sort before: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    selectSort(arr, n);

    printf("sort  after: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
