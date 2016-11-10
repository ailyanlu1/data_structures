#ifndef STACK_H_EXISTS
#define STACK_H_EXISTS

#include "cell.h"
using namespace std;

/***********/
/* stack.h */
/***********/

class Stack{
private:
    int maxStackSize;
    int currentStackIndex;
    Cell *list;
    
public:
    //CONSTRUCTOR / DECONSTRUCTOR
    Stack(int size);
    ~Stack();
    
    //GETTERS / SETTERS
    int getLength();
    bool isEmpty();
    bool isFull();
    
    //OTHER PUBLIC METHODS
    Cell top();
    Cell* getList();
    void push(Cell newItem);
    void pop();
};

#endif /* defined(____stack__) */