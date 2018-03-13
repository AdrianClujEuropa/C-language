#include <cs50.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <ctype.h>

#define SECONDS_IN_YEAR (365LU*24LU*3600LU*9LU)

void Copy(char *h);
void Swap(int *x, int *y);

typedef struct
{
    string name;
    int age;
}
student;

int main(void)
{

    string y = "Hello, world\n";

    printf("%s\n", y);

    printf("Storage size for int : %lu bytes that is %lu x 8 biti \n", sizeof(int), sizeof(int));
    printf("Seconds in a year: %li\n", SECONDS_IN_YEAR);

    printf("enter sentence:");
    char *g = get_string();
    printf("enter sentence:");
    char *z = get_string();

    Copy(g);
    printf("%s\n", z);
    if ( strcmp(g, z) == 0 )
    {
        printf("same\n");
    }

    char *t = malloc((strlen(z)+1) * sizeof(char));

    for (int i = 0, m=strlen(z); i<=m; i++)
    {
        t[i]=z[i];
    }
    t[1]= toupper(t[1]);
    printf("%s\n", t);
    free(t);

    printf("give number a: ");
    int a = get_int();
    printf("give number b: ");
    int b = get_int();
    printf("swaping a and b\n");
    Swap(&a,&b);
    printf("a is %i\n", a);
    printf("b is %i\n", b);

    int *rr = malloc(sizeof(int));
    *rr = a + b;
    printf("Sum is %i\n", *rr);
    printf("%p\n",(void*)&rr);
    printf("freeing memory of sum\n");
    free(rr);
    printf("Sum is %i\n", *rr);
    int **foo = &rr;

    printf("%p\n", foo);
    printf("%p\n",(void*)&rr);

    int *ptr;
    ptr = (int *)foo;
    *ptr = 100;

    printf("new pointer shows value %i\n", *ptr);
    printf("%p\n",(void*)&ptr);

    int *test;
    test = malloc(sizeof(int));
    *test = 13;
    printf("%i\n", *test);
    free(test);

    int *teste=malloc(10*sizeof(int));
    for (int i=0; i<10; i++)
    {
        teste[i]=i;
    }

    for (int i=0; i<10; i++)
    {
        printf("%i , ", teste[i]);
    }
    free(teste);

    student student[2];

    student[0].name = "Adrian";
    student[0].age = 23;

    printf("%s, %i\n", student[0].name, student[0].age);

}

void Copy(char *h)
{
    int i = 0;
    do
    {
        printf("%c\n", h[i]);
        i++;
    } while ( h[i] != '\0' );
}

void Swap(int *x, int *y)
{
    int temp= *x;
    *x = *y;
    *y = temp;
}