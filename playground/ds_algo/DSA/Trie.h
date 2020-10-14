#ifndef TRIE_H
#define TRIE_H
#define CHAR_TO_INDEX (c)  (int)(c - 'a') ;
#define MAX_CHAR 26
struct Node
{
  Node  *children[MAX_CHAR];
  bool isFinal=false;
};


class Trie
{
 public:
    Trie();
    bool insert(char );
    void find(char c, std::string &res);
 private:
 Node m_root;
};

Trie::Trie()
{
    for(int i=0;i<MAX_CHAR;i++)
    {
        m_root.children[i]=nullptr;
    }
    m_root.isFinal=false;
}

bool Trie::insert(char c)
{
 bool ret(false);

 auto index  = CHAR_TO_INDEX(c);
 if( !m_root.children[index] )
 {
   m_root.children[index]= new Node();
 }
  m_root.isFinal =  true;
 return ret;
}


void Trie::find(char c, std::string &res)
{

}

#endif // TRIE_H
