#include <iostream>
#include <vector>

struct Trees
{
    explicit Trees(int d) : data(d)
    {
    }

    int data;
    std::vector<Trees> children;
};

static int cnt = 1;
void display(Trees &trees)
{
    std::cout << cnt++ << "." << trees.data << "  ";
    for (int i = 0; i < trees.children.size(); i++)
    {
        display(trees.children[i]);
    }
}

int main(void)
{
    Trees trees(10);
    int n = 2;
    // trees.children.resize(n);
    for (int i = 0; i < n; i++)
    {
        trees.children.push_back(Trees(i * i));
        //  trees.children[i].children.resize(n);

        for (int j = n; j < n + n; j++)
        {
            trees.children[i].children.push_back(Trees(j * j));
        }
    }

    display(trees);

    return 0;
}
