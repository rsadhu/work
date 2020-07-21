#include <iostream>
#include <string>

class Test
{
public:
  void setString (std::string & rhs)
  {

    std::cout << " setString non const " << rhs << "\n";
    m_str = rhs;
  }


  void setString (std::string & rhs) const
  {
    std::cout << " hello mello " << rhs << "\n";
  }



private:
    std::string m_str;
};

int
main (void)
{
  std::string s ("test");
  Test t;
  t.setString (s);

  const Test u;
  u.setString (s);
  return 0;
}
