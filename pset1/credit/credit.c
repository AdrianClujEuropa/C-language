#include <cs50.h>
#include <stdio.h>
#include <math.h>

bool checksum();

int main(void)
{
    printf("We are going to checksum your credit card. Please enter card number : \n");
    long long h = get_long_long();

    int a = log10(llabs(h)) + 1;

    long long o = llabs(h);
    while ( o >= 10)
        o /= 10;


    bool tru = checksum(h);

    if ( !tru ) printf("INVALID\n");
        else {
            switch (a)
            {
                case (15): printf("AMEX\n"); break;
                case (16): if ( o == 4) printf("VISA\n");
                            else printf("MASTERCARD\n"); break;
                case (13): printf("VISA\n"); break;
                default : printf("INVALID\n"); break;
            }
        }
}

bool checksum(long long n)
{
    int s = 0;


    while ( n >= 10 )
    {
        s += n % 10 ;
        long long v = (((n % 100) / 10) * 2);
        if ( v < 10)
            {
                s += v;
            }
            else
            {
                s += (v % 10) + (v / 10);
            };
        n = n/100;
    }
    s += n % 10;

    return ( s % 10 == 0 );
}