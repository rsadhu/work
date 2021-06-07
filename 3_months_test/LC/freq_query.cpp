#include <sstream>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>

using namespace std;


std::map<int, long int> ds;
vector<int> freqQuery(vector<vector<int>> queries) {

    std::vector<int> res;
   
    for (auto query : queries)
    {
        switch(query[0])
        {
            case 1:
            {
                 ds[query[1]]++;   
            }
            break;
            case 2:
            {
                if (ds.find(query[1])==ds.end())
                    ds[query[1]]--;
            }
            break;
            case 3:
            {
                bool f= false;
                for(auto &[key, val]: ds)
                {
                    if (val >= query[1]) {
                        res.push_back(1);
                        f = true;
                        break;
                    }
                }
                    
                if (!f)
                {
                    res.push_back(0);
                }
            }
            break;
        }
    }
    return res;
}

int main()
{
    

    std::ifstream infile("input.txt");
    int a, b;
    std::vector<std::vector<int>> queries;
    std::string line;
    while (std::getline(infile, line))
    {
         std::istringstream is( line );
         queries.push_back( 
            std::vector<int>( std::istream_iterator<int>(is),
                              std::istream_iterator<int>() ) );
    }
    
    vector<int> ans = freqQuery(queries);

    return 0;
}

