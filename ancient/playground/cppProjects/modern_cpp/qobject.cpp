#include <iostream>
#include <vector>

template <typename T>
class QObject
{
public:
  QObject(T *child)
  {
    std::cout << "\nQObject::QObject    " << child << "\n";
    if (child)
      mChildren.push_back(child);
  }

private:
  std::vector<T *> mChildren;
};

class MyObject : public QObject<MyObject>
{
public:
  MyObject() : QObject(this)
  {
    std::cout << "\nMyObject::MyObject\n";
  }
};

class Der : public QObject<Der>
{
public:
  Der() : QObject(this) {}

  friend class QObjct;
};

int main(void)
{
  MyObject obj;
  return 0;
}
