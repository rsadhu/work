#include <iostream>
#include <map>
#include <vector>

void group_anagrams_method1(std::vector<std::string> &input, std::vector<std::vector<std::string>> &output)
{
    std::map<std::vector<int>, std::vector<std::string>> lookup;

    for (auto each_str : input)
    {
        std::vector<int> lu(26, 0);
        for (auto ch : each_str)
        {
            lu[ch - 'a'] = +1;
        }
        auto &val = lookup[lu];
        val.push_back(each_str);
    }
    for (auto &[key, str_list] : lookup)
    {
        output.push_back(str_list);
    }
}

void group_anagrams_method2(std::vector<std::string> &list, std::vector<std::vector<std::string>> &output)
{
    std::unordered_map<std::string, std::vector<std::string>> lookup;
    for (auto str : list)
    {
        std::string item = str;
        std::sort(str.begin(), str.end());
        lookup[str].push_back(item);
    }

    for (auto &[key, value] : lookup)
    {
        output.push_back(value);
    }
}

int main(void)
{
    std::vector<std::string> input = {"tea", "ate", "eat", "ant", "tan", "nate", "nada", "dana", "enat"};
    std::vector<std::vector<std::string>> output;

    group_anagrams_method1(input, output);

    for (auto list : output)
    {
        for (auto str : list)
        {
            std::cout << str << " ";
        }
        std::cout << "\n";
    }

    output.clear();
    std::cout << "#######################\n";

    group_anagrams_method2(input, output);

    for (auto list : output)
    {
        for (auto str : list)
        {
            std::cout << str << " ";
        }
        std::cout << "\n";
    }

    return 0;
}