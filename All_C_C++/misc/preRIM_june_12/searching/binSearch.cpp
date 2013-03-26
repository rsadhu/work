/* CODE TO SEARCH A NUMBER PROVIDED AS COMMAND LINE  
 * ARGUMENT USING RECURSUVE BINARY SEARCH ALGORITHM
 * 
 */

#include<stdio.h>
#include<stdlib.h>


class BSA
{
	public:
	BSA():m_index(0){}
	BSA &operator<(int d) {printf("\n %d \n",m_index); m_arr[m_index]=d;++m_index; return *this;}
	int binaryS(int n){ return binarySearch(0,m_index-1,n);}
	private:
	int binarySearch(int lb,int ub,int );
	int m_arr[10];
	int m_index;
};

int BSA::binarySearch( int lb,int ub,int num)
{
	if(lb > ub)
		return 0;

	int mid  = (lb+ub)/2;

	if(num > m_arr[mid])
		lb = mid+1;
	else if(num < m_arr[mid])
		ub = mid-1;
	else
		return 1;
	binarySearch(lb,ub,num);
}



int main(int argc, char *argv[])
{
	BSA b;
	b<1<2<3<4<5<6<7<8<9;
	int n = -99;
	if(argc==2)
	n=atoi(argv[1]);
	printf("\n Binary Searching %d and is %d \n",n,b.binaryS(n));
	return 0;
}
