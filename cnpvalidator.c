#include <cs50.h>
#include <stdio.h>
#include <math.h>

bool checksum();

int main(void)
{
    printf("We are going to checksum your cnp code. Please enter cnp number : \n");
    long long h = get_long_long();

    bool tru = checksum(h);

    if (tru) printf("cnp VALID\n");
        else printf("cpn INVALID\n");

}

bool checksum(long long n)
{
    int a = log10(llabs(n)) + 1;

    if ( a != 13) return false;

        else
            {
            int c = ( n % 10 );
            long long k = 279146358279;
            n /= 10;

            int s = 0;

            while ( n > 0)
                {
                    s += (( n % 10 ) * ( k % 10));
                    n /= 10;
                    k /= 10;
                }

            return ( (s % 11) == (c) );

            }
}
