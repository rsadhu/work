#ifndef __BST__H__
#define __BST__H__
#pragma once

#include <queue>
#include <stack>

namespace Trees
{
    struct Node
    {
    public:
        Node(int d = 0) : __data(d), __left(nullptr), __right(nullptr) {}

        int __data;
        Node *__left = nullptr, *__right = nullptr;
    };

    class BST
    {
    public:
        BST &operator<(int d);

        void dfs();

        void bfs();

        Node *root() { return __root; }

        Node *createBST(std::vector<int>, std::vector<int>);

        int height() const { return height(__root); }

        int max() const { return max(__root); }

        int min() const { return min(__root); }

        int totalSum() const
        {
            return (totalSumIter(__root) + totalSumRec(__root)) / 2;
        }

        int count() const { return (countIter(__root) + countRec(__root)) / 2; }

        void deleteItem(int refItem);

        void insert(int item, int refItem);

        int successor(int refItem) const;

        bool isBST(Node *root) const;

        bool isInBST(int ele) const;

    protected:
        static Node *createBSTRec(Node *, int);

        static int min(Node *);

        static int max(Node *);

        static int height(Node *);

        static int countIter(Node *);

        static int countRec(Node *);

        static int totalSumIter(Node *);

        static int totalSumRec(Node *);

        static void inOrderRec(Node *);

        static void postOrderIter(Node *);

        static void preOrderRec(Node *);

        static void preOrderIter(Node *);

        static void postOrderRec(Node *);

        static void inOrderIter(Node *);

    private:
        Node *__root = nullptr;
    };

    bool BST::isBST(Node *root) const
    {
        if (!root)
        {
            return true;
        }
        if (root->__left && root->__left->__data > root->__data)
        {
            return false;
        }

        if (root->__right && root->__right->__data < root->__data)
        {
            return false;
        }

        if (isBST(root->__left) || isBST(root->__right))
            return false;

        return true;
    }

    int BST::countRec(Node *root)
    {
        if (root)
        {
            return 1 + countRec(root->__left) + countRec(root->__right);
        }
        return 0;
    }

    int BST::countIter(Node *root)
    {
        std::stack<Node *> stack;
        int count = 0;
        while (root || !stack.empty())
        {
            while (root)
            {
                stack.push(root);
                root = root->__left;
            }

            root = stack.top();
            count++;
            stack.pop();
            root = root->__right;
        }
        return count;
    }

    int BST::totalSumRec(Node *root)
    {
        if (root)
        {
            return root->__data + totalSumRec(root->__left) +
                   totalSumRec(root->__right);
        }
        return 0;
    }

    int BST::totalSumIter(Node *root)
    {
        std::stack<Node *> stack;
        int sum = 0;
        while (root || !stack.empty())
        {
            while (root)
            {
                stack.push(root);
                root = root->__left;
            }

            root = stack.top();
            sum += root->__data;
            stack.pop();
            root = root->__right;
        }
        return sum;
    }

    void BST::deleteItem(int refItem) {}

    void BST::insert(int item, int refItem) {}

    int BST::successor(int refItem) const {}

    int BST::height(Node *root) {}

    Node *BST::createBST(std::vector<int>, std::vector<int>) {}

    Node *BST::createBSTRec(Node *root, int d)
    {
        if (!root)
        {
            return new Node(d);
        }
        if (d < root->__data)
        {
            root->__left = createBSTRec(root->__left, d);
        }
        else
        {
            root->__right = createBSTRec(root->__right, d);
        }
    }

    BST &BST::operator<(int d)
    {
        if (!__root)
        {
            __root = new Node(d);
        }
        else
        {
            //__root = createBSTRec(__root, d); for recursive coding

            Node *tra = __root;
            while (tra)
            {
                if (tra->__data < d)
                {
                    if (tra->__right)
                    {
                        tra = tra->__right;
                    }
                    else
                    {
                        tra->__right = new Node(d);
                        break;
                    }
                }
                else
                {
                    if (tra->__left)
                    {
                        tra = tra->__left;
                    }
                    else
                    {
                        tra->__left = new Node(d);
                        break;
                    }
                }
            }
        }
        return *this;
    }

    void BST::dfs()
    {
        std::cout << "\n inOrderRec \n";
        inOrderRec(__root);
        std::cout << "\n preOrderRec \n";
        preOrderRec(__root);
        std::cout << "\n postOrderrec\n";
        postOrderRec(__root);

        // iterative methods

        std::cout << "\n inorderIter \n";
        inOrderIter(__root);

        std::cout << "\n  preOrderIter \n";
        preOrderIter(__root);

        std::cout << "\n postOrderIter \n";
        postOrderIter(__root);
    }

    void BST::bfs()
    {
        std::queue<Node *> queue;
        queue.push(__root);
        while (!queue.empty())
        {
            Node *cur = queue.front();
            std::cout << cur->__data << " ";
            if (cur->__left)
                queue.push(cur->__left);
            if (cur->__right)
                queue.push(cur->__right);
            queue.pop();
        }
    }

    void BST::inOrderRec(Node *root)
    {
        if (root)
        {
            inOrderRec(root->__left);
            std::cout << root->__data << " ";
            inOrderRec(root->__right);
        }
    }

    void BST::preOrderRec(Node *root)
    {
        if (root)
        {
            std::cout << root->__data << " ";
            preOrderRec(root->__left);
            preOrderRec(root->__right);
        }
    }

    void BST::postOrderRec(Node *root)
    {
        if (root)
        {
            postOrderRec(root->__left);
            postOrderRec(root->__right);
            std::cout << root->__data << " ";
        }
    }

    void BST::inOrderIter(Node *root)
    {
        std::stack<Node *> stack;
        while (root || !stack.empty())
        {
            while (root)
            {
                stack.push(root);
                root = root->__left;
            }

            root = stack.top();
            std::cout << root->__data << " ";
            stack.pop();
            root = root->__right;
        }
    }

    void BST::preOrderIter(Node *root) {}

    void BST::postOrderIter(Node *root) {}

    int BST::max(Node *root)
    {
        while (root->__right)
        {
            root = root->__right;
        }
        return root->__data;
    }

    int BST::min(Node *root)
    {
        while (root->__left)
        {
            root = root->__left;
        }
        return root->__data;
    }

    bool BST::isInBST(int ele) const
    {
        std::stack<Node *> st;
        Node *cur = __root;

        while (cur || !st.empty())
        {
            while (cur)
            {
                if (cur->__data == ele)
                    return true;
                st.push(cur);
                cur = cur->__left;
            }

            cur = st.top();
            st.pop();
            if (cur->__data == ele)
                return true;
            cur = cur->__right;
        }
        return false;
    }

} // namespace Trees
#endif