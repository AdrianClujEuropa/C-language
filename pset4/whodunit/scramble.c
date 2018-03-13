/**
 * Copies a BMP piece by piece, just because.
 */
#define _XOPEN_SOURCE

#include <cs50.h>
#include <stdbool.h>
#include <string.h>
#include <strings.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "bmp.h"


int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 3)
    {
        fprintf(stderr, "Usage: ./whodunit infile outfile\n");
        return 1;
    }

    // remember filenames
    char *infile = argv[1];
    char *outfile = argv[2];

    // open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }
           //////////
         ////////////
       //////////////
     ////////////////
    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }

    // write outfile's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);

    // determine padding for scanlines
    int padding =  (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

           //////////
         ////////////
       //////////////
     ////////////////
    // starting to read actual photo pixels

long totalpixels = 0;
long countblue = 0;
long countmount =0;
long countgreen = 0;
long countautumn = 0;
long countshadow = 0;

long o = 0;

RGBTRIPLE matrix[950][950];
//RGBTRIPLE blue[40000];
//RGBTRIPLE mount[22000];
//RGBTRIPLE green[120000];
//RGBTRIPLE autumn[70000];
//RGBTRIPLE shadow[72000];
RGBTRIPLE* blue = (RGBTRIPLE*) malloc(40000*sizeof(RGBTRIPLE));
RGBTRIPLE* mount = (RGBTRIPLE*) malloc(22000*sizeof(RGBTRIPLE));
RGBTRIPLE* green = (RGBTRIPLE*) malloc(120000*sizeof(RGBTRIPLE));
RGBTRIPLE* autumn = (RGBTRIPLE*) malloc(70000*sizeof(RGBTRIPLE));
RGBTRIPLE* shadow = (RGBTRIPLE*) malloc(72000*sizeof(RGBTRIPLE));

RGBTRIPLE* allpixels = (RGBTRIPLE*) malloc(310564*sizeof(RGBTRIPLE));

//RGBTRIPLE allcolors[900000];
RGBTRIPLE ey[950][950];

RGBTRIPLE blue_start;
    blue_start.rgbtRed= 80;
    blue_start.rgbtGreen= 95;
    blue_start.rgbtBlue= 160;

RGBTRIPLE blue_end;
    blue_end.rgbtRed= 110;
    blue_end.rgbtGreen= 150;
    blue_end.rgbtBlue= 175;

RGBTRIPLE mount_start;
    mount_start.rgbtRed= 136;
    mount_start.rgbtGreen= 136;
    mount_start.rgbtBlue= 126;

RGBTRIPLE mount_end;
    mount_end.rgbtRed= 235;
    mount_end.rgbtGreen= 235;
    mount_end.rgbtBlue= 200;

RGBTRIPLE green_start;
    green_start.rgbtRed= 26;
    green_start.rgbtGreen= 40;
    green_start.rgbtBlue= 46;

RGBTRIPLE green_end;
    green_end.rgbtRed= 130;
    green_end.rgbtGreen= 255;
    green_end.rgbtBlue= 160;

RGBTRIPLE autumn_start;
    autumn_start.rgbtRed= 31;
    autumn_start.rgbtGreen= 51;
    autumn_start.rgbtBlue= 22;

RGBTRIPLE autumn_end;
    autumn_end.rgbtRed= 250;
    autumn_end.rgbtGreen= 150;
    autumn_end.rgbtBlue= 100;
        // iterate over infile's scanlines
        for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
        {
            // iterate over pixels in scanline
            for (int j = 0; j < bi.biWidth; j++)
            {
                // temporary storage
                RGBTRIPLE triple;
                // read RGB triple from infile
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);
                matrix[j][i]= triple;
                allpixels[totalpixels] = triple;
                totalpixels++;

                if (
                            (triple.rgbtRed > blue_start.rgbtRed)
                            &&(triple.rgbtGreen > blue_start.rgbtGreen)
                            &&(triple.rgbtBlue > blue_start.rgbtBlue)
                                &&(triple.rgbtRed < blue_end.rgbtRed)
                                &&(triple.rgbtGreen < blue_end.rgbtGreen)
                                &&(triple.rgbtBlue < blue_end.rgbtBlue)
                        )
                    {

                        blue[countblue] = triple;
                        countblue++;
                    }
                else if (
                            (triple.rgbtRed > mount_start.rgbtRed)
                            &&(triple.rgbtGreen > mount_start.rgbtGreen)
                            &&(triple.rgbtBlue > mount_start.rgbtBlue)
                                &&(triple.rgbtRed < mount_end.rgbtRed)
                                &&(triple.rgbtGreen < mount_end.rgbtGreen)
                                &&(triple.rgbtBlue < mount_end.rgbtBlue)
                        )
                    {
                        mount[countmount] = triple;
                        countmount++;
                    }
                else if (
                            (triple.rgbtRed > green_start.rgbtRed)
                            &&(triple.rgbtGreen > green_start.rgbtGreen)
                            &&(triple.rgbtBlue > green_start.rgbtBlue)
                                &&(triple.rgbtRed < green_end.rgbtRed)
                                &&(triple.rgbtGreen < green_end.rgbtGreen)
                                &&(triple.rgbtBlue < green_end.rgbtBlue)
                        )
                    {
                        green[countgreen] = triple;
                        countgreen++;
                    }
                else if (
                            (triple.rgbtRed > autumn_start.rgbtRed)
                            &&(triple.rgbtGreen > autumn_start.rgbtGreen)
                            &&(triple.rgbtBlue > autumn_start.rgbtBlue)
                                &&(triple.rgbtRed < autumn_end.rgbtRed)
                                &&(triple.rgbtGreen < autumn_end.rgbtGreen)
                                &&(triple.rgbtBlue < autumn_end.rgbtBlue)
                        )
                    {
                        autumn[countautumn] = triple;
                        countautumn++;
                    }
                else
                    {
                        shadow[countshadow] = triple;
                        countshadow++;
                    }

            }
            // skip over padding, if any
        fseek(inptr, padding, SEEK_CUR);

        }

           //////////
         ////////////
       //////////////
     ////////////////
    // HElp display porposes
  //////////////////////////Randomness
    printf("Poza are atatia pixeli: %li\n", totalpixels);
    printf("Poza are atatia pixeli blue: %li\n", countblue);
    printf("Poza are atatia pixeli mount: %li\n", countmount);
    printf("Poza are atatia pixeli green: %li\n", countgreen);
    printf("Poza are atatia pixeli autumn: %li\n", countautumn);
    printf("Poza are atatia pixeli shadow: %li\n", countshadow);
    long toti = countblue + countmount + countgreen + countautumn + countshadow;
        printf("Poza are atatia pixeli, adunati din categ culori: %li\n", toti);


    //printf("testing output for rgbt green: %hhu\n", allcolors[1011].rgbtGreen);


           //////////
         ////////////
       //////////////
     ////////////////
    // starting to put read pixels in an array
  //////////////////////////Randomness
        o=0;
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
        {
            // iterate over pixels in scanline
            for (int j = 0; j < bi.biWidth; j++)
            {
                             if (
                            (matrix[j][i].rgbtRed > blue_start.rgbtRed)
                            &&(matrix[j][i].rgbtGreen > blue_start.rgbtGreen)
                            &&(matrix[j][i].rgbtBlue > blue_start.rgbtBlue)
                                &&(matrix[j][i].rgbtRed < blue_end.rgbtRed)
                                &&(matrix[j][i].rgbtGreen < blue_end.rgbtGreen)
                                &&(matrix[j][i].rgbtBlue < blue_end.rgbtBlue)
                            )
                            {
                                int kkk = (int) (drand48() * countblue+1);
                                ey[j][i] = blue[kkk];
                                o++;
                            }
                            else if (
                            (matrix[j][i].rgbtRed > mount_start.rgbtRed)
                            &&(matrix[j][i].rgbtGreen > mount_start.rgbtGreen)
                            &&(matrix[j][i].rgbtBlue > mount_start.rgbtBlue)
                                &&(matrix[j][i].rgbtRed < mount_end.rgbtRed)
                                &&(matrix[j][i].rgbtGreen < mount_end.rgbtGreen)
                                &&(matrix[j][i].rgbtBlue < mount_end.rgbtBlue)
                            )
                                {
                                    int kkk = (int) (drand48() * countmount+1);
                                    ey[j][i] = mount[kkk];
                                    o++;
                                }
                            else if (
                                        (matrix[j][i].rgbtRed > green_start.rgbtRed)
                                        &&(matrix[j][i].rgbtGreen > green_start.rgbtGreen)
                                        &&(matrix[j][i].rgbtBlue > green_start.rgbtBlue)
                                            &&(matrix[j][i].rgbtRed < green_end.rgbtRed)
                                            &&(matrix[j][i].rgbtGreen < green_end.rgbtGreen)
                                            &&(matrix[j][i].rgbtBlue < green_end.rgbtBlue)
                                    )
                                {
                                   int kkk = (int) (drand48() * countgreen+1);
                                    ey[j][i] = green[kkk];
                                    o++;
                                }
                            else if (
                                        (matrix[j][i].rgbtRed > autumn_start.rgbtRed)
                                        &&(matrix[j][i].rgbtGreen > autumn_start.rgbtGreen)
                                        &&(matrix[j][i].rgbtBlue > autumn_start.rgbtBlue)
                                            &&(matrix[j][i].rgbtRed < autumn_end.rgbtRed)
                                            &&(matrix[j][i].rgbtGreen < autumn_end.rgbtGreen)
                                            &&(matrix[j][i].rgbtBlue < autumn_end.rgbtBlue)
                                    )
                                {
                                   // int kkk = (int) (drand48() * countautumn+1);
                                    ey[j][i] = matrix[j][i];
                                    o++;
                                }
                            else
                                {
                                   // int kkk = (int) (drand48() * 548);
                                    ey[j][i] = matrix[j][i];
                                    o++;
                                }


                                            /* random int between 0 and 19 */
                                            //int r = rand() % 33240;
                                             //   ey[j][i] = matrix[j][i];


                    }
                }
                                    printf("%li\n", o);




          //////////
         ////////////
       //////////////
     ////////////////
    // starting to write actual photo pixels to new file
   //////////////////////////////////
o=0;
//int init[abs(bi.biHeight)];
int jinit[bi.biWidth];
int ct = 0;
int ans=0;
int kkj=0;

RGBTRIPLE hy[950][950];
for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
        { printf("new line..");
        for (int ctu=0; ctu<bi.biWidth; ctu++)
        {
            jinit[ctu]=0;
        }
        ct=0;
            // iterate over pixels in scanline
            for (int j = 0; j < bi.biWidth; j++)
            {
                 if ( i%11 != 0 )
                 {
                     do {
                     //int kki = (int) (drand48() * bi.biHeight );
                    kkj =  (int) (drand48() * bi.biWidth );
                    //init[ct]= kki;
                    jinit[ct]= kkj;

                    ans =0;

                    if ( ct >= 1)
                    {
                    for (int g=0; g<ct-1; g++)
                    {
                        if ( jinit[g]==kkj)
                        ans = 1;
                    }
                    }

                    }
                    while ( ans == 1);


                    ct++;
                    hy[j][i]= matrix[kkj][i];
                 }
                    else
                    {
                       hy[j][i]=matrix[j][i];
                    }



                    /// OTHER OPTION DOWN
 /*
                if (( i> 160 && i< 450 ) && ( j> 450 && j< 600 ))
                {
                    int kki = (int) (drand48() * 60);
                    //int kkj = (int) (drand48() * 20);
                    hy[j][i]= matrix[j][i+kki];
                }
                else if ( ( i> 160 && i< 300 ) && ( j> 300 && j< 440 ) )
                {
                   // int kki = (int) (drand48() * 40+1);
                //    int kkj = (int) (drand48() * 140+1);
                    hy[j][i]=matrix[j][i];
                }
                else if ( ( i> 300 && i< 450 ) && ( j> 0 && j< 240 ) )
                {
                    int kki = (int) (drand48() * 40);
                    int kkj = (int) (drand48() * 40);
                    hy[j][i]=matrix[j+kkj][i+kki];
                }
                else
                {
                   hy[j][i]=ey[j][i];
                }
*/
               o++;
            }
        }



    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
        {
            // iterate over pixels in scanline
            for (int j = 0; j < bi.biWidth; j++)
            {
                // write RGB triple to outfile
               fwrite(&hy[j][i], sizeof(RGBTRIPLE), 1, outptr);

              //// or this
 /*              if ( i> 0 && i< 350)
               {
                   int kki = (int) (drand48() * 12);
                    int kkj = (int) (drand48() * 5);
                   fwrite(&hy[j+kkj][i+kki], sizeof(RGBTRIPLE), 1, outptr);
               }
               else if ( i> 350 && i< 400)
               {
                   int kki = (int) (drand48() * 5);
                    int kkj = (int) (drand48() * 3);
                   fwrite(&matrix[j+kkj][i+kki], sizeof(RGBTRIPLE), 1, outptr);
               }

              else if ( i> 400 && i<450)
              {
                  int kki = (int) (drand48() * 15);
                    int kkj = (int) (drand48() * 53);
                  fwrite(&matrix[j+kkj][i+kki], sizeof(RGBTRIPLE), 1, outptr);
              }
              else
              fwrite(&matrix[j][i], sizeof(RGBTRIPLE), 1, outptr);
 */             ///// til here!!!
               o++;
            }


        // then add it back (to demonstrate how)
        for (int k = 0; k < padding; k++)
        {
            fputc(0x00, outptr);
        }

        }

        printf("%li\n", o);


    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);
   //// freee heap memory

    free(blue);
    free(mount);
    free(green);
    free(autumn);
    free(shadow);
    free(allpixels);


    // success
    return 0;
}
