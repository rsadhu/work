#include<stdio.h>
#include<stdlib.h>


typedef struct _tree
{
  struct _tree *right, *left;
  int data;
} BST;

typedef enum
{
INORDER,
POSTORDER,
PREORDER
}Type;

BST * new(int d)
{
    BST *tmp = (BST*)malloc(sizeof(BST));
    tmp->data = d;
    tmp->left= tmp->right = NULL;    
}


void create(BST **root,int d)
{
 BST *tra= *root;
 int f=0;
 while(tra)
 {
     if(d > tra->data)
     {
        if(tra->right)
        {
            tra->right  =  new (d);
            f=1;
        }
        else
            break;
     }
     else  if( d < tra->data)
     {
            if(tra->left)
            {
                tra->left = new(d);
                f=2;
            }
            else
                break;
     }
   }
  
   if(2 == f)
       tra->left = new(d);

   if(1 == f)
       tra->right = new(d);
}

void  inOrder(BST *tra)
{
    if(tra)
    {
        inOrder(tra->left);
        printf(" %d ",tra->data);
        inOrder(tra->right);
    }
}

void display(BST *root,Type t)
{
    switch(t)
    {
        case INORDER:
            printf("\ndisplay :: ONORDER \n");
            inOrder(root);
            break;
        case POSTORDER:
            printf("\ndisplay :: POSTORDER \n");
  //          postOrder(root);
            break;
        case PREORDER:
            printf("\ndisplay :: PREORDDER \n");
    //        preOrder(root);
            break;
       default:
           printf("\ndisplay :: default \n");
        break;
    }
}



int
main (void)
{
  BST *root = new(30);

  int arr[] = { 45, 15, 18, 12, 16, 50 };
  int i,s=sizeof(arr)/sizeof(int), tmp[s];
  
  for(i=0;i<s;i++)
      create(&root,arr[i]);

  display(root,INORDER);
  return 0;
}

