#include<stdio.h>
#include<string>
#include<stdlib.h>



typedef struct _trie 
{
    char value;
    struct _trie *links[26];
}trie;



int main(void)
{
     trie t;
     memset(&t,0,sizeof(trie));
     return 0;
}

