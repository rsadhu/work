#include <fstream>
#include <iostream>
#include <set>
#include <vector>

int main(void)
{
    std::ifstream f("README.md");
    if (f.is_open()) {
        std::string line, data;
        while (getline(f, line)) {
            data += line;
        }

        std::cout << data;
    } else {
        std::cout << " couldnt open the file";
    }
    return 0;
}
