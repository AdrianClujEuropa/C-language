/**
 * Implements a dictionary's functionality.
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include "dictionary.h"
#include <ctype.h>

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char *word)
{
    // TODO

    int letter = (tolower(word[0]) - 'a');
    int result;

        node *cursor = hashtable[letter];
        while( cursor != NULL )
        {
            result = strcasecmp(word,cursor->word);
            if ( result == 0)
            {
                return true;
            }
            cursor = cursor->next;
        }

    return false;
}

/**
 * Loads dictionary into memory. Returns true if successful else false.
 */
bool load(const char *dictionary)
{
    // TODO

    // open dictionary for reading
    FILE *inptr = fopen(dictionary, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", dictionary);
        return 2;
    }

    char word[LENGTH];

    int letter;
    while (fscanf(inptr, "%s", word) != EOF)
    {
        node *new_node = malloc(sizeof(node));
        if ( new_node == NULL )
        {
            unload();
            return false;
        }
        letter = (tolower(word[0]) - 'a');
        strcpy(new_node->word, word);
        //hashtable[letter]->next = word;
        //hashtable[letter] = new_node;
        new_node->next = hashtable[letter];
        hashtable[letter] = new_node;

    }
        fclose(inptr);

    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    // TODO
    //return 0;
    int counter= 0;
    for ( int i=0; i< 26; i++)
    {
        node *cursor = hashtable[i];

        while( cursor != NULL )
        {
            cursor = cursor->next;
            counter ++;
        }
    }
    return counter;
}

/**
 * Unloads dictionary from memory. Returns true if successful else false.
 */
bool unload(void)
{
    // TODO
    for ( int i=0; i<26; i++)
    {
        node *cursor = hashtable[i];
        while( cursor != NULL )
        {
            node *temp = cursor;
            cursor = cursor->next;
            free(temp);
        }
    }
    return true;
}
