/**
 * this program adds numbers
 *
 */

#include <cs50.h>
#include <stdio.h>

int sigma (int m);

int main ( void )
{
    int n;
    do
    {
        printf("positive integer please: ");
        n= get_int();
    }
    while (n<1);

    int answer= sigma(n);
    printf("%i\n", answer);
}

int sigma ( m )
{
    if ( m <= 0 )
    {
        return 0;
    }
    else
    {
        return(m + sigma(m-1));
    }
}