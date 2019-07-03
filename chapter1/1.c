#include <stdio.h>

long fact(int n);

int main(void)
{
    long f = fact(5);
    printf("%ld\n", f);

    return 0;
}

long fact(int n) 
{
    if (n == 1) {
        return 1;
    }
    return n * fact(n - 1);
}
