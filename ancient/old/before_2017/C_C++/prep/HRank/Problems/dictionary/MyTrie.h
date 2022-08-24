#pragma once
#include <string>

class MyTrie
{
public:
	MyTrie();
	~MyTrie();
	void initialize();
	void addWord(std::string &);
	int countPreffixes();
	int countWords();
};
