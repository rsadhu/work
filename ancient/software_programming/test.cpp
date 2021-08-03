#include <fstream>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

bool detectCapitalUse(std::string word) {
    auto checkAllUpper = [](auto word, int i = 1) -> bool {
        for (; i < word.length(); i++) {
            if (!std::isupper(word[i]))
                return false;
        }
        return true;
    };

    auto checkAllLower = [](auto word, int i = 1) -> bool {
        for (; i < word.length(); i++) {
            if (!std::islower(word[i]))
                return false;
        }
        return true;
    };


    if (std::isupper(word[0])) {
        int sz = word.length();
        if (sz > 1) {
            if (std::isupper(word[1])) {
                return checkAllUpper(word, 1);
            } else {
                return checkAllLower(word, 1);
            }
        } else {
            return true;
        }
    } else {
        return checkAllUpper(word);
    }
}

string reverseVowels(string s) {

    auto isVowel = [](char c) {
        if (c == 'a' || c == 'e' || c == 'o' || c == 'u' || c == 'i')
            return true;
        return false;
    };

    int i = 0, sz = s.length() - 1;
    bool limit = false;

    while (i < sz) {
        while (!isVowel(s[i])) {
            i++;
            if (i >= sz) {
                limit = true;
                break;
            }
        }
        if (limit)
            break;

        while (!isVowel(s[sz])) {
            sz--;
        }

        std::swap(s[i], s[sz]);
        i++;
        sz--;
    }

    return s;
}

#include <regex>
#include <set>

std::set<std::string> dict_ {"bad","dad","mad"};

bool search(std::string word) {
    if (word.empty())
        return true;

    if (dict_.find(word) != dict_.end()) {
        return true;
    } else {
        if (word.find('.')==std::string::npos)
            return false;
        std::string reg;
        for (auto it: word)
        {
            if (it == '.')
                reg+="[a-z]*";
            else
                reg+=it;
        }
        const std::regex reg_txt(reg);
        for (auto it : dict_) {
            auto res = std::regex_match(it, reg_txt);
            return res == 1;
        }
    }
    return false;

}

/*["WordDictionary","addWord","addWord","addWord","search","search","search","search"]
[[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]*/

int main(void) {

//    std::cout << detectCapitalUse("AssA");
    //std::cout << reverseVowels("RaTCRT");


    auto aa = search("bad");
    auto ab = search(".ad");
    auto ac = search("b..");
    auto ad = search("pad");

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
