#include<iostream>


int main(void)
{
 int arr[5] =  { 1, 2, 3, 4, 5 };
 std::cout<<"  arr[-1] "<<arr[-1];
 int arr1[3][5] =  { { 1, 2, 3, 4, 5  },
					 { 6, 7, 8, 9, 10 },
					 { 11, 12, 13, 14, 15}
				  };
 std::cout<<" arr1[-1][0]"<< arr1[-1][0];
 return 0;
}
