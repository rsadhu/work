// A C++ program to find the count of distinct substring
// of a string using trie data structure

#include <ctime>
#include <iostream>
#include <set>
#include <unordered_set>

#define MAX_CHAR 26
using namespace std;

// A Suffix Trie (A Trie of all suffixes) Node
class SuffixTrieNode
{
public:
    SuffixTrieNode *children[MAX_CHAR];
    SuffixTrieNode() // Constructor
    {
        // Initialize all child pointers as nullptr
        for (int i = 0; i < MAX_CHAR; i++)
            children[i] = nullptr;
    }

    // A recursive function to insert a suffix of the s
    // in subtree rooted with this node
    void insertSuffix(string suffix);
};

// A Trie of all suffixes
class SuffixTrie
{
    SuffixTrieNode *root;
    int _countNodesInTrie(SuffixTrieNode *);

public:
    // Constructor (Builds a trie of suffies of the given text)
    SuffixTrie(string s)
    {
        root = new SuffixTrieNode();

        // Consider all suffixes of given string and insert
        // them into the Suffix Trie using recursive function
        // insertSuffix() in SuffixTrieNode class
        for (int i = 0; i < s.length(); i++)
            root->insertSuffix(s.substr(i));
    }

    //  method to count total nodes in suffix trie
    int countNodesInTrie() { return _countNodesInTrie(root); }
};

// A recursive function to insert a suffix of the s in
// subtree rooted with this node
void SuffixTrieNode::insertSuffix(string s)
{
    // If string has more characters
    if (s.length() > 0)
    {
        // Find the first character and convert it
        // into 0-25 range.
        char cIndex = s.at(0) - 'a';

        // If there is no edge for this character,
        // add a new edge
        if (children[cIndex] == nullptr)
            children[cIndex] = new SuffixTrieNode();

        // Recur for next suffix
        children[cIndex]->insertSuffix(s.substr(1));
    }
}

// A recursive function to count nodes in trie
int SuffixTrie::_countNodesInTrie(SuffixTrieNode *node)
{
    // If all characters of pattern have been processed,
    if (node == nullptr)
        return 0;

    int count = 0;
    for (int i = 0; i < MAX_CHAR; i++)
    {
        // if children is not nullptr then find count
        // of all nodes in this subtrie
        if (node->children[i] != nullptr)
            count += _countNodesInTrie(node->children[i]);
    }

    // return count of nodes of subtrie and plus
    // 1 because of node's own count
    return (1 + count);
}

// Returns count of distinct substrings of str
int countDistinctSubstring(string str)
{
    // Construct a Trie of all suffixes
    SuffixTrie sTrie(str);

    // Return count of nodes in Trie of Suffixes
    return sTrie.countNodesInTrie();
}

int countDistinct(std::string str)
{
}

int countDistinct_brute(std::string str)
{
    std::set<std::string> lookup;
    int cnt = 0;
    for (int i = 0; i < str.length(); i++)
    {

        for (int j = i + 1; j < str.length(); j++)
        {
            auto sub_str = str.substr(i, j);

            lookup.insert(sub_str);

            //   std::cout<<sub_str <<"\n";
            cnt++;
        }
    }

    // std::cout << " \n number of distinct  strings are  " << lookup.size() << "\n";

    // std::cout << "\n general count of strings is " << cnt << "\n";
    return lookup.size();
}

// Driver program to test above function
int main(int argc, char *argv[])
{
    string str = "asjhjahsjahjshjdhsjhdjshdsjkjdksjdksjdksjkdsjkdsjdksjdksjkdjskdjkdjshdjshdjshjdshjababhjshjcxhjchxjoiwuqyuwqyuwya";
    if (argc == 2)
        str = argv[1];

    std::time_t start = std::time(nullptr);
    cout << "\nCount of  substrings is "
         << countDistinctSubstring(str) << "\n";

    // std::cout << "time diff:  "
    //         << std::difftime(std::time(nullptr), start) << " s.\n";

    // std::time_t start1 = std::time(nullptr);

    std::cout << "count of distinct substrings is " << countDistinct_brute(str) << "\n";

    // std::cout << "time diff1:  "
    //         << std::difftime(std::time(nullptr), start1) << " s.\n";

    return 0;
}