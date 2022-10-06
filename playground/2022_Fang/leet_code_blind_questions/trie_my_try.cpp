#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

class Trie
{
public:
    std::unordered_map<char, Trie *> children_;
    bool is_leaf = false;

    Trie()
    {

        char ch = 'a';

        while (ch <= 'z')
        {
            children_[ch] = nullptr;
            //    children_[ch]->is_leaf = false;
            ch++;
        }

        ch = 'A';
        while (ch <= 'Z')
        {
            children_[ch] = nullptr;
            //  children_[ch]->is_leaf = false;
            ch++;
        }
    }

    void insert(string word)
    {
        Trie *tra = this;
        for (auto it : word)
        {
            if (tra->children_[it] == nullptr)
            {
                tra->children_[it] = new Trie();
            }
            // else
            //{
            tra = tra->children_[it];
            //}
        }
        tra->is_leaf = true;
    }

    bool search(string word)
    {

        Trie *tra = this;
        for (auto ch : word)
        {
            if (tra->children_[ch] == nullptr)
                return false;
            else
            {
                tra = tra->children_[ch];
            }
        }
        return tra->is_leaf;
    }

    bool startsWith(string prefix)
    {
        Trie *tra = this;
        for (auto it : prefix)
        {
            if (tra->children_[it] == nullptr)
                return false;
            else
                tra = tra->children_[it];
        }
        return true;
    }
};

/*["Trie","insert","search","search","startsWith","insert","search"]
[[],["apple"],["apple"],["app"],["app"],["app"],["app"]]*/
int main(void)
{
    Trie t;
    t.insert("apple");
    auto r = t.search("apple");
    auto t1 = t.search("app");
    auto u = t.startsWith("app");
    t.insert("app");
    t1 = t.search("app");
}