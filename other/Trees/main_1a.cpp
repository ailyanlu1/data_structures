//Count the number of Nodes in a Binary Tree

#include "Tree.h"
#include <vector>
#include <algorithm>

////////////  main  /////////////////
int main()
{
   // we create obj#1 of tree cls
   Tree tree1;
   Node *t1 = tree1.getRoot();
   
   t1 = tree1.insert(100, t1);
   t1 = tree1.insert(82, t1);
   t1 = tree1.insert(36, t1);
   t1 = tree1.insert(13, t1);
   t1 = tree1.insert(25, t1);
   t1 = tree1.insert(58, t1);
   t1 = tree1.insert(200, t1);
   t1 = tree1.insert(2, t1);
   
   // Print Tree
   cout << "TREE 1 -- NO CONSTRAINTS \n\n";
   tree1.printTree(t1, 6);
    cout << "PRESS ENTER TO CONTINUE" << endl;
    cin.ignore();
    
   system("pause");
}

