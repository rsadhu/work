#include <unordered_map>
#include <string>
#include <memory>
#include <iostream>

struct Node
{
    bool _is_end = false;
    std::unordered_map<char, std::shared_ptr<Node>> children;
};

class Trie
{
    std::shared_ptr<Node> _root;

public:
    Trie()
    {
        _root = std::make_shared<Node>();
    }
    void insert(const std::string &word);
    bool search(const std::string &word);
};

void Trie::insert(const std::string &word)
{
    auto node = _root;
    for (auto ch : word)
    {
        if (node->children.count(ch) == 0)
        {
            node->children[ch] = std::make_shared<Node>();
        }
        node = node->children[ch];
    }
    node->_is_end = true;
}

bool Trie::search(const std::string &word)
{
    auto node = _root;
    for (auto ch : word)
    {
        if (node->children.count(ch) == 0)
        {
            return false;
        }
        else
        {
            node = node->children[ch];
        }
    }
    return node->_is_end;
}

int main(int argc, char *argv[])
{
    Trie t;
    t.insert("mummy");
    t.insert("daddy");
    t.insert("rakesh");
    t.insert("valya");
    t.insert("bhaiya");
    t.insert("didi");
    t.insert("aryan");
    t.insert("lavu");
    t.insert("leo");
    t.insert("amitji");
    t.insert("mona");

    t.insert("rajesh");
    t.insert("rak");
    t.insert("babloo");
    t.insert("bablal");
    t.insert("hasan");

    for (int i = 1; i < argc; i++)
    {
        if (t.search(argv[i]))
        {
            std::cout << argv[i] << " is found\n";
        }
        else
        {
            std::cout << argv[i] << " is not found\n";
        }
    }

    return 0;
}