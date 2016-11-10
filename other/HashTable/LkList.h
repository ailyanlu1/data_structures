//  LkList.h

#ifndef LkList_h
#define LkList_h

#include "Node.h"
#include <vector>
#include <string.h>
class LkList
{
    public:
           Node *pll;
           
    public:
          LkList ();
          ~LkList();
          void insert (string name1, int phoneNr1);
          int search (string name1);
          bool search2 (string name1);
        //  void deleteNode (int nr1);
          void printL ();
};

#endif  
          
