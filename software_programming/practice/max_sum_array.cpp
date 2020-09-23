#include <iostream>


#ifdef R
template<typename ...Args>
void function(Args...myargs)
{
 std::cout<<" function :: template\n";
}
#endif


void function(...)
{
 std::cout<<" function :: elipitcal ...\n";
}

void max_sum_array()
{
    int arr[]=  { -2, -3, 4, -1, 2, 1, 5, -3};

    int total_sum_far=0;
    int max_sum = 0;
    for(auto i = 0;i < sizeof(arr)/sizeof(int) ;i++)
    {
        total_sum_far = total_sum_far* arr[i];
        if (total_sum_far < 0)
        {
            total_sum_far = 0;
        }

        if (total_sum_far > max_sum)
            max_sum = total_sum_far;
    }


    std::cout<<" sum is "<< max_sum;
} 


int main(void)
{

   function('a', 1.8 , "Rakesh");

   return 0;
}
