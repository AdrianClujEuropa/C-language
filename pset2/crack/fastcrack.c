#define _XOPEN_SOURCE
#include <cs50.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <strings.h>

typedef struct node
    {
        char word[45 + 1];
        struct node *next;
    }
    node;
    node *head;

int main( void )
{
    printf("building app...\n");

    char salt[]= "50";

    char namestring[5];


    int arr[4] = {'A','A','A','A'};

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

                        node *new_node = malloc(sizeof(node));
                        strcpy(new_node->word, crypt(namestring,salt));
                        new_node->next = head;
                        head = new_node;

                        node *new_node2 = malloc(sizeof(node));
                        strcpy(new_node2->word, namestring);
                        new_node2->next = head;
                        head = new_node2;


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
        arr[0]++;
        if ( arr[0] == 91)
            {
                arr[0] = 97;
            }
    }

    string hashedpwd = "";
    do
    {
        printf("(type exit to quit) enter hash... ");
         hashedpwd = get_string();

        node *cursor = head;
        int result;

        while( cursor != NULL )
        {
            result = strcasecmp(hashedpwd,cursor->word);
            if ( result == 0)
            {
                cursor = cursor->next;
                printf("%s\n", cursor->word);
            }
            cursor = cursor->next;
        }
        printf("a fost sau nu gasit?\n");
    }
    while ( strcasecmp(hashedpwd,"exit") != 0 );


     node *cursor = head;
        while( cursor != NULL )
        {
            node *temp = cursor;
            cursor = cursor->next;
            free(temp);
        }

}