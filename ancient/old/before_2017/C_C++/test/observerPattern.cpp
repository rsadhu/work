#include <iostream>

class Observer;
class Subject()
{
   int val;
   std::vector<Observer *> mSubscribers;

public:
   void subscribe(Subject *);
   void unsubsribe(Subject *);
   void setVal()
   {
      val = 9;
   }

private:
   void notify();
}

class Observer
{
   Subject *mPriv;

public:
   Observer()
   {
      mPriv = new Subject();
   }

   virtual void update() = 0;
};

class Obs1 : public Observer
{
public:
   Obs1()
   {
      attach(this);
   }
   void update()
   {
      std::cout << " Obs1:: update\n";
   }
};

class Obs2 : public Observer
{
public:
   void update()
   {
      std::cout << " Obs2:: update\n";
   }
};
