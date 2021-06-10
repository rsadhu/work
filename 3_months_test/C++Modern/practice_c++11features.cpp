#include <initializer_list>
#include <iostream>
#include <map>
#include <memory>
#include <vector>

// c++11 features.

void print(int&& rvr)
{
    std::cout << " print:: rvalue ref " << rvr << "\n";
}

void print(int& lvr)
{
    std::cout << " print:: lvalue ref " << lvr << "\n";
}

// uniform initialization

class Animal {
public:
    std::string m_kind;

    Animal()
    {
        m_kind = "human";
    }
    Animal(std::string kind)
        : m_kind(kind)
    {
    }

    ~Animal()
    {
        std::cout << "~Animal " << this << "\n";
    }

    Animal(const Animal& rhs)
    {
        std::cout << "\n COPY Constructor\n";
    }

    Animal& operator=(const Animal& rhs)
    {
        std::cout << "\n COPY assignment\n";
        return *this;
    }

    Animal(Animal&& rhs)
    {
        std::cout << " MOVE Constructor " << &rhs << "   " << this << "\n";
    }

    //  Animal(int age):m_age(age)
    //  {
    //      std::cout<<"Regular constructor with para\n";
    //  }

    //  Animal(std::initializer_list<int> rhs) noexcept
    //  {
    //      std::cout<<" Initializer_List called\n";
    //      for(auto it: rhs){
    //         m_age =  it;
    //         break;
    //      }
    //  }

    void display()
    {
        std::cout << "what animal i am " << m_kind << "\n";
    }
};

Animal createAnimal()
{
    Animal a;
    return a;
}

void foo(Animal rhs)
{
    std::cout << " foo :: do something \n";
}

//perfecting forwarding

//std::forward for perfect forwarding
//std::move to make an arg an r value ref
template <typename T>
void relay(T&& arg)
{
    foo(std::forward<T>(arg));
}

// literal overloading
long double operator"" _cm(long double x) { return x; }
long double operator"" _m(long double x) { return x * 100; }
long double operator"" _mm(long double x) { return x * 0.1; }
long double operator"" _km(long double x) { return x * 1000 * 10; }

template <typename T>
class SharedPtr {
    static int s_ref;

public:
    // SharedPtr(T *arg=nullptr)
    // {

    // }

    SharedPtr()
    {
        if (s_ref == 0)
            m_data = new T();

        s_ref++;
    }

    ~SharedPtr()
    {
        if (s_ref == 0)
            delete m_data;
    }

    T& operator*()
    {
        return *m_data;
    }

    T* operator->()
    {
        return m_data;
    }

    T* m_data;
};

template <typename T>
int SharedPtr<T>::s_ref = 0;

// template<typename T>
// class Packs
// {
//     public:
//         Packs(std::initializer_list<T> rhs)
//         {
//             // *m_list = new std::vector<T>(rhs.size());
//             for(auto &it: rhs)
//             {
//                 m_list.push_back(it);
//             }
//         }

//         class Iterator
//         {
//             public:

//             Iterator(T *arg)
//             {
//                 m_data = arg;
//             }

//             Iterator & operator ++ (int p )
//             {
//                 m_data++;
//                 return  *this;
//             }

//             Iterator & operator ++ ( )
//             {
//                 auto tmp = m_data;
//                 return  Iterator(m_data++);
//             }

//             Iterator & operator -> () { return m_data;}
//             Iterator  operator * () { return *m_data;}

//             bool friend operator ==(Iterator &lhs , Iterator &rhs) const
//             {
//                 return lhs == rhs;
//             }
//             private:
//             T *m_data;

//         };

//         Iterator begin() { return Iterator(&m_list[0]);}
//         Iterator end(){ return Iterator(&m_list[m_list.size()-1]);}

//         std::vector<T> m_list;
// };

std::vector<int> twoSum(std::vector<int> nums, int target)
{

    std::map<int, int> lookup;
    std::vector<int> res;

    for (size_t i = 0; i < nums.size(); i++) {
        lookup[nums[i]] = i;
    }

    for (int i = 0; i < nums.size(); i++) {
        if (lookup.find(target - nums[i]) != lookup.end()) {
            res = { i, lookup[target - nums[i]] };
            break;
        }
    }

    return res;
}

int main(void)
{

    int x = 10;
    print(10);
    print(std::move(x));
    print(x);

    Animal A; //{ 34 };
    relay(createAnimal());
    relay(A);

    std::cout << " 5 km is how many cms " << 5.0_km << "\n";
    std::cout << " 5 ms is how many cms " << 5.0_m << "\n";
    std::cout << " 5 mm is how many cms " << 5.0_mm << "\n";

    SharedPtr<Animal> sp;
    sp->display();
    (*sp).display();

    std::shared_ptr<Animal> cpp_sp = std::shared_ptr<Animal>(new Animal(), [](Animal* p) {
        std::cout << " custom Deleter " << p << "\n";
        delete p;
    });

    std::shared_ptr<Animal> cpp_sp1(new Animal(), [](Animal* p) {
        std::cout << " custom Deleter " << p << "\n";
        delete p;
    });

    //     Packs<Animal> animals_pack = {
    //         Animal("Dog"),
    //         Animal("horse"),
    //         Animal("Cow")
    //         };

    // for (auto it : animals_pack)
    // {
    //     it->display();
    // }
    // Packs<Animal> animals_pack = {
    //         "Dog",
    //         "horse",
    //         "Cow"
    //         };

    //std::unique_ptr<int> aa(new int() , [](int *p ) { delete p;} );

    auto r = twoSum({ 3, 2, 4 }, 6);

    return 0;
}
