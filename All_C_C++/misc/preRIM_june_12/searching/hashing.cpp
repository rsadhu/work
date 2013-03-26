#include<stdio.>

class Node
{
	protected:
	int index;
	long int value;
};

class HashTable
{

	public;
       	int hashFunction(long int key);
	private:
	void linearProbing();
	void chanining();
	private:
	Node m_hash[100];

};
