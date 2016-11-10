#ifndef LINKEDLIST_H_EXISTS
#define LINKEDLIST_H_EXISTS
#include "cell.h"
using namespace std;



class LinkedList{
private:
    struct Node{
        Cell data;
        Node* next;
    };
    
    Node* start;
    Node* current;
    Node* finish;
    Node* fugitive;

public:
    // CONSTRUCTOR / DECONSTRUCTOR
    LinkedList();
    ~LinkedList();
    
    // GETTERS / SETTERS
    Cell getStartData();
    Cell getFinishCell();
    
    //OTHER PUBLIC FUNCTIONS
    void insertCell(Cell item);
    void deleteCell(Cell item);

};

#endif /* defined(____linkedlist__) */