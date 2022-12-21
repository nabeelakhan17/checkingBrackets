// Implement a class that provides a stack interface for your DSLists class.

// Implement:
// push, pop, top, empty, size
#ifndef DSStack_H
#define DSStack_H


#include "DSList.h"
#include <iostream>
using namespace std;
template <typename Object>

class DSStack{
private:
    DSList<Object> ss;

public:
    void push(Object x);
    void pop();
    Object top();
    bool empty();
    int size();


};
//adds new element at the front
template<typename Object>
void DSStack<Object>::push(Object x) {
    ss.push_front(x);


}
//removes element at the front
template<typename Object>
void DSStack<Object>::pop() {
    ss.pop_front();
}
//returns the first element
template<typename Object>
Object DSStack<Object>::top() {
    if(ss.empty())
    {
        cout<<"Error"<<endl;
    }
    return ss.first();
}
//returns true or false
template<typename Object>
bool DSStack<Object>::empty() {
    return ss.empty();
}
//returns the length of the list
template<typename Object>
int DSStack<Object>::size() {
   return ss.size();
}

#endif


