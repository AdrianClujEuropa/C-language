/**
 * Recovers jpegs from deleted mediums.
 * "char" is a type of integer. But it is a type of signed integer. It is 8 bits long, with one bit used for the sign.
 * So the range of numbers it can hold is from -128 to +127. Only.
 * if you are comparing 0xff to a character. Since that is comparing 255 to a variable that can never hold the value 255
 *
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover infile\n");
        return 1;
    }

    // remember filename
    char *infile = argv[1];

    // open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

unsigned char buffer[512];

// \0 is there to initialize name to null or else sprint f does not work when it tries to write the name.
char name[40] = {'\0'} ;

int counter = 0;
FILE *outptr; // = fopen(name[counter], "w");
                // reads a block of 512 bytes at a time
      while  (fread(buffer, 512, 1, inptr)==1 )
      {
                if
                    (      buffer[0] == 0xff
                    && buffer[1] == 0xd8
                    && buffer[2] == 0xff
                    && (buffer[3] & 0xf0)== 0xe0
                    )
                {
                     sprintf(name, "%03i.jpg", counter);
                    outptr = fopen(name, "w");
                    counter++;
                }
             // if a jpeg is encountered we write in files until the end of data read.
             if ( counter >= 1 )
                    {
                        fwrite(buffer, 512, 1, outptr);
                    }
        }
    while (fread(buffer, 1, 1, inptr) == 1)
    {

        fwrite(buffer, 1, 1, outptr);
    }

    fclose(outptr);

    return 0;
}