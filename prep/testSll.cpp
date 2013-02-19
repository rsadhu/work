#include"sll.h"

int main(void)
{
 cout<<"use for testing integer list ";
// basic unit tests
 SLL<int > iSll;
 iSll<1<2<3<4<5<6<7<8<9;
 iSll.display();

 iSll.reverse(ITER);
 iSll.display();
 iSll.reverse(REC);
  iSll.display();
 iSll.reverse(ITER);
 iSll.display();
 iSll.reverse(REC);
 iSll.display();

 //running  Non Function tests
 for(int i=0;i<30;i++)
 {
  if(i%2==0)
  iSll.reverse(ITER);
  else 
  iSll.reverse(REC);
   iSll.display();
 }

 cout<<"\n  performing tests on char list";
 SLL<char > cSll ;
 cSll<'r'<'a'<'k'<'e'<'s'<'s'<'h';
 cSll.display();


 cSll.reverse(ITER);
cSll.display();
 cSll.reverse(REC);
cSll.display();
 cSll.reverse(ITER);
cSll.display();
 cSll.reverse(REC);
cSll.display();

 //running  Non Function tests
 for(int i=0;i<30;i++)
 {
  if(i%2==0)
  cSll.reverse(ITER);
  else 
  cSll.reverse(REC);
cSll.display();
 }
cout<<"\n";
 
 return 0;
}
