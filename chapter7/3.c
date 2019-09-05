#include <stdio.h>

int h(int key)
{
    return key % 11;
}

int main(void)
{
    int i;
    int arr[] = {31, 62, 74, 36, 49, 77};
    int ha[11] = {0};

    for (i = 0; i < 6; i++) {
        ha[h(arr[i])] = arr[i];
    }

    for (i = 0; i < 11; i++) {
        printf("%d ", ha[i]);
    }
    printf("\n");
    
    return 0;
}
