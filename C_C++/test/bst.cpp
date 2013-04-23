#include<stdio.h>
#include<stdlib.h>
#include<queue>
#include<stack>


typedef struct _tree
{
  struct _tree *right, *left;
  int data;
} BST;

typedef enum
{
  INORDERITER,
  POSTORDERITER,
  PREORDERITER,
  INORDER,
  POSTORDER,
  PREORDER,
  BFS,
  SPIRAL
} Type;

BST *
_new (int d)
{
  BST *tmp = (BST *) malloc (sizeof (BST));
  tmp->data = d;
  tmp->left = tmp->right = NULL;
  return tmp;
}


void
create (BST ** root, int d)
{
  BST *tra = *root;
  while (tra)
    {
      if (d > tra->data)
	{
	  if (tra->right)
	    tra = tra->right;
	  else
	    {
	      tra->right = _new (d);
	      break;
	    }
	}
      else if (d < tra->data)
	{
	  if (tra->left)
	    tra = tra->left;
	  else
	    {
	      tra->left = _new (d);
	      break;
	    }
	}
    }
}


void
createRec (BST * root, int d)
{
  if (root)
    {
      if (d > root->data)
	{
	  if (root->right)
	    createRec (root->right, d);
	  else
	    root->right = _new (d);
	}
      else if (d < root->data)
	{
	  if (root->left)
	    createRec (root->left, d);
	  else
	    root->left = _new (d);
	}
    }
}

void
inOrderIter (BST * tra)
{
  std::stack < BST * >st;
  st.push (tra);

  while (!st.empty ())
    {
      if (tra)
	{
	  st.push (tra);
	  tra = tra->left;
	}
      else
	{
	  tra = st.top ();
	  printf ("   %d   ", tra->data);
	  st.pop ();
	  tra = tra->right;
	}
    }
}

void
postOrderIter (BST * tra)
{
  std::stack < BST * >st;
  st.push (tra);
  while(!st.empty() || tra)
  {
      if(tra)
      {
          printf(" %d ",tra->data);
          tra = tra->left;
          st.push(tra);
      }
      else
      {
          tra = st.top();
          st.pop();
          if(tra->left)
          printf(" %d ",tra->left->data);
          if(tra->right)
          printf(" %d ",tra->right->data);
      }

  }

}

void
preOrderIter (BST * tra)
{
  std::stack < BST * >st;
  while (!st.empty () || tra )
    {
      if (tra)
	{
	  printf (" %d ", tra->data);
	  if (tra->right);
	  st.push (tra->right);
	  tra = tra->left;
	}
      else
	{
	  tra = st.top ();
	  st.pop ();
	}
    }

}

void
inOrder (BST * tra)
{
  if (tra)
    {
      inOrder (tra->left);
      printf (" %d ", tra->data);
      inOrder (tra->right);
    }
}

void
postOrder (BST * tra)
{
  if (tra)
    {
      inOrder (tra->left);
      inOrder (tra->right);
      printf (" %d ", tra->data);
    }
}

void
preOrder (BST * tra)
{
  if (tra){
      printf (" %d ", tra->data);
      inOrder (tra->left);
      inOrder (tra->right);
  }
}

void
bfs (BST * root)
{
  std::queue < BST * >q;
  q.push (root);
  while (!q.empty ())
    {
      BST *tmp = q.front ();
      printf (" %d ", tmp->data);
      if (tmp->left)
	q.push (tmp->left);
      if (tmp->right)
	q.push (tmp->right);
      q.pop ();
    }
}

void
spiral (BST * root)
{
  std::stack < BST * >st1;
  std::stack < BST * >st2;
  st1.push (root);

  while (!st1.empty () || !st2.empty ())
    {
      while (!st1.empty ())
	{
	  BST *t = st1.top ();
	  st1.pop ();
	  if (t)
	    {
	      printf ("   %d  ", t->data);
	      st2.push (t->right);
	      st2.push (t->left);
	    }
	}

      while (!st2.empty ())
	{
	  BST *t = st2.top ();
	  st2.pop ();
	  if (t)
	    {
	      printf ("   %d  ", t->data);
	      st1.push (t->left);
	      st1.push (t->right);
	    }
	}
    }
}

void
display (BST * root, Type t)
{
  switch (t)
    {
    case INORDER:
      printf ("\ndisplay :: INORDER \n");
      inOrder (root);
      break;
    case POSTORDER:
      printf ("\ndisplay :: POSTORDER \n");
      postOrder (root);
      break;
    case PREORDER:
      printf ("\ndisplay :: PREORDDER \n");
      preOrder (root);
      break;
    case BFS:
      printf ("\ndisplay ::BFS \n");
      bfs (root);
      break;
    case SPIRAL:
      printf ("\ndisplay ::EBFS \n");
      spiral (root);
      break;
    case INORDERITER:
      printf ("\n display :: INORDERITER\n");
      inOrderIter (root);
      break;
    case PREORDERITER:
      printf ("\n display :: INORDERITER\n");
      preOrderIter (root);
      break;
    case POSTORDERITER:
      printf ("\n display :: INORDERITER\n");
      postOrderIter(root);
      break;
    default:
      printf ("\ndisplay :: default \n");
      break;
    }
}


void
dNode (BST ** root, int d)
{
  BST *tra = *root;
  BST *tmp = NULL;
  int i = 1;
  while (tra)
    {
      if (d > tra->data)
	{
	  tmp = tra;
	  i = 0;
	  if (tra->right)
	    tra = tra->right;

	}
      else if (d < tra->data)
	{
	  tmp = tra;
	  i = 1;
	  if (tra->left)
	    tra = tra->left;
	}
      else
	{
	  printf ("\n %d == %d \n ", tra->data, d);
	  if (!tra->left && !tra->right)
	    {
	      free (tra);
	      tra = NULL;
	      if (i == 1)
		tmp->left = NULL;
	      if (i == 0)
		tmp->right = NULL;
	    }
	}
    }
}


int
main (void)
{
  BST *root = _new (30);

  int arr[] = { 45, 15, 18, 12, 36, 50 };
  printf ("\n\n 45, 15, 18, 12, 36, 50  \n\n\n");

  printf ("\t \t 30\t\t\n");
  printf ("\t 15  \t\t45\n");
  printf ("12\t\t18  36\t\t50\n");

  int i, s = sizeof (arr) / sizeof (int);

  for (i = 0; i < s; i++)
    // createRec(root,arr[i]);
    create (&root, arr[i]);

// display (root, INORDER);
// display (root, BFS);
// display (root, EBFS);
/* dNode(&root,12);
 display (root, INORDER);
 dNode(&root,18);
 display (root, INORDER);
 dNode(&root,36);
 display (root, INORDER);
 dNode(&root,50);
 display (root, INORDER);
 */
  //display(root,SPIRAL);
// display(root,POSTORDER);
  //display(root,INORDERITER);
  display (root, PREORDER);
  display (root, PREORDERITER);
  display (root, POSTORDERITER);
  return 0;
}
