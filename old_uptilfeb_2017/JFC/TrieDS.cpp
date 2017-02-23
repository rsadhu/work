#include "TrieDS.h"


TrieDS::TrieDS()
{
	head = new Node();
	head->prefix_count = 0;
	head->is_end = false;
}


TrieDS::~TrieDS()
{

}

void TrieDS::insert(std::string &word)
{
	Node *current = head;
	current->prefix_count++;
	for (unsigned int i = 0; i < word.length(); i++)
	{
		int letter = (int)word[i] - (int)'a';
		if (current->child[letter] == NULL)
			current->child[letter] = new Node();
		current->child[letter]->prefix_count++;
		current = current->child[letter];
	}
	current->is_end = true;
}

bool TrieDS::search(std::string &word)
{
	Node *current = head;
	for (unsigned int i = 0; i < word.length(); i++)
	{
		int letter = (int)word[i] - (int)'a';
		if (current->child[letter] == NULL)
			return false;		
		current = current->child[letter];
	}
	return current->is_end;
}

int TrieDS::countWordsWithPref(std::string &word)
{
	Node *current = head;
	for (unsigned int i = 0; i < word.length(); i++)
	{
		int letter = (int)word[i] - (int)'a';
		if (current->child[letter] == NULL)
			return 0;
		else			
			current = current->child[letter];
	}
	return current->prefix_count;

}