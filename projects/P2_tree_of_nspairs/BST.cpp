//
//  BST.cpp
//  
//
//  Created by BLAKE CONRAD on 4/5/15.
//
//

#include "BST.h"
//#include "NSPair.h"
//#include "NSQueue.h"

BST::BST(){
}

BST::~BST(){
    DUMB.close();
}
BST::BST(string fileName){

/* RIP OUT LINE BY LINE AND STORE INTO AN ARRAY  */
    
    string tempStr;
    string line;
    string str_numLines;
    int int_numLines;
    NSPair *tempArray;
    NSPair *tempObj;
    
    ifstream QsortFile;
    
    QsortFile.open(fileName.c_str());
    
    getline(QsortFile, str_numLines);
    int_numLines = atoi(str_numLines.c_str());
    BST::max = int_numLines;

    for(int i = 0; i < int_numLines; i++){
        
        if (i == 0) {
            tempArray = new NSPair[int_numLines];
        }
        getline(QsortFile, line);
        
        for(int j = 0; j < line.length(); j++){
            if(line.substr(j,1) == " "){
                
                string subLineInt = line.substr(0, j);
                
                int tempInt = atoi(subLineInt.c_str());
                
                string subLineStr = line.substr(j+1, line.length());
                
                string tempStr = subLineStr;
                
                NSPair *tempObj = new NSPair(tempInt,tempStr);

                tempArray[i] = *tempObj;
            }
        }
        
    }
    
/* USE THAT ARRAY TO MAKE A TREE USING A NEW CONSTRUCTOR */
    
    //MAKE A BST OBJECT WITH NEW PARAMETERS
    BST QsortTree(tempArray, 0, BST::max-1);
    
    // CLEAN UP
    delete[] tempArray;
    delete tempObj;
}

BST::BST(NSPair obj){
    this->data = obj;
    this->left = NULL;
    this->right = NULL;
    
}

BST::BST(NSPair *NSArray, int left, int right){
    // CONSTRUCT A FRESH TREE WITH OUR ARRAY OF INPUT TO RECEIVE THE CONSTRUCTED TREE
    BST *yourTree;
    yourTree = ConstBSTNS(NSArray, left, right);
    
    // EXECUTE AN INORDER TRAVERSAL ON NEWLY CONSTRUCTED TREE
    InorderBSTNS(yourTree);
    
    // EXECUTE AN INORDER TRAVERSAL TO FIND THE MAX STRING
    findBSTmaxStr(yourTree);
    
/* BEGIN FILE OUTPUT */
    ofstream maxStr("BST_maxStr.txt");
    maxStr << globalStr << endl;
/* END FILE OUTPUT */
    
    // LblTraversal(yourTree);
    
    //CLEAN UP
    maxStr.close();
    cout << "BST_Inorder.txt has been added to your current directory." << endl;

}

NSPair BST::getBSTNSPairObj(){
    return this->data;
}


BST* BST::ConstBSTNS(NSPair *NSArray, int left, int right){
    
/* BASE CASE TO DETERMINE WHEN A SUBARRAY HAS BECOME TOO SMALL */
    if (left > right){
        return NULL;
    }
    
/* CENTER = MIDPOINT */
    int center = (left + right)/2;

/* MAKE A NEW OBJECT IN THE MIDDLE OF MY CURRENT ARRAY */
    BST *node = createNewBSTObj(NSArray[center]);
    
/* THIS MAKES AN OBJECT IN THE CENTER OF MY LEFT SUB ARRAY */
    node->left = ConstBSTNS(NSArray, left, center-1);
    
/* THIS MAKES AN OBJECT IN THE CENTER OF MY RIGHT SUB ARRAY */
    node->right = ConstBSTNS(NSArray, center+1, right);

/* RETURN A POINTER TO MY ROOT OBJECT - THIS IS MY WHERE MY ENTIRE TREE IS CONNECTED */
    return node;
}

BST* BST::createNewBSTObj(NSPair obj){
    BST *node = new BST(obj);
    return node;
}

void BST::InorderBSTNS(BST *node){
    
/* GO THROUGH MY TREE (A POINTER TO THE ROOT) */
    
/* BASE CASE TO CATCH IF WE ARE ACTUALLY DEALING WITH A TRUE OBJECT OR A NULL POINTER */
    if(node == NULL){
        return;
    }
    else{
    /* CHECK MY ROOTS LEFT SIDE OF THE FAMILY TREE, THEN ITSELF WILL BE ADDED */
        InorderBSTNS(node->left);
        fileWriter(node->getBSTNSPairObj().getNSPairInt());
    /* CHECK MY ROOTS RIGHT SIDE OF THE FAMILY TREE, THEN IT WILL COMPLETE WITH THE LAST ELEMENT BEING OUTPUTTED */
        InorderBSTNS(node->right);
    }
}

void BST::fileWriter(int data){
    DUMB << data << endl;
}

void BST::findBSTmaxStr(BST *node){
/* EXECUTE A CUSTOM INORDER SORT */

/* JUST CHECK EVERY SUBTREES LEFT AND RIGHT TO SEE WHO HAS THE MOST PROMINENT STRING */
    
/* THE STRING CLASS IS OPERATOR OVERLOADED WITH STRCMP() SO I CAN JUST COMPARE WITH INEQUALITIES INSTEAD OF STRCMP()
 */
    if(node == NULL){
        return;
    }
    else{
         if (node->data.getNSPairStr() > globalStr) {
         globalStr = node->data.getNSPairStr();
         }
        
        findBSTmaxStr(node->left);
        
        findBSTmaxStr(node->right);
    }
}


