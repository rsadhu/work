#include <iostream>

struct ListNode
{
    int data;
    ListNode *next;
    ListNode(int d) : data(d), next(nullptr)
    {
    }
};

ListNode *reverseRec(ListNode *head)
{
    if (!head->next)
    {
        return head;
    }
    else
    {
        head->next = reverseRec(head->next);
        return head;
    }
}

void display(ListNode *head)
{
    std::cout << "\n";
    while (head)
    {
        std::cout << head->data << "  ";
        head = head->next;
    }
    std::cout << "\n";
}

void reverse(ListNode *head, ListNode *second)
{
    if (!second)
        return;

    reverse(head->next, second->next);
    second->next = head;
}

ListNode *reverse(ListNode *head)
{
    ListNode *prev = nullptr, *cur = head;

    while (cur)
    {
        auto tmp = cur->next;
        cur->next = prev;
        prev = cur;
        cur = tmp;
    }

    return prev;
}

/*
    1 2 3 4
    cur=1 rabbit=2
    cur=2 rabbit= 4

    1 2 3 4 5
    cur = 1 rabbit = 2
    cur = 2 rabbit = 4
    cur = 3 rabbit = nullptr
*/
void reorderList(ListNode *head)
{

    if (head && head->next)
    {
        ListNode *cur = head, *rabbit = head->next;
        ListNode *mid = nullptr;

        while (rabbit && rabbit->next)
        {
            cur = cur->next;
            rabbit = rabbit->next->next;
        }

        cur = reverse(cur->next);

        display(head);
        display(cur);

        ListNode *tra = head, *tmp = head;
        ListNode *rev_cur = cur;

        while (tra != cur && rev_cur != nullptr)
        {
            head = tra;
            head->next = rev_cur;
            head = head->next;

            tra = tra->next;
            rev_cur = rev_cur->next;
        }

        head = tmp;
    }
}

ListNode *removeNthNodeFromEnd(ListNode *head, int n)
{

    ListNode *slow = nullptr, *fast = head, *dummy = head;

    while (--n && fast)
    {
        fast = fast->next;
    }

    if (fast->next == nullptr)
    {
        auto tmp = head;
        head = head->next;
        delete tmp;
        return head;
    }

    // move both slow and fast until fast reaches last node
    while (fast->next)
    {
        fast = fast->next;

        if (slow == nullptr)
            slow = head;
        else
            slow = slow->next;
    }

    auto tmp = slow->next;
    slow->next = slow->next->next;
    delete tmp;
    return dummy;
}

int main(void)
{
    ListNode *head = new ListNode(1);
    ListNode *tra = head;
    for (int i = 2; i <= 5; i++)
    {
        tra->next = new ListNode(i);
        tra = tra->next;
    }

    display(head);

    head = removeNthNodeFromEnd(head, 5);
    display(head);

    head = removeNthNodeFromEnd(head, 3);
    display(head);

    head = removeNthNodeFromEnd(head, 1);
    display(head);

    // reorderList(head);

    //    head = reverse(head);

    // display(head);

    return 0;
}