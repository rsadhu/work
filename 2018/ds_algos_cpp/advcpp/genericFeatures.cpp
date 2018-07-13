#include<typeinfo>
#include<iostream>


using RType =  class Test
{
     public:
     void display() const{std::cout<<"Test::display\n";}
};



void
lambas ()
{
  auto callableObj =[](auto arg) {
    return arg;
  };

  std::cout << "\n" << callableObj ("rakesh");
  std::cout << "\n" << callableObj (1);
  std::cout << "\n" << callableObj (0.9f);

  auto feedMe =[](){
    return 10;
  };

  int x = 0;
  auto lambaCapVar =[x=10] (auto arg) mutable {
    x++;
    return x * arg;
  };


  for (auto i = 1; i <= 10; i++)
    std::cout << "\n" << lambaCapVar (9);
}

template<typename T=int>
void foo(T arg)
{
    decltype(arg)  xx=arg;
    std::cout<< sizeof(T);
    std::cout<< "\n Foo:: arg :: "<<arg<<"\n"<<xx<<"\n";
}

int
main (int argc, char *argv[])
{
  lambas ();
  RType t;
  t.display();
  foo(9.0f);
  try{
  std::cout<<"typeof :: "<<typeid(t).name();
  }catch(std::exception &ex)
  {
      std::cout<<" Exception::\n";
  }
  return 0;
}
