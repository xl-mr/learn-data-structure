#include <stdio.h>

int binSearch(int *arr, int val, int low, int high)
{
    int mid;
    if (low <= high) {
        mid = (low + high) / 2;
        if (arr[mid] > val) {
            return binSearch(arr, val, low, mid - 1);
        } else if (arr[mid] < val) {
            return binSearch(arr, val, mid + 1, high);
        } else {
            return mid;
        }
    } else {
        return -1;
    }
}

int main(void)
{
    int arr[] = {13, 25, 36, 42, 48, 56, 64, 69, 78, 85, 92};

    printf("search res = %d\n", binSearch(arr, 42, 0, 10));

    return 0;
}
