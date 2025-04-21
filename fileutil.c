#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fileutil.h"

// chose array of array's

// Load the text file from the given filename.
// Return a pointer to the array of strings.
// Sets the value of size to be the number of valid
// entries in the array (not the total array length).
char ** loadFileAA(char *filename, int *size) {

    int n = 40;
    char optArray[1000];
    int strLen;

	FILE *in = fopen(filename, "r");
	if (!in)
	{
	    perror("Can't open file");
	    exit(1);
	}
	
	// TODO
	// Allocate memory for an array of strings (arr).
    char ** strArray = malloc(n * sizeof(char *));
    int i = 1;

	// Read the file line by line.
    while(fgets(optArray, 1000, in)){

        //   Trim newline.
        char *nl = strchr(optArray, '\n');
        if(nl){

            *nl = '\0';

        }

        strLen = strlen(optArray);
        //printf("\nsize: %d, string: %s", strLen, optArray);

        strArray[i] = malloc(strLen);
        strcpy(strArray[i], optArray);
        
        //printf("\nstring: %s", strArray[i]);

        i++;
        n++;
        strArray = realloc(strArray, n *sizeof(char *));
	
    }
        
	//   Expand array if necessary (realloc).
	//   Allocate memory for the string (str).
	//   Copy each line into the string (use strcpy).
	//   Attach the string to the large array (assignment =).
    // Close the file.
	fclose(in);
	
	// The size should be the number of entries in the array.
	*size = (n - 40);

	// Return pointer to the array of strings.
	return strArray;
}

char (*loadFile2D(char *filename, int *size))[COLS]
{
	FILE *in = fopen(filename, "r");
	if (!in)
	{
	    perror("Can't open file");
	    exit(1);
	}
	
	// TODO
	// Allocate memory for an 2D array, using COLS as the width.
	// Read the file line by line into a buffer.
    //   Trim newline.
	//   Expand array if necessary (realloc).
	//   Copy each line from the buffer into the array (use strcpy).
    // Close the file.
	
	// The size should be the number of entries in the array.
	*size = 0;
	
	// Return pointer to the array.
	return NULL;
}

// Search the array for the target string.
// Return the found string or NULL if not found.
char * substringSearchAA(char *target, char **lines, int size) {

	char *foundArr;

	for(int i=1; i <= size; i++) {

		foundArr = strstr(target, lines[i]);

		if (foundArr != NULL) {
			
			break;

		}
		
	}

	return foundArr;
}

char * substringSearch2D(char *target, char (*lines)[COLS], int size)
{
    
    return NULL;
}

int stringcmp(const void *a, const void *b, int *size){

	char ** aa = (char **)a;
	char ** bb = (char **)b;

	return strcmp(*aa, *bb);

}

// Free the memory used by the array
void freeAA(char ** arr, int size)
{
	free(arr);

}

void free2D(char (*arr)[COLS])
{

}