#include <iostream>
#include <vector>

struct Node
{
    Node(int d = 0) : data(d), next(nullptr)
    {
    }

    int data = 0;
    Node *next = nullptr;
};

Node *create(std::vector<int> &l)
{
    Node *head = new Node(l[0]);
    Node *ret_ptr = head;
    std::vector<int> n_l = {l.begin() + 1, l.end()};

    for (auto ele : n_l)
    {
        head->next = new Node(ele);
        head = head->next;
    }
    return ret_ptr;
}

void display(Node *head)
{
    while (head)
    {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << "\n";
}

Node *reverse(Node *head)
{
    Node *tmp = nullptr;
    Node *cur = head, *prev = nullptr;
    while (cur)
    {
        prev = cur;
        cur = cur->next;
        prev->next = tmp;
        tmp = prev;
    }
    return tmp;
}

Node *mergeTwoLists(Node *list1, Node *list2)
{
    Node *head = new Node(-1);
    auto tra = head;
    while (list1 && list2)
    {
        if (list1->data <= list2->data)
        {
            head->next = list1;
            list1 = list1->next;
        }
        else
        {
            head->next = list2;
            list2 = list2->next;
        }
        head = head->next;
    }

    while (list1)
    {
        head->next = list1;
        list1 = list1->next;
        head = head->next;
    }

    while (list2)
    {
        head->next = list2;
        list2 = list2->next;
        head = head->next;
    }

    auto tmp = tra;
    tra = tra->next;
    delete tmp;
    return tra;
}

int main(void)
{
    std::vector<int> list = {1, 2, 3, 4, 5, 6, 7, 8};
    Node *head = create(list);

    // display(head);

    // head = reverse(head);

    // display(head);

    std::vector<int> list1 = {1, 2, 3, 4, 5, 6, 7, 8};
    Node *head1 = create(list1);

    Node *tmp = mergeTwoLists(head, head1);
    display(tmp);

    return 0;
}