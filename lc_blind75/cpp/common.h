#include <array>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

template <typename T>
std::ostream &
operator<<(std::ostream &o, std::vector<T> &r)
{
    static_assert(std::is_same_v<T, int> || std::is_same_v<T, float> || std::is_same_v<T, std::string> ||
                      std::is_same_v<T, bool>,
                  "std::cout function only supports  container's int,bool, float and std::string types");
    for (auto el : r)
    {
        o << el << " ";
    }
    return o;
}

template <typename T>
std::ostream &
operator<<(std::ostream &o, T &r)
{
    static_assert(std::is_same_v<T, int> || std::is_same_v<T, float> || std::is_same_v<T, std::string> ||
                      std::is_same_v<T, bool> || std::is_same_v<T, const char *>,
                  "std::cout function only supports int,bool, float and std::string types");

    o << r << " ";
    return o;
}
