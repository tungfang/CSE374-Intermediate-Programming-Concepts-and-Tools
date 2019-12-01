//  Charles Tung Fang, CSE 374 HW4, 4/30/2019
// gasp reads the list files and copy each line from the input to stdout if 
// it contains STRING anywhere in the input line.

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Handle input lines up to 500 chars
#define MAX_LINE 500
// String pattern on the cmd must be less than 100 chars
#define MAX_STR_PATTERN 100

// serve as flag for '-i'. 1 if '-i' is given, otherwise 0
int ignoreCase; 
// serve as flag for '-n'. 1 if '-n' is given, otherwise 0
int numLine; 


void searchMatches(char *file, char *str);


// Given num of cmd arguments and list of cmd arguments
// to find the string matches in the files.
// Output the sentences that contains the given string

int main(int argc, char *argv[]){
    ignoreCase = 0; 
    numLine = 0; 
    char *str = NULL; // store the given string

    if (argc < 3) {
        fprintf(stderr, "Must pass at least 3 arguments. Usage: ./gasp [options] STRING FILE...");
        return -1;
    }

    // examine given arguments
    for (int i = 1; i < argc; i++) {
        if (numLine == 0 && strncmp(argv[i], "-n", 2) == 0) {
            // user passed in number line option
            numLine = 1; 
        } else if (ignoreCase == 0 && strncmp(argv[i], "-i", 2) == 0) {
            //user passed in ignore case option
            ignoreCase = 1; 
        } else {
            // read and record the desired input string
            if (str == NULL) {
                str = argv[i];
                if (ignoreCase != 0) {
                    for (char *p = str; *p; ++p) *p = tolower(*p);
                }
            } else {
                // searchMatches in current file
                searchMatches(argv[i], str);
            }                 
        }
    }
    return 0;
}

// Given a argument count, argument value and string to find the match 
// among files
void searchMatches(char *fileName, char *str) {
    FILE* file = fopen(fileName, "r"); // pointer to current file

    if (file == NULL) {
        fprintf(stderr, "Cannot open %s\n", fileName);
    }

    char singleLine[MAX_LINE];
    int lineCount = 1;

    if (ferror(file)) {
        fprintf(stderr, "Error reading line %d in %s\n", lineCount, fileName);
    }

    while (fgets(singleLine, MAX_LINE, file) != NULL) {
        char temp[MAX_LINE];
        strncpy(temp, singleLine, strlen(singleLine));
        // change line to lower case if flag is true
        if (ignoreCase == 1) {
            for (char *p = temp; *p; ++p) *p = tolower(*p);
        }

        if (strstr(temp, str)) {
            if (numLine != 1) {
                printf("%s:%s", fileName, singleLine);
            } else {
                printf("%s line %d:%s", fileName, lineCount, singleLine);
            }            
        }
        lineCount++;
    }
    fclose(file);
}
