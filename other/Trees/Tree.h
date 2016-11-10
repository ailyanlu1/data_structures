//  Tree.h

#ifndef Tree_h
#define Tree_h

#include "Node.h"

#include <vector>
class Tree
{
    private:
           Node *root;
           
    public:
          Tree ();
          ~Tree();
          vector<int> specTree;
          Node* insert (int nr1, Node *p);
          int countNrNode(Node *t);
          int countNrNodeLessThan(Node *t, int max);
          Node* getRoot();
          void printTree (Node *t1, int moveCursor);
};

#endif  
          
