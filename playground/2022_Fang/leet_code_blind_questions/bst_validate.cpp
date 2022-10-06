#include <iostream>

struct TreeNode
{
    TreeNode(int d) : val(d)
    {
    }
    int val;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;
};

/*
         20
    15       25
  12  17  28     30

max = 99 , 20
20 15
20 12


 */

void usingInorder(TreeNode *root, int big, bool &res)
{
    if (!root)
    {
        res = true;
        return;
    }

    big = root->val;

    usingInorder(root->left, big, res);

    if (big >= root->val)
        res &= true;
    else
        res &= false;

    usingInorder(root->right, big, res);
}

int main(void)
{

    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);

    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(7);

    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(25);

    int max = INT_MAX;
    bool res = true;

    usingInorder(root, max, res);

    return 0;
}