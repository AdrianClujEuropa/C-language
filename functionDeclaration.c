#include <cs50.h>
#include <stdio.h>

void print_name(string name);

int main(void)
{
    printf("enter a name:\n");
    string p = get_string();
    print_name(p);

}

void print_name(string name)
{
    printf("the name is %s\n", name);
}