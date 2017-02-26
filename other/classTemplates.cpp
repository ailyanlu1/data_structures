#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <stdexcept>
using namespace std;


// class template : its most common use is when the type of object you are creating is dependant on an unknown type; data structures are perfect for this.
// function template : much more commonly found in isolation like with the std::swap() function, are needed when you want to do calculations on any type of object being passed; most useful for general cases for manipulating the objects

template <class T>
class Stack { // the stack requires <some type> to go into it
  private: 
    vector<T> elems;     // elements 

  public: 
    void push(T const&);  // push element 
    void pop();               // pop element 
    T top() const;            // return top element 
    inline bool empty() const{       // return true if empty.
        return elems.empty(); 
    } 
}; 

template <class T>
void Stack<T>::push(T const& elem) 
{ 
    // append copy of passed element 
    elems.push_back(elem);    
} 

template <class T>
void Stack<T>::pop () 
{ 
    if (elems.empty()) { 
        throw out_of_range("Stack<>::pop(): empty stack"); 
    }
	// remove last element 
    elems.pop_back();         
} 

template <class T>
T Stack<T>::top () const 
{ 
    if (elems.empty()) { 
        throw out_of_range("Stack<>::top(): empty stack"); 
    }
	// return copy of last element 
    return elems.back();      
} 

int main() 
{ 
    try { 
        Stack<int> intStack;  // stack of ints 
        Stack<string> stringStack;    // stack of strings 

        // manipulate int stack 
        intStack.push(7); 
        cout << intStack.top() <<endl; 

        // manipulate string stack 
        stringStack.push("hello"); 
        cout << stringStack.top() << std::endl; 
        stringStack.pop(); 
        stringStack.pop(); 
    } 
    catch (exception const& ex) { 
        cerr << "Exception: " << ex.what() <<endl; 
        return -1;
    } 
} 
