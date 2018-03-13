#include <cs50.h>
#include <stdio.h>


int main(void)
{

    printf("x is :");
    float x = get_float();

    printf("y is :");
    float y = get_float();

    printf("the sum is %f\n", x + y);
    printf("%f divided by %f is %f\n", x, y, x/y );
}