// Charles Tung Fang
// CSE 374 HW 5
// 2019/5/10
// Trie object stores and retrieves words
// according to the String number input

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trie.h"
#include <ctype.h>

Trie* myTrie;
Node* curNode;

// Given a trie and a file to form the
// trie with the lines in the given file. 
void read(Trie* trie, char* file) {
    FILE *fptr = fopen(file, "r"); // file struct ptr
    myTrie = trie;
    myTrie->overallRoot = (Node*)calloc(1, sizeof(Node));
    Node* rootNode = myTrie->overallRoot;

    char wordsRead[100]; // words being read
    while (fgets(wordsRead, 100, fptr)) {
        for (int i = 0; i < strlen(wordsRead); i++) {
            if (wordsRead[i] == '\n') {
                break;
            }
            int index = characterToIndex(wordsRead[i]);
            if (rootNode->nextNodes[index] == NULL) {
                Node* newNode = (Node*)calloc(1, sizeof(Node));
                rootNode->nextNodes[index] = newNode;
            }
            rootNode = rootNode->nextNodes[index];
        }

        int wordSize = 1 + strlen(wordsRead);
        char* word = (char*)calloc(wordSize, sizeof(char));
        strncpy(word, wordsRead, wordSize);

        if (rootNode->word != NULL) {
            while(rootNode->nextNodes[8] != NULL) {
                rootNode = rootNode->nextNodes[8];
            }
            Node* new = (Node*)calloc(1, sizeof(Node));
            rootNode->nextNodes[8] = new;
            new->word = word;
        } else {
            rootNode->word = word;
        }
        rootNode = myTrie->overallRoot;
    }
    curNode = myTrie->overallRoot;
    fclose(fptr);
}


// Given the root of the trie and free
// the allocated memory occupied by the 
// trie 
void freeTrie(Node* root) {
    for (int i = 0; i < 9; i++) {
        if (root->nextNodes[i] != NULL)
            freeTrie(root->nextNodes[i]); 
    }
    free(root->word);
    free(root);
}

// Given a String num to traverse the 
// trie and return a key combination String  
char* getWord(char* num) {
    if (num[0] != '#') {
        curNode = myTrie->overallRoot;
        // subtract by one to deal with extra newline got added in
        int size = strlen(num) - 1; 
        for (int i = 0; i < size; i++) {
            if (num[i] != '#') {
                int index = num[i] - '0' - 2;
                if (curNode->nextNodes[index] != NULL) {
                    curNode = curNode->nextNodes[index];
                } else {
                    return "Not found in current dictionary.\n";
                }
            } else {
                curNode = curNode->nextNodes[8];
                if (curNode == NULL && i < size) {
                    break; // if given string has # in the middle
                }
            }
        }
    } else {
        if (curNode->nextNodes[8] == NULL) {
            return "There are no more T9onyms\n";
        }
        curNode = curNode->nextNodes[8];
        return curNode->word;
    }
    if (curNode == NULL) {
        return "There are no more T9onyms\n";
    } else if (curNode->word == NULL) {
        return "Not found in current dictionary.\n";
    } else {
        return curNode->word;
    }
}

// Given a character to determine what 
    // is the index on the T9 system
int characterToIndex(char character) {
    switch (character) {
        case('a'):
        case('b'):
        case('c'): return 0;
        case('d'):
        case('e'):
        case('f'): return 1;
        case('g'):
        case('h'):
        case('i'): return 2;
        case('j'):
        case('k'):
        case('l'): return 3;
        case('m'):
        case('n'):
        case('o'): return 4;
        case('p'):
        case('q'):
        case('r'):
        case('s'): return 5;
        case('t'):
        case('u'):
        case('v'): return 6;
        case('w'):
        case('x'):
        case('y'):
        case('z'): return 7;
        case('#'): return 8;
        default: return -1;
    }
}