#include <iostream>
#include <string.h>
using namespace std;

static int pow(int base, int pow)
{
  int tmp = 1;
  while (pow-- > 0)
    tmp = tmp * base;
  return tmp;
}

static bool checkBit(int num, int bit)
{
  bool ret(false);
  num = num >> bit;
  if (num & 1 == 0)
    ret = true;
  return ret;
}

class bitString
{
  int m_bit;
  char *m_str;

public:
  explicit bitString(char *str)
  {
    m_str = strdup(str);
    memset(&m_bit, 0, sizeof(m_bit));
  }
  ~bitString()
  {
    cout << " bitString::~bitString\n";
    delete m_str;
  }

  inline char *ascii()
  {
    return m_str;
  }
  bool isUnique();

protected:
  bool bitSet();
};

bool bitString::isUnique()
{
  bool ret(false);
  ret = bitSet();
  return ret;
}

bool bitString::bitSet()
{
  int index;
  while (*m_str != '\0')
  {
    index = ((int)*m_str) - 68;

    if (checkBit(m_bit, index))
      return false;
    m_bit |= pow(2, index);
    m_str++;
  }
  return true;
}

int main(void)
{
  bitString b("helo");
  cout << " string :: " << b.ascii() << "  is unique " << b.isUnique();
  return 0;
}
