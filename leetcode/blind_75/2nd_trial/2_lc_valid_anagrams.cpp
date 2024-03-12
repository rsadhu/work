#include <iostream>
#include <set>
#include <vector>
#include <chrono>

bool validAnagram(std::string &s1, std::string &s2)
{
    std::sort(s1.begin(), s1.end());
    std::sort(s2.begin(), s2.end());
    return s1 == s2;
}

bool validAnagram_better(std::string &s1, std::string &s2)
{
    std::set<char> lu;
    for (auto it : s1)
    {
        lu.insert(it);
    }

    for (auto it : s2)
    {
        if (lu.find(it) == lu.end())
            return false;
    }

    return true;
}

int main(void)
{
    std::string s1, s2;
    auto begin = std::chrono::system_clock::now();

    s1 = "anagram";
    s2 = "nagaram";

    std::cout << validAnagram(s1, s2) << "\n";

    s1 = "rasahsjahsjahjshjhjshdjshdjshdjshjdhsjkkqlllt";
    s2 = "cawsauyusdjshdhjshdjsghdjshdjshjhdjshjhjhjhjr";

    std::cout << validAnagram(s1, s2) << "\n";

    auto end = std::chrono::system_clock::now();

    std::cout << "1>> time spent is " << (std::chrono::duration_cast<std::chrono::microseconds>(end - begin)).count();

    begin = std::chrono::system_clock::now();

    s1 = "anagram";
    s2 = "nagaram";

    std::cout << validAnagram_better(s1, s2) << "\n";

    s1 = "rujshdjshjdshjdhsat";
    s2 = "cardsdjksjdksjdksjd";

    std::cout << validAnagram_better(s1, s2) << "\n";

    end = std::chrono::system_clock::now();

    std::cout << "1>> time spent is " << (std::chrono::duration_cast<std::chrono::microseconds>(end - begin)).count();

    return 0;
}