#include <vector>
#include <iostream>
using namespace std;

/*
int
getTotalX (vector < int >a, vector < int >b)
{
    int cnt = 0;

    for (auto tt = a.end (); tt !=  b.end (); tt++)
    {
        for (auto aa = a.begin (); aa != a.end (); aa++)
        {
            for (auto bb = b.begin (); (tt % aa == 0) && bb != b.end (); bb++)
            {
                if (bb % tt == 0)
                    cnt++;
            }
        }
    }
    return cnt;
}*/

/*int
getTotalX (vector < int >a, vector < int >b)
{
    int cnt=0;
    for(int n=a.at(a.size()-1);n<=b.at(0);n++)
    {

        for(int j=0;j<a.size();j++)
        {
            if( n % a.at(j) == 0)
            {
                for(int k=0; k<b.size();k++)
                {
                    if(b.at(k) % n ==0)
                    {
                        cnt++;
                    }
                    else
                    {
                        cnt==0;
                        break;
                    }
                }
            }
            else
            {
                cnt==0;
            }
        }
    }

    return cnt;
}*/

int calV()
{
    int v[] = {3, 4, 21, 36, 10, 28, 35, 5, 24, 42};
    int n = 10;
    int min = v[0], max = v[0];
    int cntMin = 0, cntMax = 0;
    for (int i = 1; i < n; i++)
    {

        if (v[i] > max)
        {
            cntMax++;
            max = v[i];
        }
        if (v[i] < min)
        {
            cntMin++;
            min = v[i];
        }
    }

    std::cout << cntMax << " " << cntMin;
}

int main(void)
{
    std::vector<int> v1 =
                         {
                             2, 4, 8, 16},

                     v2{
                         32, 64, 128, 256};

    // std::cout << getTotalX (v1, v2);
    calV();
    return 0;
}
