
#include "utility.h"

bool solution_two_ptrs(const std::vector<int>& list, int target)
{
    int first = 0, last = list.size() - 1;
    while (first < last) {
        auto sum = list[first] + list[last];
        if (sum == target)
            return true;
        if (sum > target)
            last--;
        else
            first++;
    }
    return false;
}

bool solution_find_another(const std::vector<int>& list, int target)
{
    for (int i = 0; i < list.size(); i++) {
        auto iter = std::find(list.begin(), list.end(), target - list[i]);
        if (iter != list.end()) {
            if ((iter - list.begin()) != i) {
                return true;
            }
        }
    }
    return false;
}

bool solution_set_lookup(const std::vector<int>& list, int target)
{
    std::unordered_set<int> lookup;
    for (auto it : list) {
        lookup.insert(target - it);
    }

    for (auto it : list) {
        if (lookup.count(it) > 0)
            return true;
    }

    return false;
}

bool solution_brute(const std::vector<int>& list, int target)
{
    for (int i = 0; i < list.size(); i++) {
        for (int j = i + 1; j < list.size(); j++) {
            if (target == (list[i] + list[j]))
                return true;
        }
    }
    return false;
}

int main(void)
{
    std::vector<int> list;
    std::string file_with_path = "input_list_integer.txt";
    input(list, file_with_path);
    std::map<long, std::string> time_span;

    int target = 1002;
    auto start = std::chrono::steady_clock::now();
    bool ret = solution_find_another(list, target);
    auto end = std::chrono::steady_clock::now();
    time_span[(end - start).count()] = "find_tech";

    start = std::chrono::steady_clock::now();
    ret &= solution_two_ptrs(list, target);
    end = std::chrono::steady_clock::now();
    time_span[(end - start).count()] = "two pointers";

    start = std::chrono::steady_clock::now();
    ret &= solution_set_lookup(list, target);
    end = std::chrono::steady_clock::now();
    time_span[(end - start).count()] = "set lookup";

    start = std::chrono::steady_clock::now();
    ret &= solution_brute(list, target);
    end = std::chrono::steady_clock::now();
    time_span[(end - start).count()] = "brute force";

    for (auto item : time_span) {
        std::cout << item.first << "  " << item.second << "\n";
    }

    return 0;
}