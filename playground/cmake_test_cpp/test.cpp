//#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// string ltrim(const string &);
// string rtrim(const string &);

/*
 * Complete the 'validateAddresses' function below.
 *
 * The function is expected to return a STRING_ARRAY.
 * The function accepts STRING_ARRAY addresses as parameter.
 */

vector<string> split(string s, string delimiter)
{
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    string token;
    vector<string> res;

    while ((pos_end = s.find(delimiter, pos_start)) !=

           string::npos)
    {
        token = s.substr(pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back(token);
    }

    res.push_back(s.substr(pos_start));
    return res;
}

bool checkIfIpv4(std::string ip)
{
    auto list = split(ip, ".");
    std::cout << "SIZE of list is " << list.size() << "\n";
    if (list.size() != 4)
        return false;

    return true;
}

bool checkIfIpv6(std::string ip)
{
    auto list = split(ip, ".");
    std::cout << "SIZE of list is " << list.size() << "\n";
    if (list.size() != 6)
        return false;

    return true;
}

vector<string> validateAddresses(vector<string> addresses)
{
    std::vector<std::string> res;

    for (auto ip : addresses)
    {
        if (ip.find(":") != std::string::npos)
        {
            res.push_back("IPV6");
        }
        else if (ip.find(".") != std::string::npos)
        {
            res.push_back("IPV4");
        }
        else
        {
            res.push_back("Neither");
        }
    }
    return res;
}

int main()
{
    auto t = validateAddresses({"1.2.3.4", ".1.2.3.34.4", "1.2.3.4"});
    auto u = validateAddresses({"1:1:1:!:!:", ":1.1:", "1:1:1:1:1:1"});
    return 0;
}

// {
//     ofstream fout(getenv("OUTPUT_PATH"));

//     string addresses_count_temp;
//     getline(cin, addresses_count_temp);

//     int addresses_count = stoi(ltrim(rtrim(addresses_count_temp)));

//     vector<string> addresses(addresses_count);

//     for (int i = 0; i < addresses_count; i++) {
//         string addresses_item;
//         getline(cin, addresses_item);

//         addresses[i] = addresses_item;
//     }

//     vector<string> result = validateAddresses(addresses);

//     for (size_t i = 0; i < result.size(); i++) {
//         fout << result[i];

//         if (i != result.size() - 1) {
//             fout << "\n";
//         }
//     }

//     fout << "\n";

//     fout.close();

//     return 0;
// }

// string ltrim(const string &str) {
//     string s(str);

//     s.erase(
//         s.begin(),
//         find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
//     );

//     return s;
// }

// string rtrim(const string &str) {
//     string s(str);

//     s.erase(
//         find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
//         s.end()
//     );

//     return s;
// }
