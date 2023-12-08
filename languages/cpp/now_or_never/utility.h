#include <algorithm>
#include <chrono>
#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <unordered_set>
#include <vector>

void input(std::vector<int>& list, std::string file_with_path)
{
    try {
        std::ifstream ifs(file_with_path, std::ios_base::out);
        std::string str;
        if (ifs.is_open()) {
            while (ifs) {
                ifs >> str;
                if (str != "\n" || str != " ")
                    list.push_back(std::stoi(str));
            }
        }
    } catch (std::exception& e) {
        std::cout << "\nException is thrown :: " << e.what() << "\n";
    }
}