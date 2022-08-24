/*
Author:rsadhu
Date:07/12/2012
Completely for learning purposes.
*/
#include <iostream>
#include <stack.h>
using namespace std;

struct Node
{
	Node *left, *right;
	int data;
	Node(int d) : left(0), right(0), data(d) {}
};

class BST
{
public:
	BST &operator<(int d);
	void displayAll()
	{
		cout << "\nINORDER\n";
		/*inOrderRec(m_root);
		cout<<"\nPREORDER\n";
		preOrderRec(m_root);
		cout<<"\nPOSTORDER\n";
		postOrderRec(m_root);
		cout<<"\n";*/
		cout << "Non Recursive Methods\n";
		inOrder(m_root);
		bfsDisplay(m_root);
	}

protected:
	void inOrderRec(Node *node);
	void preOrderRec(Node *node);
	void postOrderRec(Node *node);
	void inOrder(Node *n);
	void preOrder(Node *n);
	void postOrder(Node *n);
	void bfsDisplay(Node *n);

private:
	Node *m_root;
};

#define MAX 100
template <typename T>
class Stack
{
	T arr[MAX];
	int m_top;

public:
	Stack() : m_top(-1){};
	T pop()
	{
		if (m_top > 0)
		{
			return arr[m_top--];
		}
	}
	void push(T n)
	{
		if (m_top < MAX)
		{
			arr[++m_top] = n;
		}
	}
	bool isEmpty()
	{
		bool ret(false);
		if (m_top == -1)
		{
			ret = true;
		}
		return ret;
	}
	int size() { return m_top; }
};

void BST::inOrderRec(Node *n)
{
	if (n != NULL)
	{
		inOrderRec(n->left);
		cout << n->data << "  ";
		inOrderRec(n->right);
	}
}

void BST::preOrderRec(Node *n)
{
	if (n != NULL)
	{
		cout << n->data << "  ";
		preOrderRec(n->left);
		preOrderRec(n->right);
	}
}

void BST::postOrderRec(Node *n)
{
	if (n != NULL)
	{
		postOrderRec(n->left);
		postOrderRec(n->right);
		cout << n->data << "  ";
	}
}

void BST::inOrder(Node *n)
{
	stack<Node *> s;

	while (!s.empty() || n)
	{
		if (n)
		{
			s.push(n);
			n = n->left;
		}
		else
		{
			n = s.top();
			s.pop();
			cout << n->data;
			cout << "\n";
			n = n->right;
		}
	}
}

void BST::bfsDisplay(Node *root)
{
	cout << " BST::bfsDisplay \n";
	queue<Node *> q;
	if (root)
	{

		q.push(root);
		while (!q.empty())
		{
			Node *d = q.front();
			cout << d->data << "  ";
			if (d->left)
			{
				q.push(d->left);
			}
			if (d->right)
			{
				q.push(d->right);
			}
			q.pop();
		}
	}
	cout << " BDT::dfsDisplay end\n";
}

void BST::preOrder(Node *n)
{
}
void BST::postOrder(Node *n)
{
}
BST &BST::operator<(int d)
{
	if (!m_root)
	{
		m_root = new Node(d);
	}
	else
	{
		Node *tmp = m_root;

		while (tmp)
		{
			if (d > tmp->data)
			{
				if (tmp->right == NULL)
				{
					tmp->right = new Node(d);
					break;
				}
				else
					tmp = tmp->right;
			}
			else if (d < tmp->data)
			{
				if (tmp->left == NULL)
				{
					tmp->left = new Node(d);
					break;
				}
				else
					tmp = tmp->left;
			}
		}
	}
	return *this;
}

int main(void)
{
	BST bst;
	bst < 10 < 5 < 15 < 8 < 12 < 3 < 18;
	bst.displayAll();
	return 0;
}
