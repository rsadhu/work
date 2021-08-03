//
// Created by rsadhu on 13.07.20.
//
#include <iostream>
#include<vector>

struct Node {
    Node(int d) : val(d) {}

    int val;
    Node *prev = nullptr;
    Node *next = nullptr;
    Node *child = nullptr;
};

void flattenImpl(Node *head, Node *tra) {
    if (head) {
        if (head->child) {
            tra->next = head->child;
            tra = tra->next;
            flattenImpl(head->child, tra);
        }
        tra->next = head;
        tra = tra->next;
        flattenImpl(head->next, tra);
    }
}


Node *flatten(Node *head) {
    Node *tra = head;
    flattenImpl(head, tra);
    return tra;
}
//[1,2,3,4,5,6,null,null,null,7,8,9,10,null,null,11,12]

using ListNode = Node;

void removeFromNthElem(ListNode *head, ListNode *prev, int &n) {
    if (head) {
        removeFromNthElem(head->next, prev->next, n);
        if (n == 0) {
            prev->next = head->next;
            delete head;
        }
        //n--;
    }
    n--;
}

ListNode *removeNthFromEnd(ListNode *head, int n) {
    ListNode *prev = head;
    removeFromNthElem(head->next, prev, n);
    return head;
}

void print(Node *head, std::vector<int> &tra) {
    if (!head) {
        return ;
    }

    tra.push_back(head->val);
    if (head->child)
        print(head->child, tra);
    if (head)
        print(head->next, tra);
}

int main(void) {
    Node *head, *tra, *todel;

    head = new Node(1);
    Node *cur = new Node(0);

    head->next = new Node(2);

    Node *tra1 = head->next;

    head->next->next = new Node(3);

    head->next->next->next = new Node(4);

    Node *tra2 = head->next->next->next;


    head->next->next->next->next = new Node(5);

    tra1->child = new Node(20);
    tra1->child->next = new Node(21);
    tra1->child->next->next = new Node(22);

    tra2->child = new Node(40);
    tra2->child->next = new Node(41);
    tra2->child->next->next = new Node(42);

    auto  rotate = [](std::vector<int>& nums, int k) {
        for(int i = 0; i < k % nums.size() ;i++)
        {
            int tmp = nums[nums.size()-1];

            for(int j = nums.size(); j> 0; j--)
            {
                nums[j] = nums[j-1];
            }
            nums[0]= tmp;
        }
    };

    std::vector<int> v{-1,-100,3,99};
    rotate(v, 2);


    return 0;
}