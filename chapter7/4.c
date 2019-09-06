#include <stdio.h>

#define M 11
#define NULLKEY -32768

int hash(int key)
{
    return key % M;
}

void insertHash(int *arr, int key)
{
    int addr = hash(key);

    while (arr[addr] != NULLKEY) {
        addr = (addr + 1) % M;
    }
    arr[addr] = key;
}

void initHash(int *ht)
{
    int i;
    for (i= 0; i < 11; i++) {
        ht[i] = NULLKEY;
    }
}


int main(void)
{
    int i, ht[11], arr[] = {27, 13, 55, 32, 18, 49, 24, 38, 43};
    int len = sizeof(arr) / sizeof(arr[0]);

    initHash(ht);

    for (i = 0; i < len; i++) {
        insertHash(ht, arr[i]);
    }

    for (i = 0; i < 11; i++) {
        printf("%d ", ht[i]);
    }
    printf("\n");

    return 0;
}
