#include <iostream>

struct ListNode
{
    ListNode(int d = 0)
    {
        val = d;
        next = nullptr;
    }
    int val;
    ListNode *next;
};

ListNode *
reverse(ListNode *head)
{
    ListNode *cur = head, *prev = nullptr;

    while (cur)
    {
        auto tmp = cur->next;
        cur->next = prev;
        prev = cur;
        cur = tmp;
    }
    return prev;
}

void display(ListNode *head)
{
    std::cout << "\n";
    while (head)
    {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << "\n";
}

ListNode *reorderList(ListNode *head)
{

    ListNode *mid = nullptr, *slow = head, *fast = head->next;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    mid = reverse(slow->next);

    slow->next = nullptr;

    // display(head);

    // display(mid);

    auto tmp = head;
    auto first = head, second = mid;

    while (second)
    {
        auto tmp1 = first->next, tmp2 = second->next;
        first->next = second;
        second->next = tmp1;
        first = tmp1;
        second = tmp2;
    }
    return tmp;
}

int main(void)
{
    ListNode *tra = nullptr, *head = nullptr;
    for (int i = 1; i <= 8; i++)
    {
        if (!head)
        {
            tra = new ListNode(i);
            head = tra;
        }
        else
        {
            tra->next = new ListNode(i);
            tra = tra->next;
        }
    }

    display(head);

    reorderList(head);

    display(head);
    return 0;
}