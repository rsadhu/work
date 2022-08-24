#include <iostream>
#include <string>
#include <vector>
#include <sstream>

template <typename T>
T fun(T v)
{
    std::cout << " implementation called\n";
    return v;
}

template <typename T, typename... Args>
T fun(T first, Args... rest)
{
    std::cout << " fun called\n";
    return first + fun(rest...);
}

template <typename T>
std::string to_string_impl(const T &v)
{
    std::stringstream ss;
    ss << v;
    return ss.str();
}

template <typename... Args>
std::vector<std::string> to_string(Args... rest)
{
    return {to_string_impl(rest)...};
}

int main(void)
{
    std::cout << fun(1, 2, 3, 4, 5, 6, 7);
    auto ret = to_string(1, 'a', 1111.111f, 121.000, "rakesh");

    for (auto it : ret)
    {
        std::cout << it << "  ";
    }

    return 0;
}
