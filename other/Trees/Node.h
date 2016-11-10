//  Node.h

#ifndef Node_h
#define Node_h

#include <iostream>
using namespace std;


class Node
{
    public:
           int data;
           Node *left, *right;
           
    public:
          Node ();
          ~Node();
};

#endif  
          
                 
