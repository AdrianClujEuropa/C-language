#include <cs50.h>
#include <stdio.h>


int main(void)
{
    int x = 1;
    for (int i=0; i<64; i++){
        printf("x is %i\n", x);
        x = x * 2;
    }
}