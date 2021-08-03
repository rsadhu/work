//
// Created by rsadhu on 24.04.20.
//

#include <vector>
#include <string>
#include <map>
#include <set>
#include <iostream>
#include <algorithm>




std::vector<std::string> repeatedDNASequences(std::string s) {
    std::map<std::string, int> str_cnt_map;

    for (int i = 0; (i + 10) <= s.length(); i++) {
        str_cnt_map[s.substr(i, 10)]++;
    }

    std::vector<std::string> res;
    for (auto it:str_cnt_map) {
        if (it.second > 1)
            res.push_back(it.first);
    }
    return res;
}

void swap(int &a, int &b) {
//    a = a + b;
//    b = a-b;
//    a = a-b;

    a = a ^ b;
    b = a ^ b;
    a = b ^ a;
}

void max_subarray() {
    std::vector<int> arr = {2, -8, 3, -2, 4, -10};
    int best_sum = 0, current_sum = 0;
    for (auto it: arr) {
        current_sum = std::max(0, current_sum + it);
        best_sum = std::max(best_sum, current_sum);
    }

    std::cout << best_sum;
}

template<typename T=int>
struct LinkList {
    LinkList(T d) : data(d), next(nullptr) {}

    LinkList *next = nullptr;
    T data;
};

LinkList<int> *removeDupes(LinkList<int> *n) {
    std::set<int> lu;
    LinkList<int> *m = nullptr, *tra = nullptr;
    while (n) {
        if (lu.insert(n->data).second) {
            if (!tra) {
                m = n;
                tra = m;
            } else {
                m->next = n;
                m = m->next;
            }
        }
        n = n->next;
    }
    return tra;
}

void printKthFromLastinLinkList(LinkList<int> *n, int k) {
    LinkList<int> *cur = n, *prev = n;
    int cnt = 0;
    while (cur && cnt < k) {
        cnt++;
        cur = cur->next;
    }
    while (cur) {
        prev = prev->next;
        cur = cur->next;
    }
    std::cout << k << "th item: >   " << prev->data << "   \n";
}


LinkList<int> *reverseExistingLinkList(LinkList<int> *list) {
    LinkList<int> *head = nullptr;
    while (list) {
        LinkList<int> *n = new LinkList<int>(list->data);
        n->next = head;
        head = n;
        list = list->next;
    }
    return head;
}

class Node {
public:
    Node(int d) : data(d), left(nullptr), right(nullptr) {}

    int data;
    Node *left;
    Node *right;
};

Node *createBSTFromArray(std::vector<int> rhs, int begin, int end) {
    if (end < begin)
        return nullptr;

    int mid = (begin + end) / 2;

    Node *n = new Node(rhs[mid]);

    n->left = createBSTFromArray(rhs, begin, mid - 1);
    n->right = createBSTFromArray(rhs, mid + 1, end);
    return n;
}

void inOrder(Node *n) {
    if (n) {
        inOrder(n->left);
        std::cout << n->data << "  ";
        inOrder(n->right);
    }
}

int height(Node *root) {
    if (!root)
        return -1;
    return 1 + std::max(height(root->left), height(root->right));
}


void createBSTFromArray(std::vector<int> rhs) {
    std::sort(rhs.begin(), rhs.end());
    Node *root = createBSTFromArray(rhs, 0, rhs.size() - 1);

    std::cout << " \n";
    inOrder(root);
    std::cout << " \n";

    std::cout << height(root);
}

/*(1, 5), (10, 15), (20, 25)] + (12, 27) => [(1, 5), (10, 27)]*/
void mergeInterval(std::vector<std::pair<int,int>> &list, std::pair<int,int> pair)
{
    if (list.empty()) {
        list.push_back(pair);
    }
    else {
        int prev = 0;
        for (int i = 0; i < list.size(); i++) {
            if (list[i].first > pair.first) {
                break;
            }
            prev = i;
        }
        bool f = false;
        for (int j = prev; j < list.size(); j++) {
            if (list[j].second > pair.second) {
                list.insert(list.begin() + prev+1, pair);
                f =  true;
                break;
            }
        }

        if( !f )
        {
            std::vector<std::pair<int, int> > newList(list.begin(), list.begin()+prev);
            list =  newList;
        }
    }
}

int main(void) {

    std::vector<std::pair<int,int>> inter {{1, 5}, {10, 15}, {20, 25}};
    std::pair<int, int> pair {12, 17};

    mergeInterval(inter, pair);


    std::vector<std::pair<int,int>> inter1 {{1, 5}, {10, 15}, {20, 25}};
    std::pair<int, int> pair1 {12, 27};

    mergeInterval(inter1, pair1);

    int a = 1, b = 2;
    swap(a, b);
    std::cout << a << "   " << b << "\n";

    max_subarray();

    LinkList<int> *tra;
    LinkList<int> *head = new LinkList<int>(10);
    tra = head;
    head->next = new LinkList<int>(1);
    head = head->next;
    head->next = new LinkList<int>(1);
    head = head->next;
    head->next = new LinkList<int>(3);
    head = head->next;
    head->next = new LinkList<int>(2);
    head = head->next;
    head->next = new LinkList<int>(1);
    head = head->next;
    head->next = new LinkList<int>(5);

    std::cout << "\n";
    for (auto nnn = tra; nnn; nnn = nnn->next) {
        std::cout << nnn->data << " ";
    }
    std::cout << "\n";
    auto nn = removeDupes(tra);
    std::cout << "\n";
    while (nn) {
        std::cout << nn->data << " ";
        nn = nn->next;
    }
//    printKthFromLastinLinkList(tra, 2);
    //   printKthFromLastinLinkList(tra, 7);
    //  printKthFromLastinLinkList(tra, 3);
    std::cout << "\n";

    auto reply = reverseExistingLinkList(tra);

    for (auto nnn = reply; nnn; nnn = nnn->next) {
        std::cout << nnn->data << " ";
    }

    createBSTFromArray({3, 1, 2, 5, 6, 9, 0, 8, 7, 4});
    return 0;
}

