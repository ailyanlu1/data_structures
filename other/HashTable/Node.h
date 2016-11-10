//  Node.h

#ifndef Node_h
#define Node_h

#include <string>
#include <iostream>
using namespace std;

enum EntryType {Legitimate, Empty, Deleted};

class Node
{
    public:
           string data;
           int phoneNr;
           enum EntryType info;
           Node *next;
           
    public:
          Node ();
          ~Node();
};

#endif  
          
                 
