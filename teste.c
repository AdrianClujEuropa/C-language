#include <cs50.h>
#include <stdio.h>
#include <math.h>


int main(void)
{
    printf("We are going to master unsigned value types : \n");

    unsigned int x = 0xABCDu;
    unsigned int zerocomp = 0xFFFF;
    unsigned int zero = 0x0000;

    printf("0xABCD is %u\n", x);
    printf("size of u int is %lu\n", sizeof(x));
    printf("0xFFFF in u int is %u\n", zerocomp);
    printf("0x0000 in u int is %u\n", zero);

    int *a = malloc(sizeof(int) * 10);
    int (*b)[10] = 0;

    a[0] = 4;

    printf("%i\n", a[0]);
    free(a);

    *b[0] = 4;
    printf("%i\n", *b[0]);
}

