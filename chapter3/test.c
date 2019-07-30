#include <stdio.h>
#include <stdlib.h>

struct book {
    int num;
    struct {
        int num1;
    };
};

int main(void)
{
    struct book *b;
    b = malloc(sizeof(struct book));

    b->num = 100;
    b->num1 = 1000;

    printf("b->num1 = %d\n", b->num1);
    printf("b->num = %d\n", b->num);

    free(b);

    return 0;
}
