#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>


// argc is the number of arguments passed and argv is the list of arguments passed
// example ./vigenere team rocket  argc would be 3, argv[0] would be ./vigenere etc
int main( int argc, string argv[])
{
    if ( argc != 2 )
    {
        printf("Usage: ./caesar k\n");
        return 1;
    }
    int k = atoi(argv[1]);

    printf("plaintext:");
    string text = get_string();
    if ( text != NULL)
    {
    printf("ciphertext:");
        int cipher;
        int ascii;
        for (int i=0, n=strlen(text); i<n; i++ )
            {
            if ( (text[i] >= 'A') && (text[i] <= 'Z') )
                {
                cipher= ((text[i]-65)+k)%26;
                ascii= cipher+65;
                printf("%c", ascii);
                }

            if ( (text[i] >= 'a') && (text[i] <= 'z') )
                {
                cipher= ((text[i]-97)+k)%26;
                ascii= cipher+97;
                printf("%c", ascii);
                }
            if ( !((text[i] >= 'A') && (text[i] <= 'Z')) && !( (text[i] >= 'a') && (text[i] <= 'z') ) )
                {
                    printf("%c", text[i]);
                }
            }
    printf("\n");
    return 0;
    }


}