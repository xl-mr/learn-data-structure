#include <stdio.h>

void shellInsert(int arr[], int dk, int n)
{
    int i, j, temp;
    for (i = dk; i < n; i++) {
        if (arr[i] < arr[i - dk]) {
            temp = arr[i];
            
            for (j = i - dk; j >= 0 && temp < arr[j]; j -= dk) {
                arr[j + dk] = arr[j];
            }

            arr[j + dk] = temp;
        }
    }
}

void shellSort(int arr[], int n) 
{
    int i;
    for (i = 5; i >= 1; i -= 2) {
        shellInsert(arr, i, n);
    }
}

int main(void)
{
    int i, n = 10;
    int arr[] = {36, 25, 48, 27, 65, 25, 43, 58, 76, 32};
    printf("sort before: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    //shellInsert(arr, 5, n);
    //shellInsert(arr, 3, n);
    //shellInsert(arr, 1, n);
    shellSort(arr, n);

    printf("sort  after: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
