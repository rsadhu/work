#include <iostream>
#include <fstream>
#include <sstream>

void read_file()
{
    //std::fstream f("test.txt", std::ios::in); // read works
    std::ifstream f("test.txt");

    std::string s_data;
    //while(std::getline(f, s_data))
    while(f >> s_data);
    {
        std::cout<<s_data;
    }
}

int main(void)
{
    read_file();
    return 0;
}