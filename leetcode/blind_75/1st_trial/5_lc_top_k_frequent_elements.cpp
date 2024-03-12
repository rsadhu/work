#include <iostream>
#include <vector>
#include <map>

std::vector<int> top_k_frequent_elements_method1(std::vector<int> input, int k)
{
    std::vector<int> output;
    std::map<int, int> res;
    std::map<int, int, std::greater<int>> lu;
    for (auto ele : input)
    {
        res[ele]++;
    }

    for (auto &[key, value] : res)
    {
        lu[value] = key;
    }
    int i = 0;
    for (auto &[key, value] : lu)
    {
        if (i++ >= k)
            break;
        output.push_back(key);
    }
    return output;
}

void test1()
{
    std::vector<int> input = {1};
    int k = 1;

    auto res = top_k_frequent_elements_method1(input, k);

    for (auto ele : res)
    {
        std::cout << ele << " ";
    }
}

void test2()
{
    std::vector<int> input = {1, 1, 1, 2, 2, 3};
    int k = 2;

    auto res = top_k_frequent_elements_method1(input, k);

    for (auto ele : res)
    {
        std::cout << ele << " ";
    }
}

int main(int argc, char *argv[])
{
    std::cout << "\n";
    test1();
    std::cout << "\n";
    test2();
    std::cout << "\n";
    return 0;
}