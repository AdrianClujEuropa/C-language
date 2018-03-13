/**
 * Recovers jpegs from deleted mediums.
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

    // remember filenames
    char *infile = argv[1];

    // open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    unsigned int buffer[512];
    char name[]= {'0','0','0','.','j','p','g'};
    int nrofjpgs=0;

    // open output file
 //   FILE *outptr = fopen(name, "w");

    while (fread(buffer, 512, 1, inptr) )
    {
      //  printf("incepe citirea");
        if ( buffer[0] == 0xff
            && 0xd8==buffer[1]
            && 0xff==buffer[2]
            && (buffer[3] & 0xf0)== 0xe0 )
        {

            printf("am gasit primul jpg\n");
            // set name for output file
            nrofjpgs +=1;
                if ( name[2] == '9' )
                    {
                        name[2] = '0';
                        if ( name[1] == '9')
                        {
                            name[1] = '0';
                            name[0] += '1';
                        }
                        else name[1] += '1';
                    }
                else name[2] += '1';
            printf("%s", name);
            // close outfile
    ///        fclose(outptr);
       //     outptr = fopen(name, "w");
         //   fwrite(buffer, 512, 1, outptr);
        }
//        if ( nrofjpgs>1 )fwrite(buffer, 512, 1, outptr);
    }

    return 0;
}