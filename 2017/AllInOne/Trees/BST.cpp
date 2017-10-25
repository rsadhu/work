#include "stdafx.h"
#include "BST.h"

//
//void BinaryTree::addNode(int data)
//{
//	if (!mRoot)
//		mRoot = new Node(data);
//	else
//	{
//		Node *tra = mRoot;
//		while(tra)
//		{			
//		
//		}
//	}
//}
//

//void BinaryTree::inOrderDisplay(Node *root)
//{
//	if (root)
//	{
//		inOrderDisplay(root->left);
//		std::cout << root->mData << " ";
//		inOrderDisplay(root->right);
//	}
//}


BST::BST()
{
}

void cheanBST(Node *root)
{
	if (root)
	{
		cheanBST(root->left);
		cheanBST(root->right);
		delete root;
		root = nullptr;
	}
}

BST::~BST()
{
	//cheanBST(mRoot);
	//mRoot = nullptr;
	std::queue<Node *>queue;
	queue.push(mRoot);
	while (!queue.empty())
	{
		Node *tra = queue.front();
		queue.pop();
		if (tra)
		{		
			if (tra->left)
				queue.push(tra->left);
			if (tra->right)
				queue.push(tra->right);
			delete tra;
		}
	}
	mRoot = nullptr;
}


// iteratively 
void BST::add(int d)
{
	if (!mRoot)
	{
		mRoot = new Node(d);
	}
	else
	{
		Node *tra = mRoot;
		while (tra)
		{
			if (d < tra->mData)
			{
				if (!tra->left)
				{
					tra->left = new Node(d);
					break;
				}
				else
				{
					tra = tra->left;
				}
			}
			else
			{
				if (!tra->right)
				{
					tra->right = new Node(d);
					break;
				}
				else
				{
					tra = tra->right;
				}
			}
		}
	}
}

BST & BST::operator<(int d)
{
	mRoot = add(mRoot, d); //recursive 
	return *this;
}

Node *BST::add(Node *root, int d)
{
	if (!root)
		return new Node(d);
	else
	{
		if (d < root->mData)
			root->left = add(root->left, d);
		else
			root->right = add(root->right, d); // todo: when same key is found, dont add or handle it the way u want
	}
	return root;
}


void BST::display(TYPE t)
{
	switch (t)
	{
	case TYPE::INORDER_R:
		inOrderR(mRoot);
		break;
	case TYPE::PREORDER_R:
		preOrderR(mRoot);
		break;
	case TYPE::POSTORDER_R:
		postOrderR(mRoot);
		break;
	case TYPE::INORDER_I:
		inOrderI(mRoot);
		break;
	case TYPE::PREORDER_I:
		preOrderI(mRoot);
		break;
	case TYPE::POSTORDER_I:
		postOrderI(mRoot);
		break;
	case TYPE::BFS:
		bfs(mRoot);
		break;
	case TYPE::SPIRAL:
		spiral(mRoot);
		break;
	case TYPE::MIRROR:
		mirror(mRoot);
		break;
	case TYPE::REVERSE_LEVELORDER:
		reverseLevelOrder(mRoot);
		break;
	}
	std::cout << "\n";
}

void reverseLevelOrder_R(Node *root)
{
	if (root->left == nullptr || root->right == nullptr){
		std::cout << root->mData << " - ";
		return;
	}
	

	reverseLevelOrder_R(root->left);
	reverseLevelOrder_R(root->right);

	std::cout << root->left->mData << " - ";
	std::cout << root->right->mData << " - ";

	return;
}

void BST::reverseLevelOrder(Node *root)
{
	reverseLevelOrder_R(root);

	/*std::stack<std::vector<Node*>> st;
	std::vector<Node*>list;
	list.push_back(root);
	st.push(list);

	while (1)
	{
		list = st.top();
		std::vector<Node *> subList;
		for (auto it : list)
		{			
			if (it->left)
				subList.push_back(it->left);
			if (it->right)
				subList.push_back(it->right);
		}
		if (!subList.empty())
			st.push(subList);
		else
			break;
	}

	while (!st.empty())
	{
		std::vector<Node *> n = st.top();
		for (auto it : n)
		{
			std::cout << it->mData << " ";
		}
		st.pop();
	}*/
}

void BST::preOrderR(Node *root)
{
	if (root)
	{
		std::cout << root->mData << "  ";
		preOrderR(root->left);
		preOrderR(root->right);
	}
}


void BST::postOrderR(Node *root)
{
	if (root)
	{
		postOrderR(root->left);
		postOrderR(root->right);
		std::cout << root->mData << "  ";
	}
}

void BST::inOrderR(Node *root)
{
	if (root)
	{
		inOrderR(root->left);
		std::cout << root->mData << "  ";
		inOrderR(root->right);
	}
}




void BST::bfs(Node *root)
{
	levelOrder(root);
}


void BST::spiral(Node *root)
{
	std::stack<Node*> st1, st2;
	if (root)
	{
		st1.push(root);
		Node *tmp;
		while (!st1.empty() || !st2.empty())
		{
			while (!st1.empty())
			{
				tmp = st1.top();
				std::cout << tmp->mData << "  ";
				st1.pop();
				if (tmp->left)
					st2.push(tmp->left);
				if (tmp->right)
					st2.push(tmp->right);
			}
			while (!st2.empty())
			{
				tmp = st2.top();
				st2.pop();
				std::cout << tmp->mData << "  ";
				if (tmp->right)
					st1.push(tmp->right);
				if (tmp->left)
					st1.push(tmp->left);
			}
		}
	}
}


void BST::levelOrder(Node *root)
{
	std::queue<Node *>q;
	if (root)
		q.push(root);
	while (!q.empty())
	{
		root = q.front();
		q.pop();
		std::cout << root->mData << " ";
		if (root->left)
			q.push(root->left);
		if (root->right)
			q.push(root->right);
	}
}

void BST::mirror(Node*root)
{
	if (root)
	{
		mirror(root->left);
		mirror(root->right);
		Node *tmp = root->left;
		root->left = root->right;
		root->right = tmp;
	}
}

void BST::topView(Node *root)
{
//todo: to be done
}



void BST::preOrderI(Node *root)
{
	std::stack<Node *>st;
	st.push(root);

	while (!st.empty())
	{
		root = st.top();
		std::cout << root->mData << " ";
		st.pop();
		if (root->right)
			st.push(root->right);
		if (root->left)
			st.push(root->left);
	}
}


void BST::postOrderI(Node *root)
{
	if (root)
	{

	}
}

void BST::inOrderI(Node *root)
{
	std::stack<Node *> st;
	while (root || !st.empty())
	{
		if (root)
		{
			st.push(root);
			root = root->left;
		}
		else
		{
			root = st.top();
			std::cout << root->mData << " ";
			st.pop();
			root = root->right;
		}
	}
}

int BST::max()
{
	Node *tra = mRoot;
	if (tra->right)
	{
		while (tra->right)
		{
			tra = tra->right;
		}
		return tra->mData;
	}
	else
	{
		return tra ? tra->mData : 0;
	}
}

int BST::min()
{
	Node *tra = mRoot;
	if (tra->left)
	{
		while (tra->left)
		{
			tra = tra->left;
		}
		return tra->mData;
	}
	else
	{
		return tra ? tra->mData : 0;
	}
}

int BST::height()
{
	return findHeight(mRoot);
}

int BST::findHeight(Node *root)
{
	if (root)
	{
		return std::max(findHeight(root->left), findHeight(root->right)) + 1;
	}
	else
		return -1;
}

int mSmallestSum =INT_MAX, mLargestSum = INT_MIN;

void BST::printPathsRec(Node *root, std::vector<int> list)
{
	if (root)
	{		
		list.push_back(root->mData);
		if (!root->left && !root->right)
		{
			int sum = 0;
			for (auto it : list)
			{
				std::cout << it << "  ";
				sum += it;
			}
			std::cout << "\n";
			if (sum > mLargestSum)
				mLargestSum = sum;
			if (sum < mSmallestSum)
				mSmallestSum = sum;
		}
		else
		{
			printPathsRec(root->left,list);
			printPathsRec(root->right,list);
		}
	}
}

void BST::printAllPaths()
{
	std::vector<int> list;
	printPathsRec(mRoot,list);
}

void BST::printLargestSumPath()
{
	std::cout << "smallest Sum : " << mLargestSum;
}

void BST::printSmallestSumPath()
{
	std::cout << "smallest Sum : " << mSmallestSum;
}

int BST::depth(int data)
{
	/*int cnt = 0;
	Node *tra = mRoot;
	while (tra)
	{
		if (data == tra->mData)
			return cnt;
		else
		if (data > tra->mData)
			tra = tra->right;
		else
		if (data < tra->mData)
			tra = tra->left;		

		cnt++;
	}
	return 0;*/

	int d = depth(mRoot, data);
	return d;
}

int  BST::depth(Node *root,int data)
{
	int d = 0;
	if (root)
	{		
		if (root->mData > data)
			d =  1 + depth(root->left,data);
		else
		if (root->mData < data)
			d =  1 + depth(root->right, data);
		else
		if (data == root->mData)
		{
			return d;
		}		
	}

	return d;
}



int BST::count()
{
	std::stack<Node*> st;
	Node *tra = mRoot;
	int count = 0;
	while (!st.empty() || tra)
	{
		if (tra)
		{
			st.push(tra);
			tra = tra->left;
		}
		else
		{
			tra = st.top();
			st.pop();
			count++;
			tra = tra->right;
		}
	}
	return count;
}

bool BST::isBST()
{
	std::stack<Node *> st;
	Node *tra = mRoot;
	while (tra || !st.empty())
	{
		if (tra)
		{
			st.push(tra);
			tra = tra->left;
		}
		else
		{
			tra = st.top();
			if (tra->right && tra->left)
			{
				if (tra->right->mData < tra->left->mData)
				{
					return false;
				}
			}
			st.pop();
			tra = tra->right;
		}
	}
	return true;
}

void BST::deleteItem(int data)
{

}