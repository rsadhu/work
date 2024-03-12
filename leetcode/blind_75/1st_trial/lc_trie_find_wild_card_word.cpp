#include <map>
#include <iostream>

struct Node
{
    std::map<char, Node *>
        children;
    bool ended = false;
};

class Trie
{
    Node *_root = nullptr;

public:
    Trie()
    {
        _root = new Node();
    }
    void add(const std::string &word)
    {
        auto cur = _root;
        for (auto it : word)
        {
            if (cur->children.find(it) == cur->children.end())
            {
                cur->children[it] = new Node();
            }
            cur = cur->children[it];
        }

        cur->ended = true;
    }

    int find(const std::string &str)
    {

        std::function<bool(int, Node *)> dfs;

        dfs = [&](int index, Node *cur)
        {
            for (int i = index; i < str.length(); i++)
            {
                char ch = str[i];
                if (ch == '.' or ch == '*')
                {
                    for (auto &[key, value] : cur->children)
                    {
                        if (dfs(i, value))
                            return 1;
                    }
                }
                else
                {
                    if (cur->children.find(ch) == cur->children.end())
                    {
                        return 0;
                    }
                    cur = cur->children[ch];
                }
            }
            return cur->ended ? 1 : 0;
        };
        return dfs(0, _root);
    }
};

int main(void)
{
    Trie t;
    t.add("sad");
    t.add("dad");
    t.add("mad");
    t.add("pad");
    std::cout << t.find("bad") << "\n";
    std::cout << t.find("b.") << "\n";
    std::cout << t.find("p..") << "\n";
    return 0;
}