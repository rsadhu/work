#include <iostream>
#include <type_traits.hpp>   


int main(void)
{

    int arr[10];
    sts::cout << std::is_array<arr>::value;
    return 0;
}