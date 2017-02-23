#include<iostream>

class cbClass
{
 public:
    virtual void draw()=0;
};

class Base
{
public:
  Base ()
  {
    foo();
  }
  void testVir ()
  {
    foo ();
  }
  virtual ~ Base ()
  {
    std::cout << "Base::~Base\n";
  }

  virtual  void foo ();
  void display(void)
  {
    std::cout<<"Base::display\n";
  }
};

void
Base::foo ()
{
  std::cout << "Base::foo\n";
};

class Der:public Base
{
public:
  Der ()
  {

  }
  Der (cbClass *cb)
  {
    cb->draw();
  }
   ~Der ()
  {
    std::cout << "Der::~Der\n";
  }
  
  void display()
  {
    std::cout<<"Der::display\n";
  }
  protected:  
  void inline foo ()
  {
    std::cout << "Der::foo\n";
  }

};

class cbDraw: public cbClass
{
    public:
        void draw()
        {
            std::cout<<"cbDra::draw\n";
        }
};

int
main (void)
{
  /*Base *t = new Der ();
  t->foo();
  t->display();
  Der *b = dynamic_cast<Der *> (t);
  b->display();
  cbClass *p =new cbDraw();

  Der b1 (p);
  
  delete t;*/

  Der b11;
  b11.testVir();
  return 0;
}
