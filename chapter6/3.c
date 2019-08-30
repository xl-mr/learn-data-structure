#include <stdio.h>
#include <stdbool.h>

void bubbleSort(int arr[], int n) 
{
    int i,j, temp;
    bool flag;
    for (i = 0; i < n; i++) {
        flag = false;
        for (j = n - 1; j >= i; j--) {
            if (arr[j] < arr[j - 1]) {
                temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
                flag = true;
            }
        }
        if (!flag) {
            return;
        }
    }
}

int main(void)
{
    int i, n = 8;
    int arr[] = {36, 28, 45, 13, 67, 36, 18, 56};
    printf("sort before: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    bubbleSort(arr, n);

    printf("sort  after: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
