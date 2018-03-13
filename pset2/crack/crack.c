#define _XOPEN_SOURCE
#include <cs50.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>


int CheckHash(int, string, string);

int main( int argc, string argv[] )
{
    if ( argc != 2 )
    {
        printf("Usage: ./crack hash\n");
        return 1;
    }

//    string hashedpwd= argv[1];
//  SALT selects which algorithm is used, the MD5-based one or the DES-based one. it also prefixes the password adding a stept in cracking it
//    string salt= hashedpwd[0] + hashedpwd[1];

    char salt[]= "50";

    string hashedpwd= argv[1];

    ////////////////////////////////////////////////////////////////////////////////////////
    string generated_hashed;
        char namestring[5];
        char trie3[4];
        char trie2[3];

    int a = 0;
    int arr[4] = {'A','A','A','A'};

int h=0;

   // input for generated hash is max for letters
   // condition to not be more than four or not alph

   // iterate over virtual input
    for ( int n=0; n<52; n++)
    {
         for (int u=0; u<52; u++)
         {

            for (int m=0; m<52; m++)
            {

                for ( int e=0; e < 52; e++)
                {
                                for (int z=0; z<4; z++)
                                {
                                    namestring[z]=(char)arr[z];
                                }
                                    namestring[4]= '\0';
                                    h++;
                                generated_hashed = crypt(namestring,salt);
                                a= CheckHash(a, hashedpwd, generated_hashed);
                                if ( a == 0 )
                                    {
                                        printf("%s\n", namestring);
                                        break;
                                    }

                                    /// check for a three letter password :)
                                            for (int z=0; z<3; z++)
                                            {
                                                trie3[z]=(char)arr[z+1];
                                            }
                                                trie3[3]= '\0';
                                            generated_hashed = crypt(trie3,salt);
                                            a= CheckHash(a, hashedpwd, generated_hashed);
                                            if ( a == 0 )
                                                {
                                                    printf("%s\n", trie3);
                                                    break;
                                                }

                                                    /// check for a two letters password :)
                                                        for (int z=0; z<2; z++)
                                                        {
                                                            trie2[z]=(char)arr[z+2];
                                                        }
                                                            trie2[2]= '\0';
                                                        generated_hashed = crypt(trie2,salt);
                                                        a= CheckHash(a, hashedpwd, generated_hashed);
                                                        if ( a == 0 )
                                                            {
                                                                printf("%s\n", trie2);
                                                                break;
                                                            }

                    arr[3]++;
                     if ( arr[3] == 91)
                                {
                                    arr[3] = 97;
                                }

                                if ( arr[3] == 123 )
                                {
                                    arr[3] = 65;
                                }

                }
                if ( a == 0 ){  break; }
                arr[2]++;
                if ( arr[2] == 91)
                {
                    arr[2] = 97;
                }

                if ( arr[2] == 123 )
                {
                    arr[2] = 65;
                }
            }
             if ( a == 0 ){  break; }
            arr[1]++;
            if ( arr[1] == 91)
                {
                    arr[1] = 97;
                }

                if ( arr[1] == 123 )
                {
                    arr[1] = 65;
                }
         }
        if ( a == 0 ){  break; }
        arr[0]++;
        if ( arr[0] == 91)
            {
                arr[0] = 97;
            }
    }

    if( a==0 )
    {
        return 0;
    }
    else
        printf("not found\n");
        printf("%i\n", h);
    return 1;
}

int CheckHash(int a, string hashedpwd, string generated_hashed)
{
    a=0;
    // argv0 meaning hashed password
    for ( int i=0, n=strlen(hashedpwd); i<n; i++)
    {
        if ( hashedpwd[i] != generated_hashed[i])
        {
            a = 1;
            break;
        }
    }
    return a;
}