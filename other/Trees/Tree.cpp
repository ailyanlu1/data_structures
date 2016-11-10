// Tree.cpp

#include "Tree.h"
Tree::Tree ()
{    
    root = NULL;  
}
Tree::~Tree()
{ }

Node* Tree::insert (int nr1, Node *p)
{
   if(p == NULL)
   {
      Node *p1 = new Node;
   
      p1->data = nr1;
      p1->left = NULL;
      p1->right = NULL;
      
      p = p1;
   }
   else
   {
       if(nr1 < p->data)
          p->left = insert(nr1, p->left);
       else p->right = insert(nr1, p->right);
   } 
   
   return p;
}

//void Tree::setRoot(Node *t1)

Node* Tree::getRoot()
{
      return root;
}

void Tree::printTree (Node *t1, int moveCursor)
{
   Node *p = t1;
      
   if (p != NULL)  
   {

       if(p->right != NULL)
          printTree(p->right, moveCursor+6);
       for(int i = 0; i < moveCursor; i++)
          cout<<" ";
       cout << p->data << endl;
       if(p->left != NULL)
          printTree(p->left, moveCursor+6);
   }   
}

int Tree::countNrNode(Node *t)
{

    if (t == NULL)
       return 0;
    else{
        return 1 + countNrNode(t->left) + countNrNode(t->right);
    }
}

int Tree::countNrNodeLessThan(Node *t, int max)
{

    if (t == NULL)
       return 0;
    else if(t->data >= max)
         return countNrNodeLessThan(t->left, max) + countNrNodeLessThan(t->right,max);
    else
    {
        specTree.push_back(t->data);
        return 1 + countNrNodeLessThan(t->left, max) + countNrNodeLessThan(t->right,max);
    }
}
