/**
 * Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */



class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        std::vector<std::vector<int>> traversalList;

        std::queue<TreeNode*> q;
        while(root || !q.empty())
        {
            q.push(root);
            std::vector<int> layer;
            std::queue<TreeNode*> q1;
            while(!q.empty())
            {
                auto node = q.front();
                layer.push_back(node->val);
                if (node->left)
                    q1.push(node->left);
                if (node->right)
                    q1.push(node->right);
                q.pop();
            }
            q = q1;
            traversalList.push_back(layer);
            std::queue<TreeNode*> empty;
            std::swap( q1, empty );
        }
        std::vector<std::vector<int>> res (traversalList.rbegin(), traversalList.rend());
        return res;
    }
};