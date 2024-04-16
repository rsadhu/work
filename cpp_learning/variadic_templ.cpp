#include <iostream>
#include <string>
#include <vector>

struct stud
{
 std::string name;
 unsigned int id;
 float money;
 std::vector<std::string> books;

 friend std::ostream & operator <<(std::ostream &o, const stud &s)
 {
    o<<s.name<<" "<<s.id<<" "<<s.money<<" ";

	for (auto it:s.books)
	{
		o<< it << " ";
	}
    return o;
 }
};

void print()
{
	std::cout<<"\nbase case\n\n";
}

// void print(const stud &s)
// {
// 	std::cout<<s.name<<" "<<s.id<<" "<<s.money<<" ";

// 	for (auto it:s.books)
// 	{
// 		std::cout<< it << " ";
// 	}

// 	std::cout<<"\n";
// }

template<typename T, typename  ...Arg>
void print(T x, Arg ...arg)
{
	std::cout<<x<<"\n";
	print(arg...);
}


struct Test
{
	Test()
	{
        try{
		    std::cout<<"Test::Test\n";
		   // throw std::exception();
        }catch(...)
        {
            std::cout<<"\nexcpt caught\n";
        }
	}

	~Test()
	{
		std::cout<<"Test::~Test\n";
	}

};

void test_rec(int n )
{
    try{
    if (n == 3)
    {
        throw std::exception ();
    }
   Test t;
   std::cout<<n<<" ";
   test_rec(--n);
    }catch(...)
    {
        std::cout<<"exception was thrown\n";
    }
}


int main() {
	// stud s{"test sub", 111, 1000.00, {"aaa", "bbb"} };
	// print(111, "rs", 0.9f, 111, 'a', 9.9, "testing", s, 11/3);
//    Test t;
    test_rec(10);
    return 0;
}