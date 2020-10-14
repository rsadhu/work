#include <iostream>
#include <vector>


int main(void)
{

    std::vector<int> A = {1,3, 4, 2, 2, 2, 1, 1, 2};
    int st = 0, end = A.size()-1;

    int sum = 0;

    for (auto it: A)
    {
        sum+=it;
    }

    int sum1 =0, sum2=0;

    while(st<end)
    {
        sum1+=A[st];
        sum2+=A[end];
        auto sum3 = sum - sum1- sum2;
        if (sum1 == sum2  && sum2== sum-(A[st] + A[end]))
        {
            std::cout<< "true";
            break;
        }

        st++;
        end--;
    }

    std::cout<<st<<" " <<end<<"  not true\n";

    
    return 0;
}
