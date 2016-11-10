//
//  NSPair.h
//  
//
//  Created by BLAKE CONRAD on 4/1/15.
//
//

#ifndef ____NSPair__
#define ____NSPair__

#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <stdlib.h>
using namespace std;

class NSPair{
private:
    int number;
    string str;
    
public:
    // EXTRA PUBLIC MEMBERS TO KEEP TRACK OF THINGS
    int maxElements;
    
    // CONSTRUCTOR AND DECONSTRUCTOR
    NSPair();
    NSPair(string);
    NSPair(int, string);
    
    // SETTERS AND GETTERS
    void setNSPair(int, string);
    void setNSPairStr(string);
    void setNSPairInt(int);
    
    NSPair getNSPair();
    const int getNSPairInt();
    string getNSPairStr();
    
    // INSTANCE METHODS
    void ReadInNSPair(string);
    int findPivot(NSPair*, int, int);
    void NSSwap(NSPair& A, NSPair& B);
    void QsortNS(NSPair*, int, int);
    void QsortNSN(NSPair*, int, int);
    void QsortNSS(NSPair*, int, int);
    void IsortNS(NSPair*);
    void fileWriter(NSPair*, string);
    
};



#endif /* defined(____NSPair__) */
