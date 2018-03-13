/**
 * this program sorts numbers
 *
 */

#include <cs50.h>
#include <stdio.h>

void sigma (int values[], int m);
//void sort(int values[], int n);

int main ( void )
{
    int n;
    do
    {
        printf("positive integer please: ");
        n= get_int();
    }
    while (n<1);

 //   int answer= sigma(n);
 //   printf("%i\n", answer);

    int haystack[10] = {60,8,6,2,1,7,5,3,3,3};

    sigma(haystack, 10);

}

// gets array
void sigma ( int values[], int m )
{
    // in this array we keep the number of times each number apears in the given array
    // the element's position in this array shows the number, it's position is the number.
    int max= 256;
    int pos_count[max];
    for (int i=0; i<max; i++)
    {
        pos_count[i]=0;
    }


    for ( int i = 0; i<m; i++)
    {
        int p = values[i];
        pos_count[p] += 1;
    }

    int z = 0;
    for (int i=0; i<max; i++)
    {
        if ( pos_count[i] != 0)
        {
            for ( int j=0, y=pos_count[i]; j<y; j++ )
            {
                printf("%i ,", i);
                values[z]= i;
                z++;
            }
        }


    }
}