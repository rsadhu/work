#include <algorithm>
#include <iostream>
#include <random>
#include <vector>
#include <queue>

struct Node
{
    Node(int d) : val(d), left(nullptr), right(nullptr) {}
    int val;
    Node *left;
    Node *right;
};

class TreeMngr
{
    Node *_root = nullptr;

    void inOrder(Node *root)
    {
        if (!root)
            return;

        inOrder(root->left);
        std::cout << root->val << " ";
        inOrder(root->right);
    }

    int sum_nodes(Node *root)
    {
        if (!root)
        {
            return 0;
        }

        return root->val + sum_nodes(root->left) + sum_nodes(root->right);
    }

public:
    void add(int data)
    {
        std::cout << data << " ";
        if (!_root)
        {
            _root = new Node(data);
        }
        else
        {
            Node *tra = _root;
            while (tra)
            {
                if (data > tra->val)
                {
                    if (!tra->right)
                    {
                        tra->right = new Node(data);
                        break;
                    }
                    tra = tra->right;
                }
                else
                {
                    if (!tra->left)
                    {
                        tra->left = new Node(data);
                        break;
                    }
                    tra = tra->left;
                }
            }
        }
    }

    void levelOrder()
    {
        std::cout << "\n\n";
        std::queue<Node *> q;
        q.push(_root);
        while (!q.empty())
        {
            auto node = q.front();
            q.pop();
            std::cout << node->val << " ";
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
    }

    void inOrder()
    {
        std::cout << "\n";
        inOrder(_root);
    }

    int sum_of_all_nodes()
    {
        return sum_nodes(_root);
    }
};

// Function to generate unique random numbers in a range
std::vector<int> generateUniqueRandomNumbers(int start, int end, int count)
{
    if (count > (end - start + 1))
    {
        std::cerr << "Error: Cannot generate more unique numbers than available in the range.\n";
        return {};
    }

    std::vector<int> result;
    for (int i = start; i <= end; ++i)
    {
        result.push_back(i);
    }

    std::random_device rd;
    std::mt19937 g(rd());

    // Shuffle the vector
    std::shuffle(result.begin(), result.end(), g);

    // Resize the vector to the desired count
    result.resize(count);

    return result;
}

int main(void)
{
    TreeMngr tb;

    auto items = generateUniqueRandomNumbers(1, 10, 10);

    for (auto ele : items)
    {
        tb.add(ele);
    }
    std::cout << "\n";

    tb.inOrder();
    tb.levelOrder();

    std::cout << "\n sum is " << tb.sum_of_all_nodes() << "\n";
    return 0;
}