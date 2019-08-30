#include <stdio.h>

int partition(int arr[], int low, int high)
{
    int temp;

    temp = arr[low];

    while (low < high) {
        while (low < high && arr[high] >= temp) {
            high--;
        }
        if (low < high) {
            arr[low] = arr[high];
            low++;
        }
        while (low < high && arr[low] <= temp) {
            low++;
        }
        if (low < high) {
            arr[high] = arr[low];
            high--;
        }
    }

    arr[low] = temp;

    return low;
}

void quickSort(int arr[], int low, int high) 
{
    int p;
    if (low < high) {
        p = partition(arr, low, high);
        quickSort(arr, low, p - 1);
        quickSort(arr , p + 1, high);
    }
}

int main(void)
{
    int i, n = 10;
    int arr[] = {45, 53, 18, 36, 76, 32, 49, 97, 13, 36};
    printf("sort before: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    quickSort(arr, 0, n - 1);

    printf("sort  after: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
