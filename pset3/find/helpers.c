/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */

#include <cs50.h>

#include "helpers.h"
#include <stdio.h>

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    // TODO: implement a searching algorithm
    //  n is even or uneven
    //  when it's uneven we keep the rightpart larger
    // when n is 2 or 1 the program checks if value is in values.
    // the program ckecks if value is in the middle of values every time the array gets "split"

    if ( n < 2 )
    {
        if (values[0]==value) return true;
        else return false;
    }

    if ( n == 2)
    {
        if (values[0] == value || values[1] == value)
            return true;
        else return false;
    }

    // open to the middle of haystack and checks that value
    int index= n/2;
    if ( values[index] == value )
    {
      //  printf("l-am gasit, %i\n", value);
        return true;
    }

    // if the value is in the fist half of the haystack
    // creates an array which equals to the first half of haystack
    // tha function calls itself with its new array as input
    if ( value < values[index] )
    {
        int leftpart[index];
        for ( int i=0; i<index; i++)
        {
            leftpart[i]= values[i];
        }
        return search(value, leftpart, index);
    }
    if ( value > values[index] )
    {
        if ( n%2 == 0)
        {
            int rightpart[index];
            for ( int i=index, x=0; i<=n; i++,x++)
            {
                rightpart[x]= values[i];
            }
            return search(value, rightpart, index);
        }
        if ( n%2 != 0)
        {
           int rightpart[index+1];
            for ( int i=index, x=0; i<=n; i++, x++)
            {
                rightpart[x]= values[i];
            }
            return search(value, rightpart, (index+1));
        }
    }

    return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // TODO: implement a sorting algorithm
    // in pos_count array we keep the number of times each number apears in the given array
    // the element's position in this array shows the number, it's position is the number.
    int max= 65536;
    // Initializing an array to zero to prevent unwanted numbers in array
    int pos_count[max];
    for (int i=0; i<max; i++)
    {
        pos_count[i]=0;
    }
    for ( int i = 0; i<n; i++)
    {
        int p = values[i];
        pos_count[p] += 1;
    }

    int z = 0;
    for (int i=0; i<max; i++)
    {
        if ( pos_count[i] != 0 )
        {
            for ( int j=0, y=pos_count[i]; j<y; j++ )
            {
                values[z]= i;
                z++;
            }
        }


    }

    return;
}
