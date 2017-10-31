// CPP11.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include"_template.h"

#define N 10

void sepPosNeg()
{
	int *arr = new int[N]{1,2,3,-9,7,-5,4,22,0,-99};
	for (int i = 0; i < N;i++)
	{
		std::cout << arr[i] << " ";
	}	

	delete[]arr;

	for (int i = 0,j=N-1; i < j;)
	{

	}
}

std::mutex mu;
std::condition_variable cv;
std::vector<int > gvec = {1,2,3,4,5,6};
bool g_ready = false;

void threadFunc1()
{
	std::unique_lock<std::mutex> locker(mu);
	//while ()

}




void threadFunc2()
{

}

template<typename MyType>
class Util
{
	public:
		Util(MyType &obj);

		void setData()const;
	private:
		mutable MyType *mData=nullptr;
};

class MutableConst
{
	mutable int mA = 0;
	int mB = 9;
public:
	MutableConst(){}
	//virtual ~MutableConst() = 0;
	void setInt(const int val) const
	{
		mA = val;
		//mB = val;
		//val *= 10;
	}

	void setAnotherInt(int &val) const
	{
		//mB = val;
		val *= 10;
	}


};
class P
{

};

class C :public P
{

};


class T
{

};

bool isDerivedFrom(P *par, C *child)
{
	if (dynamic_cast<P*>(child))
		return true;
	return false;
}




int _tmain(int argc, _TCHAR* argv[])
{
	/*P par;
	C child;
	T tmp;

	cout << isDerivedFrom(&par, &child);*/

	/*std::thread t1(threadFunc1);
	std::thread t2(threadFunc2);*/
/*	MutableConst m;
	int a = 9;
	m.setAnotherInt(a);
	m.setInt(a);

	MutableConst  const cm;
	cm.setInt(a);
	cm.setAnotherInt(a);*/	

	//int myints[] = { 10, 20, 30, 5, 15 };
	//std::vector<int> v(myints, myints + 5);

	//std::make_heap(v.begin(), v.end());
	//std::cout << "initial max heap   : " << v.front() << '\n';

	//std::pop_heap(v.begin(), v.end());
	//v.pop_back();
	//std::cout << "max heap after pop : " << v.front() << '\n';

	//v.push_back(99);
	//std::push_heap(v.begin(), v.end());
	//std::cout << "max heap after push: " << v.front() << '\n';

	//std::sort_heap(v.begin(), v.end());

	//std::cout << "final sorted range :";
	//for (unsigned i = 0; i<v.size(); i++)
	//	std::cout << ' ' << v[i];

	//std::cout << '\n';



	return 0;
}

