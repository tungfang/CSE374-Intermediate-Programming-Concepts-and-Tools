// Charles Tung Fang
// CSE 374 HW 5
// 2019/5/10
// Trie object stores and retrieves words
// according to the String number input

#ifndef TRIE_H
#define TRIE_H

// individual node that form a piece of the trie
typedef struct Node {
    char* word;
    struct Node* nextNodes[9];
} Node;

// the Trie object
typedef struct Trie {
    Node* overallRoot;
} Trie;

// Given a trie and a file to form the
// trie with the lines in the given file. 
void read(Trie* trie, char* file);

// Given the root of the trie and free
// the allocated memory occupied by the 
// trie 
void freeTrie(Node* root);

// Given a String num to traverse the 
// trie and return a key combination String  
char* getWord(char* num);

// Given a character to determine what 
// is the index on the T9 system
int characterToIndex(char c);

#endif