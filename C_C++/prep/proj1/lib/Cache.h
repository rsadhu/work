#ifndef __CACHE__H
#define __CACHE__H
#include"global.h"
template<typename T>
class Node
{
	public:
	Node(T *data):m_data(data),left(NULL),right(NULL){}
	T *m_data;
	Node *left,*right;
};

template<typename T>
class Cache
{
	 public:
	 Cache():m_root(NULL){}
	 void readAll(FILE *fp);	 
	 void insert(T *d);
	 void remove(T *d);
	 T  *search(T *);
	 void display();
	 private:
	 void inOrder(Node<T>*tra)
	 {
		if(tra)
		{
			 inOrder(tra->left);
			 cout<<tra->m_data->name();
			 cout<<"  "<<tra->m_data->mobile()<<"\n";
			 inOrder(tra->right);
		}	  
	 }
	 Node<T> *m_root;
};

template<typename T>
void Cache<T>::readAll(FILE *fp)
{
	if(!fp) return;
	fseek(fp,0,SEEK_SET);
	Contact *c ;
	char name[25],mob[25];	
    memset(&name,0,25);
    memset(&mob,0,25);   
	while(feof(fp)==0)
	{
           if(fscanf(fp,"%s%s",name,mob)<=0)
               continue;
           c = new Contact(name,mob);
           insert(c);
    }
}


template<typename T>
void Cache<T>::insert(T *d)
{
    if(!m_root)
    {
		m_root =  new Node<T>(d);          
    }
	else
	{
	    int key = atoi(d->mobile());
		int tKey;
		Node<T> *tra = m_root;
		int f=0;
		while(tra)
		{
			tKey = atoi(tra->m_data->mobile());
			if(key >tKey)
			{
			    if(tra->right)
					tra = tra->right;
				else{
					f=1;
					break;				
				}
			}
			else if(key < tKey)
			{
				if(tra->left)
					tra = tra->left;
				else
					break;					
			}
            else{
                f =3;
                break;			
            }
		}
		if(0==f)		
			tra->left  = new Node<T>(d);		
		if(1==f)	
			tra->right = new Node<T>(d);		 
	}
}

template<typename T>
void Cache<T>::remove(T *d)
{

}

template<typename T>
T *Cache<T>::search(T *d)
{

}

template<typename T>
void Cache<T>::display()
{
    cout<<" \nCache ::display\n";
    inOrder(m_root);	 
}
#endif //CACHE
