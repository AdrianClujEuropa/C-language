#include <cs50.h>
#include <stdio.h>

int bottles();

int main(void)
{
    printf("Your time spent showering in minutes is: ");
    int n = get_int();

    int y = bottles(n);

    printf("This is equivalent to %i bottles of water per shower\n", y);

}

int bottles(int n)
{
    return n * 12 ;
}