#include <stdio.h>

int binSearch(int *arr, int val, int len)
{
    int low, high, mid;

    low = 0;
    high = len;
    while (low <= high) {       
        mid = (low + high) / 2;
        if (arr[mid] > val) {
            high = mid - 1;
        } else if (arr[mid] < val) {
            low = mid + 1;
        } else {
            return mid;
        }
    }

    return -1;
}

int main(void)
{
    int arr[] = {13, 25, 36, 42, 48, 56, 64, 69, 78, 85, 92};

    printf("search res = %d\n", binSearch(arr, 42, 10));
    printf("search res = %d\n", binSearch(arr, 80, 10));

    return 0;
}
