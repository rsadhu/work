#include <iostream>
#include <map>

using mmap = std::map<char, std::map<char, char>>;

class TrieSM
{
public:
    void operator<(char ch);
    void show();

protected:
    void reset();
    void add();

private:
    mmap mTrieDatasource;
};

int main(void)
{
    return 0;
}
