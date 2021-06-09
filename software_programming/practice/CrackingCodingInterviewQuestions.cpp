//
// Created by rsadhu on 13.03.20.
//

#include <iostream>
#include <vector>
#include <set>
#include <stack>

struct Node {
    Node(int d) : data(d), next(nullptr) {}

    int data;
    Node *next = nullptr;
};


Node *
createList(std::vector<int> l) {
    Node *head = nullptr, *tra = nullptr;
    for (auto it: l) {
        if (!head) {
            head = new Node(it);
            tra = head;
        } else {
            Node *tmp = new Node(it);
            tra->next = tmp;
            tra = tra->next;
        }
    }
    return head;
}

void display(Node *tra) {
    while (tra) {
        std::cout << tra->data << " ";
        tra = tra->next;
    }
}

Node *removeDuplicates(Node *tra) {
    std::set<int> lu;
    Node *prev = tra, *head = tra;

    while (tra) {
        if (lu.count(tra->data) == 0)
            lu.insert(tra->data);
        else {
            prev->next = tra->next;
            auto tmp = tra;
            tra = tra->next;
            delete tmp;
            continue;
        }
        prev = tra;
        tra = tra->next;
    }
    return head;
}

void removeMiddleItem(Node *head) {
    Node *cur = head, *jumper = head;
    while (jumper && jumper->next) {
        jumper = jumper->next;
        jumper = jumper->next;
        cur = cur->next;
    }
    std::cout << "\nMiddle element is :  " << cur->data;
}


int sumOfTwoLinkLists(Node *l1, Node *l2) {
    if (l1 && l2)
        return l1->data + l2->data + sumOfTwoLinkLists(l1->next, l2->next);
    else if (l1)
        return l1->data + sumOfTwoLinkLists(l1->next, l2);
    else if (l2) {
        return l2->data + sumOfTwoLinkLists(l1, l2->next);
    } else
        return 0;
}

void isPalindrome(Node **front, Node *end, bool &res)
{
    if (!end)
        return ;

    isPalindrome(front, end->next, res);

    if (end->data == (*front)->data)
        res &= true;
    else
        res &= false;

    (*front) = (*front)->next;
}

bool hasLoop(Node *list)
{

}

void cci_linklist() {
    Node *head = createList({0, 1, 1, 1, 2, 2, 3, 4, 9, 9});

    std::cout << " \n   display  \n";

    display(head);

    head = removeDuplicates(head);

    std::cout << " \n   display \n";

    display(head);

    removeMiddleItem(head);

    Node *l1 = createList({9, 2, 3, 9, 1, 5, 6, 0});
    Node *l2 = createList({4, 3, 1, 9});

    std::cout << " \nsum of the linklists::  " << sumOfTwoLinkLists(l1, l2);
    bool res(true);
    isPalindrome(&l1, l1, res);

    std::cout<< "\n if linklist is palindrome :: "<<res;

//    std::cout<<" link list has a loop "<< hasLoop(l1);

}

void cci_matrix() {
    std::vector<std::vector<int>> matrix = {{1,  2,  3,  4},
                                            {5,  6,  7,  8},
                                            {9,  -8, -7, -6},
                                            {-5, -4, -3, -2}
    };

    ///turnMatrixLeft
    auto print = [&]() {
        std::cout << "\n";
        for (auto it: matrix) {
            for (auto inIt : it) {
                std::cout << inIt << " ";
            }
            std::cout << "\n";
        }

        std::cout << "\n";
    };

    print();

    // transpose
    for (int i = 0; i < matrix.size(); i++) {
        for (int k = i; k < matrix.size(); k++) {
            auto tmp = matrix[i][k];
            matrix[i][k] = matrix[k][i];
            matrix[k][i] = tmp;
        }
    }

    print();

    // swap

    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix.size() / 2; j++) {
            auto tmp = matrix[j][i];
            matrix[j][i] = matrix[matrix.size() - j - 1][i];
            matrix[matrix.size() - j - 1][i] = tmp;
        }
    }

    print();
}

inline void cci_queue_from_stacks()
{
    class MyQueue{
        public:
        void enqueu(int d)
        {
            __enq_st.push(d);
        }

        bool empty() const
        {
            if (!__enq_st.empty() || !__deq_st.empty())
                return false;

            return true;
        }
        int deque()
        {
            if (__deq_st.empty() )
            {
                if (__enq_st.empty()) {
                    throw std::runtime_error("queue is empty");
                }
                else {
                 while(!__enq_st.empty()){
                     __deq_st.push(__enq_st.top());
                     __enq_st.pop();
                 }
                }
            }

            auto ret = __deq_st.top();
            __deq_st.pop();
            return ret;
        }
        private:
        std::stack<int> __enq_st, __deq_st;
    };


    MyQueue q;
    q.enqueu(1);
    q.enqueu(2);
    q.enqueu(3);
    q.enqueu(4);
    q.enqueu(5);
    q.enqueu(6);

    while(!q.empty())
    {
        std::cout<< q.deque()<<"  ";
    }

}

int main(void) {


   //   cci_matrix();
//    cci_linklist();
   //cci_queue_from_stacks();
   return 0;
}