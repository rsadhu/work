#include <queue>
#include <vector>
#include <iostream>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
public:
  std::vector<std::vector<int>> levelOrderBottom(TreeNode *root) {
    std::vector<std::vector<int>> traversalList;

    std::queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
      std::vector<int> layer;
      std::queue<TreeNode *> q1;
      while (!q.empty()) {
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
      std::queue<TreeNode *> empty;
      std::swap(q1, empty);
    }
    std::vector<std::vector<int>> res(traversalList.rbegin(),
                                      traversalList.rend());
    return res;
  }

  std::vector<int> prisonAfterNDays(std::vector<int> &cells, int N) {
    std::vector<int> tmp(cells);
    tmp[0] = tmp[tmp.size() - 1] = 0;
    //auto fac = cells.size()*2;
    //N = N / fact  + N % fact;
    while (N) {
      for(auto it: cells)
      {
        std::cout<<it<<"  ";
      }
      std::cout<<"\n";

      for (int i = 1; i < cells.size() - 1; i++) {
        if (cells[i - 1] == cells[i + 1]) {
          tmp[i] = 1;
        } else {
          tmp[i] = 0;
        }
      }
      cells = tmp;
      N--;
    }
    return cells;
  }
};

int main(void) {
  Solution s;
  TreeNode *root = new TreeNode(10);
  root->left = new TreeNode(5);
  root->right = new TreeNode(15);

  root->left->left = new TreeNode(2);
  root->left->right = new TreeNode(8);

  root->right->left = new TreeNode(12);
  root->right->right = new TreeNode(18);

  auto res = s.levelOrderBottom(root);

  /*
   * *[1,0,0,1,0,0,1,0]
1000000000
   */
  std::vector<int> p = {1,0,0,1,0,0,1,0};
  auto r = s.prisonAfterNDays(p, 4000);
  return 0;
}