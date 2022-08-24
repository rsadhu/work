//
// Created by RSadhu on 01.07.20.
//

#ifndef SOFTWARE_PROGRAMMING_MAP_H
#define SOFTWARE_PROGRAMMING_MAP_H

struct Node
{
  Node(int k, int v) : key(k), value(v), left(nullptr), right(nullptr) {}
  Node *left, *right;
  int key;
  int value;
};

class Map
{
public:
  Map &operator[](int key);
  void insert(int key, int value);

private:
  Node *m_root = nullptr;
};

#endif // SOFTWARE_PROGRAMMING_MAP_H
