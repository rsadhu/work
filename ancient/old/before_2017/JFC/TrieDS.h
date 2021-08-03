#pragma once
#include<string>

class Node
{
public:
	bool is_end;
	int prefix_count;
	Node *child[26];
};

class TrieDS
{
public:
	TrieDS();
	~TrieDS();
	void insert(std::string &word);
	bool search(std::string &word);
	int countWordsWithPref(std::string &);
	Node *head;
};

