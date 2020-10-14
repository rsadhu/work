#include "Arrays.h"
#include "LinkList.h"
#include "Searching.h"
#include "RecursionExamples.h"
#include "BST.h"
#include "Graphs.h"
#include "Sorting.h"

void
Test_Vector() {
    GPrep::Vector<int> v(2, 0);
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    std::cout << "\n";
    for (int i = 0; i < v.size(); i++) {
        std::cout << " \nvalue==  is " << v[i];
    }

    v.insert(0, 0);
    v.insert(5, 5);
    v.insert(3, -9);

    std::cout << "\n";

    for (int i = 0; i < v.size(); i++) {
        std::cout << v[i] << " ";
    }

    std::cout << "\n";


    for (int i = 0; i < 5; i++) {
        v.push_back(i + 9);
    }


    for (int i = 0; i < v.size(); i++) {
        std::cout << v[i] << " ";
    }

    auto sz = v.size();

    std::cout << "\n";

    for (int i = 0; i < sz; i++)
        std::cout << v.pop_back() << " ";

    std::cout << "\n";
    for (int i = 0; i < 5; i++) {
        v.push_back(i + 9);
    }

    std::cout << "\n";

    for (int i = 0; i < v.size(); i++) {
        std::cout << v[i] << " ";
    }

    for (int i = 0; i < 5; i++) {
        v.insert(0, i + 19);
    }

    std::cout << "\n";

    for (int i = 0; i < v.size(); i++) {
        std::cout << v[i] << " ";
    }

    for (int i = 0; i < 5; i++) {
        v.insert(v.size(), i + 19);
    }

    std::cout << "\n";

    for (int i = 0; i < v.size(); i++) {
        std::cout << v[i] << " ";
    }

    sz = v.size();

    for (int i = 0; i < sz / 2; i++)
        v.remove(3);

    std::cout << "\n";
    for (int i = 0; i < v.size(); i++) {
        std::cout << v[i] << " ";
    }

    std::cout << "\n" << v.find(21) << " " << v.find(100);
}


void
Test_LinkList() {
    LinkList<int> linklist;
    linklist < 1 < 2 < 3 < 4 < 5 < 6;

    linklist.display();
    std::cout << "\n" << linklist.front();

    std::cout << "\n" << linklist.back();


    linklist.erase(0);
    linklist.display();

    std::cout << "\n" << linklist.front();

    std::cout << "\n" << linklist.back();


    linklist.insert(0, 99);
    linklist.display();

    std::cout << "\n" << linklist.front();

    std::cout << "\n" << linklist.back();


    linklist.erase(4);
    linklist.display();

    linklist.insert(3, 100);
    linklist.display();

    std::cout << "\n" << linklist.front();

    std::cout << "\n" << linklist.back();

    std::cout << "\n" << linklist.value_n_from_end(1);
    linklist.reverse(); // not workin yet
    linklist.display();
}

void Test_BinSearch() {
    Searching ss;
    ss < 10 < -9 < 0 < 11 < 2 < 5 < 7 < 3 < 8 < 4 < -3 < -4;
    ss.display();
    std::cout << " \nis 0 in list " << ss.search(0) << "\n";
    std::cout << " is 11 in list " << ss.search(11) << "\n";
    std::cout << " is 4 in list " << ss.search(4) << "\n";
    std::cout << " is -9 in list " << ss.search(-9) << "\n";
    std::cout << " is 100 in list " << ss.search(100) << "\n";

}

void Test_Recursion() {
    std::cout << " \npower of 2 to 4 " << power(2, 4);
    std::cout << " \nfactorial of 4 " << factorial(4);
}

void Test_BST() {
    Trees::BST bst;
    bst < 10 < 2 < 5 < 7 < 15 < 12 < 18;
    bst.dfs();
    std::cout << "\nMax: >>  " << bst.max() << "\n";
    std::cout << "\nMin: >>  " << bst.min() << "\n";
    std::cout << " \n 2,  is this ele present:: " << bst.isInBST(2) << "\n";
    std::cout << " \n-2,  is this ele present:: " << bst.isInBST(-2) << "\n";
    std::cout << " \n 21, is this ele present:: " << bst.isInBST(21) << "\n";
    std::cout << " \n 22, is this ele present:: " << bst.isInBST(12) << "\n";

    bst.bfs();

    std::cout << "\nis tree a bst  " << bst.isBST(bst.root());

    std::cout << " \n number of elements in BST " << bst.count() << "\n";
    std::cout << " the sum of all nodes in the BST is " << bst.totalSum();

}

void Test_Sorting() {
    std::vector<int> l{2, 1, 3, 4, 6, 7};
    //bubbleSort(l);
    selectionSort(l);
    auto display = [](const std::vector<int> &l) {
        std::cout << "\n";
        for (auto it: l) {
            std::cout << it << "  ";
        }
        std::cout << "\n";
    };
//
    display(l);

    std::vector<int> m{2, 1, -23, 3, 16, 7, 0, 0, 1, -23, 10, 19, -10, 100};

    //bubbleSort(m);
    //selectionSort(m);

    display(m);

//    insertionSort(m);
    quickSort(m);
    //heapSort(m);
    display(m);


    std::vector<int> arrv = {9, -8, 0, 1, 4, -3, 7, 2, 5, 3};

    auto pr = [](auto &v) {
        std::cout << "\n";
        for (auto it: v) {
            std::cout << it << " ";
        }
        std::cout << "\n";
    };

    pr(arrv);

    mergeSort(arrv, 0, arrv.size() - 1);

    pr(arrv);
}

void Test_Graph() {
    std::vector<std::vector<int>> grp = {
            {0, 1, 1, 1, 0, 0},
            {1, 0, 0, 0, 1, 0},
            {1, 0, 0, 0, 0, 1},
            {1, 0, 0, 0, 0, 1},
            {0, 1, 0, 0, 0, 1},
            {0, 0, 1, 0, 1, 0}
    };

    bfs(grp, 1);


    bfs(grp, 3);

    dfs(grp, 3);

    dfs(grp, 1);
}

int
main(void) {

    // Test_Vector();
    //Test_LinkList();
    //Test_BinSearch();
    //Test_Recursion();

    //Test_BST();
    //Test_Sorting();
    Test_Graph();
    return 0;
}

