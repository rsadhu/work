#include <unordered_set>
#include <iostream>
#include <map>

int main(void)
{
    std::unordered_set<int> uset;
    uset.insert(1);
    uset.insert(5);
    uset.insert(3);
    uset.insert(10);
    uset.insert(9);
    uset.insert(7);

    std::cout << std::endl;

    // *(uset.find(1)) = 10;

    for (auto it : uset)
    {
        std::cout << it << " ";
    }

    std::cout << std::endl;

    std::map<char, int> mymap;
    mymap.insert(std::make_pair('a', 1));
    mymap.insert(std::make_pair('z', 11));
    mymap.insert(std::make_pair('d', 7));
    mymap.insert(std::make_pair('c', 8));
    mymap.insert(std::make_pair('g', 12));
    mymap.insert(std::make_pair('f', 78));
    mymap.insert(std::make_pair('a', 0));

    std::cout << std::endl;

    for (auto it : mymap)
    {
        std::cout << it.first << " " << it.second << "\n";
    }

    std::cout << std::endl;

    return 0;
}
