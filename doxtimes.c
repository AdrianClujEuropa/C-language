#include <cs50.h>
#include <stdio.h>

void ccc(int n);
void say(string s, int n);
void bbb(int n);


int main(void)
{
    ccc(3);
    bbb(9);
}

void ccc(int n)
{
    say("ccc\n", n);
}

void bbb(int n)
{
    say("bbb\n", n);
}

void say(string s, int n)
{
    for (int i=0; i<n; i++)
    {
        printf("%s\n", s);
    }
}