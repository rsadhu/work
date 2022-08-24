#include <array>
#include <iostream>
#include <vector>

class BST
{
public:
    BST(std::vector<int> &list);

private:
    std::vector<int> bst_;
};

BST::BST(std::vector<int> &list)
{
    bst_.resize(list.size(), 0);

    bst_[0] = list[0];

    for (int i = 1; i < list.size(); i++)
    {
        auto it = list[i];
        auto parent = (i - 1) / 2;

        if (it < bst_[i - 1])
            bst_[2 * parent + 1] = it;
        else if (it > bst_[i - 1])
            bst_[2 * parent + 2] = it;
        else
            std::cout << "\n its already there \n";
    }
}

int main(void)
{
    std::vector<int> a{10, 5, 8, 2, 19, 17, 26};
    BST b = a;
    return 0;
}