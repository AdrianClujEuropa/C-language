#include <cs50.h>
#include <stdio.h>

void pyramid();

int main(void)
{
    printf("We are going to display some piramids. Enter the pyramids heigh, a number between 2 and 23: \n");
    int h = get_int();

    while ( h < 0 || h > 23) {
        printf("retry: ");
        h = get_int();
    }

    pyramid(h);

}



void pyramid(int n)
{
    for (int i = 1; i < n+1; i++)
        {
            for(int x = 0; x < (n-i); x++)
            {
                printf(" ");
            }
            for(int y = 0; y < i; y++)
            {
                printf("#");
            }
            printf("  ");
            for(int z = 0; z < i; z++)
            {
                printf("#");
            }
            printf("\n");
        }
}