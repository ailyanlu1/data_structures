//
//  BST.h
//  
//
//  Created by BLAKE CONRAD on 4/5/15.
//
//

#ifndef ____BST__
#define ____BST__

#include <stdio.h>
#include "NSPair.h"

/* DECLARE GLOBALLY BECAUSE OF INSTANTIATION ISSUES AS A PUBLIC MEMBER */
static ofstream DUMB("BST_Inorder.txt");
static std::string globalStr = "";

class BST{
protected:
    NSPair data;
    BST* left;
    BST* right;
public:
    // EXTRA PUBLIC MEMBERS TO KEEP TRACK OF THINGS
    int max;
    
    // CONSTRUCTORS AND DECONSTRUCTORS
    BST();
    ~BST();
    BST(NSPair);
    BST(std::string);
    BST(NSPair*, int, int);
    
    // SETTERS AND GETTERS
    NSPair getBSTNSPairObj();
    
    // EXTRA INSTANCE METHODS
    BST* ConstBSTNS(NSPair*, int, int);
    BST* createNewBSTObj(NSPair);
    void InorderBSTNS(BST*);
    //void LblTraversal(NSPair*);
    void fileWriter(int);
    void findBSTmaxStr(BST*);
    

};

#endif /* defined(____BST__) */
