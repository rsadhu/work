#include <queue>

struct Node {
    int val;
    Node* left = nullptr;
    Node* right = nullptr;
};

std::queue<Node*> q1, q2;

q1.push(root);

while (!q1.empty()) {
    std::vector<int> v;
    while (!q1.empty()) {
        v.push_back(q1.front()->val);
        auto tra = q1.front();
        q1.pop();
        q2.push(tra);
    }

    res.push_back(v);

    while (!q2.empty()) {
        root = q2.front();
        if (root->left) {
            q1.push(root->left);
        }
        if (root->right) {
            q1.push(root->right);
        }
        q2.pop();
    }
}
return res;