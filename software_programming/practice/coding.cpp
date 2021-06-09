#include <queue>
#include <vector>
#include <iostream>
#include <set>
#include <stack>
#include <map>
#include <string>
#include <algorithm>
#include <cmath>

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
        std::set<std::vector<int>> lookup;
        tmp[0] = tmp[tmp.size() - 1] = 0;
        int M = N;
        while (N) {

            for (auto it: cells) {
                std::cout << it << "  ";
            }
            std::cout << "\n";

            for (int i = 1; i < cells.size() - 1; i++) {
                if (cells[i - 1] == cells[i + 1]) {
                    tmp[i] = 1;
                } else {
                    tmp[i] = 0;
                }
            }
            cells = tmp;
            N--;
            if (lookup.count(cells) == 0)
                lookup.insert(cells);
            else {
                break;
            }
        }
        auto sz = lookup.size();
        if (sz < M) {
            int f = M % sz;
            if (f != 0)
                return *next(lookup.begin(), f);
            else
                return *next(lookup.end());
        }
        return cells;
    }
};


int nthUglyNumber(int n) {
    int j = 0;
    std::set<int> l;
    l.insert(1);
    while (l.size() < n) {
        j++;

        if (j % 2 == 0 || j % 3 == 0 || j % 5 == 0) {
            l.insert(j);
        }

    }

    return *l.end();
}

int getNthUglynumber(int n) {
    int last2 = 0;
    int last3 = 0;
    int last5 = 0;

    std::vector<int> result(n, 0);
    result[0] = 1;
    for (int i = 1; i < n; ++i) {
        long prev = result[i - 1];

        while (result[last2] * 2 <= prev) {
            ++last2;
        }
        while (result[last3] * 3 <= prev) {
            ++last3;
        }
        while (result[last5] * 5 <= prev) {
            ++last5;
        }

        long candidate1 = result[last2] * 2;
        long candidate2 = result[last3] * 3;
        long candidate3 = result[last5] * 5;

        result[i] = std::min(candidate1, std::min(candidate2, candidate3));
    }
    return result[n - 1];
}


std::vector<int> plusOne(std::vector<int> &digits) {
    std::stack<int> rr;
    int carry = 0;
    for (int i = digits.size() - 1; i > 0; i--) {
        int tmp = digits[i] + 1 + carry;
        auto rm = tmp % 10;
        carry = tmp / 10;
        rr.push(rm);
    }
    std::vector<int> res;

    while (!rr.empty()) {
        res.push_back(rr.top());
        rr.pop();
    }

    return res;
}

void rotate(std::vector<int> &nums, int k) {
    for (int i = 0; i < k; i++) {
        int tmp = nums[nums.size() - 1];

        for (int j = nums.size(); j > 0; j--) {
            nums[j] = nums[j - 1];
        }
        nums[0] = tmp;
    }
}


std::vector<int> intersect(std::vector<int> &nums1, std::vector<int> &nums2) {
    std::map<int, int> result;
    std::vector<int> ans;
    for (auto it: nums1) {
        result[it] += 1;
    }

    for (auto it: nums2) {
        auto item = result.find(it);
        if (item->second > 0) {
            ans.push_back(it);
            result[it] -= 1;
        }
    }
    return ans;
}

using twodarr = std::vector<std::vector<int>>;

void rotateImageBy90(twodarr &rhs) {
    for (int i = 0; rhs.size(); i++) {

    }
}

int reverse(int x) {
    auto str = std::to_string(x);
    int sign = 1;
    if (str[str.length() - 1] == '0')
        str = str.substr(0, str.length() - 1);

    if (str[0] == '-') {
        sign = -1;
        str = str.substr(1);
    }
    std::reverse(str.begin(), str.end());
    return sign * std::stoi(str);
}

struct Node {
    Node(int d) : data(d), left(nullptr), right(nullptr) {}

    Node *left, *right;
    int data;
};


struct LinkList {
    LinkList(int d) : data(d), next(nullptr) {}

    int data;
    LinkList *next;
};


void createLLFromBST(Node *root, LinkList *tra) {
    if (root) {
        createLLFromBST(root->left, tra);
        tra->next = new LinkList(root->data);
        tra = tra->next;
        createLLFromBST(root->right, tra);
    }
}
/*
bool isPalindrome(std::string s) {

    int i = 0, sz = s.length() - 1;
    while (i < sz) {

        auto first = tolower(s[i]);
        auto second = tolower(s[sz]);

        if ( (first < 'a' && first > 'z') || first == ' ' ||) {
            i++;
            continue;
        }

        if ((second < 'a' && second > 'z' ) || second == ' ' ) {
            sz--;
            continue;
        }

        if (first != second)
            return false;

        i++;
        sz--;
    }
    return true;
}*/

uint32_t reverseBits(uint32_t n = 43261596) {
    // std::string s = std::to_string(n);
    // std::reverse(s.begin(), s.end());
    // n = std::stoi(s);
    int times = sizeof(uint32_t)*8 -1;
    int para = std::pow(2, times-1);
    para = para >> 1;
    while(times--)
    {
        int x = n &1 ;
        n = n>>1;
        if (x==1)
        {
            n = n | para;
        }
    }

    return n;
}


int main(void) {

    uint8_t uin = -2;
    std::cout<<uin;

    auto tmpppp = reverseBits();
    //std::cout << isPalindrome("A man, a plan, a canal: Panama");
    Node *root1 = new Node(10);
    root1->left = new Node(5);
    root1->right = new Node(15);

    root1->left->left = new Node(3);
    root1->left->right = new Node(6);

    root1->right->left = new Node(12);
    root1->right->right = new Node(20);
    LinkList *tra = new LinkList(0);

    createLLFromBST(root1, tra);

    auto rrr = reverse(123);
    std::vector<int> r1{4, 9, 5}, r2{9, 4, 9, 8, 4};
    auto inter = intersect(r1, r2);
    std::vector<int> ar = {-1, -100, 3, 99};
    rotate(ar, 2);
    Solution s;
    std::vector<int> sss = {4, 3, 2, 9};
    plusOne(sss);
    auto n = nthUglyNumber(10);
    std::cout << n;
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);

    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(8);

    root->right->left = new TreeNode(12);
    root->right->right = new TreeNode(18);

    auto res = s.levelOrderBottom(root);

    /*
 [0,1,1,1,0,0,0,0]
9 9
     */
    std::vector<int> p = {0, 1, 1, 1, 0, 0, 0, 0};
    auto r = s.prisonAfterNDays(p, 99);

    auto nn = getNthUglynumber(1000);
    return 0;
}


/*
int hammingDistance(int x, int y) {
  int cnt = 0;
  auto x1 = std::min(x, y);
  auto y1 = std::max(x, y);
  while(y1)
  {
    x = x1 &1;
    y = y1 &1;
    if ((x1 & 1) != (y1 & 1))
      cnt++;

    x1>>=1;
    y1>>=1;
  }
  return cnt;
}

int main(void) {
  Solution s;
  hammingDistance(1, 4);
  TreeNode *root = new TreeNode(10);
  root->left = new TreeNode(5);
  root->right = new TreeNode(15);

  root->left->left = new TreeNode(2);
  root->left->right = new TreeNode(8);

  root->right->left = new TreeNode(12);
  root->right->right = new TreeNode(18);

  auto res = s.levelOrderBottom(root);

  std::vector<int> p = {1,0,0,1,0,0,1,0};
  auto r = s.prisonAfterNDays(p, 4000);
  return 0;
}*/
