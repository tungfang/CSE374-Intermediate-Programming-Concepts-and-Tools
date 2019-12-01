// Charles Tung Fang
// CSE 374 HW 5
// 2019/5/10
// This program implement T9 predicitive text
// It takes in a String of numbers and output the possible 
// wword that can be formed by the given String

#include <stdlib.h>
#include <stdio.h>
#include "trie.h"
#include <string.h>
#include <ctype.h>

void interact();

int main(int argc, char** argv) {
    // Given less than 2 arguments, present error and show usage
    if(argc < 2 || argc > 2){
        fprintf(stderr, "Usage: %s DICTFILE\n", argv[0]);
        return(-1);
    }

    Trie* trie = (Trie*)malloc(sizeof(Trie));
    read(trie, argv[1]);
    interact();
    freeTrie(trie->overallRoot);
    free(trie);
    return 0;
}


// Interactive session with the user after reading the
// dictionary and built the trie containing the words in it
void interact() {
    char digits[100];
    printf("%s", "Enter \"exit\" to quit.\n");
    printf("%s", "Enter Key Sequence (or \"#\" for next word):\n");
    while (fgets(digits, 100, stdin)) {
        // user input exit or end of file
        if (strncmp(digits, "exit", 4) == 0 || *digits == '\004') {
            return;
        }
        printf("%s", getWord(digits));
        printf("%s", "Enter Key Sequence (or \"#\" for next word):\n");
    }
}

