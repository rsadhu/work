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
    ListNode **tra1 = &(head->next);
    reverse(head, head->next);

    display(*tra1);

    return 0;
}