//
//  NSPair.cpp
//  
//
//  Created by BLAKE CONRAD on 4/1/15.
//
//

#include "NSPair.h"
#include <time.h>
#include <fstream>
#include <string>
#define forever for(;;)
using namespace std;

/**************/
/* NSPair.cpp */
/**************/

// CONSTRUCTORS / DECONSTRUCTORS
NSPair::NSPair(){
    
    NSPair::number = 0;
    NSPair::str = "NULL";
    
}

NSPair::NSPair(string fileName){
    
    ReadInNSPair(fileName);
    
}

NSPair::NSPair(int tempInt, string tempStr){
    
    NSPair::number = tempInt;
    NSPair::str = tempStr;
    
}

// SETTERS AND GETTERS
void NSPair::setNSPair(int i, string s){
    
    NSPair::number = i;
    NSPair::str = s;
    
}

NSPair NSPair::getNSPair(){
    return *this;
}

void NSPair::setNSPairStr(string newStr){
    
    NSPair::str = newStr;
}

string NSPair::getNSPairStr(){
    
    return NSPair::str;
}

void NSPair::setNSPairInt(int newInt){
    
    NSPair::number = newInt;
}

const int NSPair::getNSPairInt(){
    
    return NSPair::number;
}


// INSTANCE METHODS
void NSPair::ReadInNSPair(string fileName){
    
    // DECLARATIONS
    string tempStr;
    string line;
    string str_numLines;
    int int_numLines;
    NSPair *NSArray;
    NSPair *iNSArray;
    
    // OPEN FILE
    ifstream NSFile;
    NSFile.open(fileName.c_str());
    
    //UPDATE GLOBAL WITH FIRST LINE
    getline(NSFile, str_numLines);
    int_numLines = atoi(str_numLines.c_str());
    NSPair::maxElements = int_numLines;
    
/* BEGIN TO RIP CONTENTS OUT OF MY FILE AND STORE IT INTO AN ARRAY OF NSPAIR OBJECTS*/
    /* 1ST FOR LOOP IS TO EXECUTE THE 2ND FOR LOOP ON EACH LINE */
    for(int i = 0; i < int_numLines; i++){
        
        if (i == 0) {
            NSArray = new NSPair[int_numLines];
            iNSArray = new NSPair[int_numLines];
        }
        getline(NSFile, line);
        
        for(int j = 0; j < line.length(); j++){
            if(line.substr(j,1) == " "){
                /*
                 ONCE YOU ENTER THIS IF STATEMENT CONDITION, I CAN TREAT J AS MY STRING INDEX FOR WHERE MY " " LIES
                 */
                
                // DOMAIN = [0, SPACE) [0,space)
                string subLineInt = line.substr(0, j);
                
                // CONVERT && STORE
                int tempInt = atoi(subLineInt.c_str());
                
                // DOMAIN = (SPACE, END OF LINE]
                string subLineStr = line.substr(j+1, line.length());
                
                // STORE
                string tempStr = subLineStr;
                
                // SET STORED VALUES TO THE CURRENT OBJECT
                this->setNSPair(tempInt, tempStr);
                
                // STORE THAT OBJECT INTO AN ARRAY
                NSArray[i] = *this; /* FOR QUICKSORT */
                iNSArray[i] = *this; /* FOR ISORT */
                
            }
        }
        
    }
    
    cout << endl;
    
/* TIME MY QSORT */
    clock_t start;
    double duration;
    
    start = clock();
    QsortNS(NSArray, 0, int_numLines-1);
    duration = ( clock() - start ) / (double) CLOCKS_PER_SEC;
    cout << "QsortNS Duration: " << duration << endl;
/* END TIMER */
    
/* TIME MY ISORT */
    start = clock(); // updates the time that was previously initialized
    IsortNS(iNSArray);
    duration = ( clock() - start ) / (double) CLOCKS_PER_SEC;
    cout << "IsortNS Duration: "<< duration << endl;
/* END TIMER*/
    
/* FILE OUTPUT ISORT ARRAY*/
    string fn = "IsortNS_results.txt";
    fileWriter(iNSArray, fn);
/* END FILE OUTPUT */
    
    // CLEAN UP
    delete[] NSArray;
    delete[] iNSArray;
    NSFile.close();
}

int NSPair::findPivot(NSPair *NSArray, int smallestIndexInArray, int greatestIndexInArray){
    
   // FIND A LOGICAL PIVOT BASED ON OF THE MEDIAN VALUE
    int middleIndexInArray = (smallestIndexInArray + greatestIndexInArray)/2;
    
    // LEFT > MIDDLE ? SWAP
    if (NSArray[smallestIndexInArray].getNSPairInt()
        >
        NSArray[middleIndexInArray].getNSPairInt()
        ) {
        NSPair::NSSwap(NSArray[smallestIndexInArray], NSArray[middleIndexInArray]);
    }
    
    //LEFT > RIGHT ? SWAP
    if (NSArray[smallestIndexInArray].getNSPairInt()
        >
        NSArray[greatestIndexInArray].getNSPairInt()
        ) {
        NSPair::NSSwap(NSArray[smallestIndexInArray], NSArray[greatestIndexInArray]);
    }
    
    // MIDDLE > RIGHT ? SWAP
    if (NSArray[middleIndexInArray].getNSPairInt()
        >
        NSArray[greatestIndexInArray].getNSPairInt()
        ) {
        NSPair::NSSwap(NSArray[middleIndexInArray], NSArray[greatestIndexInArray]);
    }
    
    // RETURN LOGICAL INDEX TO BASE MY SORTING AROUND, AKA MY PIVOT
    return middleIndexInArray;
    
}

void NSPair::QsortNS(NSPair *NSArray, int left, int right){

    // SORT INTS
    QsortNSN(NSArray, left, right);
    
    for (int i = 0; i < maxElements; ++i) {
        cout << NSArray[i].getNSPairInt() << endl;
    }
    
    // SORT STRINGS WITH A TIED INT VAL
    QsortNSS(NSArray, left, right);
    
    // FILE OUTPUT FOR QSORTNS
    string fn2 = "QsortNS_results.txt";
    fileWriter(NSArray, fn2);
    
}

void NSPair::QsortNSN(NSPair *NSArray, int left, int right){

/*
 
 THE ESSENSE OF THIS QUICK SORT GOES AS FOLLOWS:
 
 recursively check templeft and tempright values that increase and decrease together swapping along the way until they meet in the middle, once they meet in the middle we declare a recursive call to repeat this with the left half and right half of our current array. this continues until the condition in LN 235 is met which will tell us whether our array is too small to sort, then it will approach an insortion sort to tie up the loose ends that the qosort didn't finish.
 
 */
    
    int pivot = findPivot(NSArray, left, right);
    int shifterLeft = left;
    int shifterRight = right;

    if(left < right){

        while (shifterLeft < shifterRight) {

            
            forever{
                if (NSArray[shifterLeft].getNSPairInt()
                    <=
                    NSArray[pivot].getNSPairInt()
                    and
                    shifterLeft<right
                    ){
                    shifterLeft++;
                }
                else
                    break;
            }
            forever{
                if (NSArray[shifterRight].getNSPairInt()
                    >
                    NSArray[pivot].getNSPairInt()
                    ){
                    shifterRight--;
                }
                else
                    break;
            }

        if(shifterLeft < shifterRight){
            NSSwap(NSArray[shifterLeft], NSArray[shifterRight]);
        }
            
    }
        
    NSSwap(NSArray[pivot], NSArray[shifterRight]);
    
    //QSORT LEFT SUB ARRAY
    QsortNSN(NSArray, left, shifterRight-1);
        
    //QSORT RIGHT SUB ARRAY
    QsortNSN(NSArray, shifterRight+1, right);
        
    }
    
    //ISORT OUR SMALL SUBARRAYS
    else{
        IsortNS(NSArray);
    }
    
}

void NSPair::QsortNSS(NSPair *NSArray, int left, int right){
    
    // SWAP ELEMENTS WITH IDENTICAL INT VALS AND HIGHER STRING VALS
    for (int k = 0; k < NSPair::maxElements; k++) {
        if (NSArray[k].getNSPairInt() == NSArray[k+1].getNSPairInt()) {
            if (NSArray[k].getNSPairStr() > NSArray[k+1].getNSPairStr()) {
                NSSwap(NSArray[k], NSArray[k+1]);
            }
        }
    }
}

void NSPair::NSSwap(NSPair& A, NSPair& B){
    
    //SWAP OBJECTS BY REFERENCE
    NSPair C = A;
    A = B;
    B = C;
}

void NSPair::IsortNS(NSPair *NSArray){
    
    for(int i = 1; i < NSPair::maxElements; i++) {
        for (int j = i; j > 0 && !(NSArray[j - 1].getNSPairInt() < NSArray[j].getNSPairInt()); j--) {
            NSSwap(NSArray[j-1], NSArray[j]);
        }
    }

    
}

void NSPair::fileWriter(NSPair *NSArray, string fileName){
    
// MAKE A OUPUT FILE OBJECT AND FOR ALL ELEMENTS IN MY SORTED ARRAY PRINT THEM TO MY FILE
    ofstream of(fileName.c_str());
    of << NSPair::maxElements << endl;
    for (int i = 0; i < NSPair::maxElements; i++) {
        of << NSArray[i].getNSPairInt() << " " << NSArray[i].getNSPairStr() << endl;
    }
    //cout << fileName << " has been added to your current directory." << endl;
}














