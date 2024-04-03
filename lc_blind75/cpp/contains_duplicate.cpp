#include "common.h"

int sz = 4;

bool contains_duplicate(const std::vector<int> &l)
{
    std::unordered_set<int> hash;
    for (auto ele : l)
    {
        if (hash.find(ele) != hash.end())
            return true;
        hash.insert(ele);
    }
    return false;
}

bool contains_duplicate_using_sorting(std::vector<int> &l)
{
    std::sort(l.begin(), l.end());
    int i = 0, j = 1;
    while (j < l.size())
    {
        if (l[i] == l[j])
        {
            return true;
        }
        else
        {
            i++;
            j++;
        }
    }

    return false;
}

void test_using_hash_set_sorting()
{
    {
        std::vector l = {1, 2, 3, 4};
        std::cout << contains_duplicate_using_sorting(l);
    }

    {
        std::vector l = {1, 2, 3, 1};
        std::cout << contains_duplicate_using_sorting(l);
    }

    {
        std::vector l = {1, 1, 2, 3};
        std::cout << contains_duplicate_using_sorting(l);
    }

    {
        std::vector l = {1, 2, 3, 5};
        std::cout << contains_duplicate_using_sorting(l);
    }
}

void test_using_hash_set()
{
    {
        std::vector l = {1, 2, 3, 4};
        std::cout << contains_duplicate(l);
    }

    {
        std::vector l = {1, 2, 3, 1};
        std::cout << contains_duplicate(l);
    }

    {
        std::vector l = {1, 1, 2, 3};
        std::cout << contains_duplicate(l);
    }

    {
        std::vector l = {1, 2, 3, 5};
        std::cout << contains_duplicate(l);
    }
}

int main(void)
{
    test_using_hash_set();
    std::cout << "\n";
    test_using_hash_set_sorting();
    return 0;
}