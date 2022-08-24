#include <iostream>

struct Node
{
    Node(int d)
    {
        val = d;
        next = nullptr;
    }

    int val;
    struct Node *next = nullptr;
};

Node *create(int d)
{
    return new Node(d);
}

void display(Node *root)
{
    std::cout << "\n";
    while (root)
    {
        std::cout << root->val << " ";
        root = root->next;
    }
    std::cout << "\n";
}

void reverse(Node *root)
{
    Node *tmp = nullptr;
    Node *cur = root;
    Node *prev;
    while (cur)
    {
        prev = cur;
        cur = cur->next;
        prev->next = tmp;
    }
}

int main(void)
{
    Node *root = create(10);
    root->next = create(20);
    root->next->next = create(30);
    root->next->next->next = create(40);
    root->next->next->next->next = create(50);
    root->next->next->next->next->next = create(60);

    display(root);
    reverse(root);

    return 0;
}
