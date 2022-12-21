//
// Created by nabee on 10/25/2022.
//

#ifndef DSStackVector_H
#define DSStackVector_H

#include<vector>
#include<iostream>
using namespace std;

template <typename Object>

class StackVector
{
    private:
    vector <Object> list;
public:
    bool empty();
    Object top();
    void push(Object x);
    void pop();
    int size();
    Object index( int x);
};
//checks if list is empty
template<typename Object>
bool StackVector<Object>::empty() {
    return list.empty();
}
//returns the first element of the stack
template<typename Object>
Object StackVector<Object>::top() {
    return list.at(0);
}
//adds a new element in the beginning of the stack
template<typename Object>
void StackVector<Object>::push(Object x) {
    list.insert(list.begin(), x);
}
//removes the first element
template<typename Object>
void StackVector<Object>::pop() {
    list.erase(list.begin());
}
//returns the length of the vector
template<typename Object>
int StackVector<Object>::size() {
    return list.size();
}
//gives the index, just made for checking purposes though
template<typename Object>
Object StackVector<Object>::index(int x) {
    return list.at(x);
}

#endif