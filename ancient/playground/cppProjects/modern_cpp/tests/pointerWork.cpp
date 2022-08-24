#include <iostream>

template <typename T>
class Test
{
public:
  void init();

private:
  T *m_arr = nullptr;
};

template <typename T>
void Test<T>::init()
{

  m_arr = new T[100];

  for (int i = 0; i < 100; i++)
  {
    m_arr[i] = i + 1;
  }

  for (int i = 0; i < 100; i++)
  {
    std::cout << m_arr[i] << "  ";
  }

  auto tmp = m_arr;

  m_arr = new T[200];

  std::cout << "\n\n";

  std::copy(tmp, tmp + 99, m_arr);
  for (int i = 100; i < 200; i++)
  {
    m_arr[i] = i + 1;
  }

  for (int i = 0; i < 200; i++)
  {
    std::cout << m_arr[i] << "  ";
  }

  delete[] m_arr;
  delete[] tmp;
}

int main(void)
{
  int *p = new int[100]();

  for (int i = 0; i < 100; i++)
  {
    p[i] = i + 1;
  }

  for (int i = 0; i < 100; i++)
  {
    std::cout << p[i] << "  ";
  }

  auto tmp = p;

  p = new int[200];

  std::cout << "\n\n";

  std::copy(tmp, tmp + 99, p);
  for (int i = 100; i < 200; i++)
  {
    p[i] = i + 1;
  }

  for (int i = 0; i < 200; i++)
  {
    std::cout << p[i] << "  ";
  }

  delete[] p;
  delete[] tmp;

  std::cout << "\n\n";

  Test<int> t;
  t.init();

  std::cout << "\n\n";

  return 0;
}
