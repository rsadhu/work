#include <iostream>
#include <vector>

/*

*/
struct Node
{
    int val;
    Node *left, *right;
    Node(int d) : val(d), left(nullptr), right(nullptr)
    {
        std::cout << "\nNode::Node\n";
    }
};

using namespace std;

int getIndex(vector<int> v, int K)
{
    int index = -1;
    auto it = find(v.begin(), v.end(), K);

    // If element was found
    if (it != v.end())
    {
        index = it - v.begin();
    }
    return index;
}

Node *buildTree(vector<int> preOrder, vector<int> inOrder)
{

    if (inOrder.empty() || preOrder.empty())
        return nullptr;

    Node *root = new Node(preOrder[0]);
    int mid = getIndex(inOrder, preOrder[0]);

    std::vector<int> left_preOrder{preOrder.begin() + 1, preOrder.begin() + mid + 1};
    std::vector<int> left_inOrder{inOrder.begin(), inOrder.begin() + mid};
    std::vector<int> right_preOrder{preOrder.begin() + 1 + mid, preOrder.end()};
    std::vector<int> right_inOrder{inOrder.begin() + 1 + mid, inOrder.end()};

    root->left = buildTree(left_preOrder,
                           left_inOrder);

    root->right = buildTree(right_preOrder, right_inOrder);

    return root;
}

int main(void)
{
    std::vector<int> preorder{25, 15, 10, 20, 40, 35, 55}, inorder{10, 15, 20, 25, 35, 40, 55};

    Node *root = nullptr;
    int index = 0;
    root = buildTree(preorder, inorder);

    return 0;
}