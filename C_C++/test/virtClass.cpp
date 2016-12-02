#include<iostream>


class Def
{
public:
  virtual ~ Def ()
  {
    std::cout << "Der::~Def\n";
  }
  Def ()
  {
    std::cout << "\nDef::Def\n";
  }
  virtual void foo ()
  {
    std::cout << "\nDef::foo\n";
  }

  bool operator < (const Def & rhs)
  {
    bool ret (true);
    return ret;
  }

private:
  int mVal = 0;
};

class Der:public Def
{
public:
  Der ()
  {
    std::cout << "\nDer::Der\n";
  }
  void foo ()
  {
    std::cout << "\nDer::foo\n";
  }
  ~Der ()
  {
    std::cout << "Der::~Der\n";
  }
};

int
main (void)
{
  Def *df = new Der ();
  df->foo ();
  delete df;
  return 0;
}
