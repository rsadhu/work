#include <iostream>
#include <memory>
#include <string>
#include <vector>

struct Human
{
    Human(std::string name)
        : name_(name)
    {
    }
    std::shared_ptr<Human> father_;
    std::vector<Human> children_;
    std::string name_;
};
enum class HumanType
{
    FATHER,
    SON
};

class FamilyTree
{
public:
    FamilyTree();
    void addHuman(std::string name, HumanType type);
    void searchChildrenFor(std::string name);

private:
    std::shared_ptr<Human> root_;
};

void FamilyTree::addHuman(std::string name, HumanType type)
{
    if (root_)
    {
        root_ = std::make_shared<Human>(name);
        root_->children_.resize(2);
    }
    else
    {
    }
}

int main(void)
{

    FamilyTree ft;
    ft.addHuman("JawaharLalSadhu", HumanType::SON);
    ft.searchChildrenFor("JawaharLalSadhu");
    return 0;
}