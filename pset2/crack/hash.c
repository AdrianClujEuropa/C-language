#define _XOPEN_SOURCE
#include <cs50.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>


int main( int argc, string argv[] )
{
    if ( argc != 2 )
    {
        printf("Usage: ./hash string_to_hash\n");
        return 1;
    }

    char salt[]= "50";

    string namestring= argv[1];


    ////////////////////////////////////////////////////////////////////////////////////////
    string generated_hashed;

    generated_hashed = crypt(namestring,salt);

    printf("the hash is: %s\n", generated_hashed);

    printf("length is: %lu\n", strlen(generated_hashed));


}

