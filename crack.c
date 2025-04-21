#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "md5.h"

#if __has_include("fileutil.h")
#include "fileutil.h"
#endif

#define PASS_LEN 50     // Maximum length any password will be.
#define HASH_LEN 33     // Length of hash plus one for null.


int main(int argc, char *argv[])
{
    if (argc < 3) 
    {
        printf("Usage: %s hash_file dictionary_file\n", argv[0]);
        exit(1);
    }

    // TODO: Read the hashes file into an array.
    //   Use either a 2D array or an array of arrays.
    //   Use the loadFile function from fileutil.c
    //   Uncomment the appropriate statement.
    int size;
    //char (*hashes)[HASH_LEN] = loadFile(argv[1], &size);
    char **hashes = loadFileAA(argv[1], &size);
    
    int n = 40;
    char **passArr = malloc(n * sizeof(char *));
    char optArr[1000];
    int i = 0;

    // CHALLENGE1: Sort the hashes using qsort.
    
    // TODO
    // Open the password file for reading.
    FILE *passFile = fopen(argv[2], "r");

    if(!passFile){

        printf("ERROR 3: could not open the password file");
        exit(1);
    }

    // TODO
    while(fgets(optArr, 1000, passFile)){

        // trimming the new line
        char *nl = strchr(optArr, '\n');
        if(nl){

            *nl = '\0';
        }

        // obtianing the length of the string to allocate memory for that individual cell
        int strLen = strlen(optArr);

        *(passArr+i) = malloc(strLen + 1);
        strcpy(*(passArr+i), optArr);

        i++;
        n++;

        if(i>=n){
            
            passArr = realloc(passArr, n *sizeof(char *));
        }

    }

    
    // For each password, hash it, then use the array search
    // function from fileutil.h to find the hash.
    // If you find it, display the password and the hash.
    // Keep track of how many hashes were found.
    // CHALLENGE1: Use binary search instead of linear search.

    // TODO
    // When done with the file:
    //   Close the file
    //   Display the number of hashes found.
    //   Free up memory.
}
