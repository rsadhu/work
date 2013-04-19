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
            tra= tra->right;
        else{
            tra->right = new(d);
            break;
        }
     }
     else  if( d < tra->data)
     {
         if(tra->left)
             tra = tra->left ;
         else{
             tra->left = new(d);                
             break;
         }
     }
   }
}


void createRec(BST *root,int d)
{
    if(root)
    {
        if(d > root->data){
            if(root->right)
            createRec(root->right,d);
            else
            root->right =  new (d);
        }
        else if(d < root->data){
            if(root->left)
            createRec(root->left,d);
            else
            root->left =  new (d);
        }
    }   
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

void postOrder(BST *tra)
{

}

void preOrder(BST *tra)
{

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
            postOrder(root);
            break;
        case PREORDER:
            printf("\ndisplay :: PREORDDER \n");
            preOrder(root);
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
  printf("\n 45, 15, 18, 12, 16, 50  \n");
  int i,s=sizeof(arr)/sizeof(int), tmp[s];
  
  for(i=0;i<s;i++)
     createRec(root,arr[i]);
   //       create(&root,arr[i]);

  display(root,INORDER);
  return 0;
}

