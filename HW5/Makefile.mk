t9: t9.o trie.o
    gcc -g -Wall -std=c11 -o t9 t9.o trie.o 

t9.o: t9.c
    gcc -g -Wall -std=c11 -c t9.c

trie.o: trie.c
    gcc -g -Wall -std=c11 -c trie.c

clean: 
	rm *.o t9