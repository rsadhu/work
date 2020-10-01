//
// Created by rsadhu on 01.10.20.
//

#include "leetcode_headers.h"

int main(void) {
  std::map<char, int> lup;
  for (char ch = 'a'; ch <= 'z'; ch++)
    lup[ch] = ch - 'a';

  auto lit = lup.lower_bound('b');

  auto lit1 = lup.upper_bound('b');

  auto lit2 = lup.lower_bound('z');

  // std::cout<<ret.u<<"\n";
  //    std::cout<<ret.second->first<<"\n";

  Utility u;
  Test t = u.get();

  return 0;
}