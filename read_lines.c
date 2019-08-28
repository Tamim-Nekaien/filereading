#include <stdio.h>
#include <stdlib.h>
#include "read_lines.h"

// Ok so I need to read a file and then print it out on different lines.
// I also need to apparently allocate memory for something
// And I can print it out in a loop like a list
/* So what I'm doing is reading a file and then splitting
 * up the contents of the file by newlines. I have to create
 * an array of arrays one array of characters and
 * then another of strings. */
void read_lines(FILE *fp, char ***lines, int *num_lines) {
    int r = 0; //r which is the same as num of args

    char l; //the representation of each character in the array of arrays

    *lines = (char **) malloc(sizeof(char *)); // dereferences the 2d array and creates space for it.
    (*lines)[(*num_lines)] = (char *) malloc(sizeof(char)); //allows chars to be stored by creating space for array
    fscanf(fp, "%c", &l); //advice from Campuswire: read the file, while loop, then read again.


    while (!feof(fp)) {//until EOF

        if (l == '\n') { //if newlines is detected it is the end of a string.
            (*num_lines)++;
            r = 0;
            *lines = (char **) realloc(*lines, sizeof(char *) * (*num_lines + 1));//dynamic allocation of memory for string array
            (*lines)[*num_lines] = (char *) malloc(sizeof(char) * (r + 1));
            (*lines)[*num_lines][r+1] = '\0';
            //i've allocated memory for the null character, now i need to append the null character to the array to the signify the end of a string.
            //Did I allocate it in the right place though?

        } else {//if you're still in the middle of a string

            (*lines)[*num_lines][r] = l;//l becomes each character in the file during the loop
            r++;
            (*lines)[*num_lines] = (char *) realloc((*lines)[*num_lines], sizeof(char) * (r + 1)); //dynamic allocation of memory for character array is in else
            //statement because string has not been completed yet.

        }
        fscanf(fp, "%c", &l);
    }
}


//checklist: set each row for one line
//num lines equal to number of lines in file
//
