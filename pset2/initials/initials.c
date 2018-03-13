#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main (void)
{
   // printf("Enter a name:\n");
    string name = get_string();
    if ( name != NULL )
    {
        for( int i=0, n=strlen(name); i<n; i++)
        {
            if ( isspace(name[i]) )
            {
            while ( isspace(name[i]) )
                {
                    i++;
                }
            printf("%c", name[i]);
            }
            else if ( i == 0 ) printf("%c", name[0]);
        }
        printf("\n");
    }
}