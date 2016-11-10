#import <iostream>
#include "stack.h"
using namespace std;

/*************/
/* stack.cpp */
/*************/

//CONSTRUCTOR / DECONSTRUCTOR
Stack::Stack(int size){
    Stack::currentStackIndex = 0;
    Stack::maxStackSize = size;
    Stack::list = new Cell[maxStackSize];
}

Stack::~Stack(){
    delete[] list;
}

// GETTERS / SETTERS
bool Stack::isFull(){
    //simply check and see if the stack index is at the top, if it is it will return a true boolean
    return (currentStackIndex == maxStackSize);
}

bool Stack::isEmpty(){
    //just sets the current index to 0, which will allow access to overwrite those elements later in the list. This is an allusion, but a widespread practice for this method.
    return Stack::currentStackIndex == 0;
}

Cell* Stack::getList(){
    //return my list;
    return Stack::list;
}


int Stack::getLength(){
    //return stack index;
    return Stack::currentStackIndex;
}

// OTHER PUBLIC METHODS
Cell Stack::top(){
    //everytime we add a member to the stack we add it to the current top, so slot 0 holds the first element, so then we incrememnt the stack up one, so it has nothing in it, so we must -1 to get back to the element on top
    return Stack::list[Stack::currentStackIndex - 1];
}

void Stack::push(Cell newItem){
    //assuming my list is not full, go ahead and add the new cell to my list at its current index and then incredmenet currentStackIndex for next round. If this fails we have a full stack.
    if (!isFull()) {
        Stack::list[Stack::currentStackIndex] = newItem;
        Stack::currentStackIndex++;
    }
    else{
        cout << "Problem: This is a full stack.";
    }
}

void Stack::pop(){
    //by decrementing the currentStackIndex we give the illusion of there not being a cell at that index. This is a wide spread implementation of this method in an array based stack.
    if (!isEmpty()) {
        Stack::currentStackIndex--;
        
    }
}


