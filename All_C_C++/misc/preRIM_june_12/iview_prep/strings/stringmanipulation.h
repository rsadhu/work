#ifndef __DER__
#define __DER__
#include"stringmanipulation_p.h"


class DerString:public String
{
public:
  DerString ():String (this )
  {
    cout << " DerString :: DerString\n";
  }
  void display () const
  {
    cout << " DerString :: display \n";
  }
  virtual ~ DerString ()
  {
    cout << "DerString :: ~DerString \n";
  }
private:
  int p;
  friend class String;
};

#endif//
