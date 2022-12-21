#ifndef DSList_H
#define DSList_H

/**
 * @brief Singly-linked list that uses position
 *
 * 1. Use a postion index to refer to an element. This is simpler to
 *    implement compared to iterators (see iterator version), but does not
 *    play as nicely with the STL.
 * 2. Optional: Use a sentinel node (a node without data that represents the
 *    beginning of the list).
 * 
 * @tparam Object 
 */
template <typename Object>
class DSList
{
private:
   /**
     * @brief The nested Node data structure
     * 
     * struct is in C++ a class with all public members
     */
    struct Node
    {
        Object data;
        Node *next = nullptr;
        Node *prev = nullptr;

        Node(const Object &d = Object{}, Node *n = nullptr, Node *p = nullptr)
            : data{d}, next{n}, prev{p} {};
    };
    
    Node *head = nullptr;
    Node *tail = nullptr;
    int length = 0;

public:

DSList();

DSList(DSList<Object> &x);
~DSList();
DSList<Object> operator=(DSList<Object> &x);

int size();
Object first();
bool empty();
void clear();
int find(Object x);
void push_front(Object x);
void insert (Object x,  int index);
void pop_front();
void remove(int x);
void find_remove(Object x );
Object &operator[](const int);




};
//DSList constructor
template<typename Object>
DSList<Object>:: DSList() {
    length = 0;
    head = nullptr;
    tail = nullptr;

}
//performs a deep copy of the list
template<typename Object>
DSList<Object>:: DSList(DSList<Object> &x) {

    Node* itr = x.head;
    //checks if the head is null, then performs a copy
    if (itr != nullptr) {
        head = new Node(itr->data);
        tail = head;
        itr = itr->next;
    }
    //if head is not null, iterates through the list and performs a copy
    while (itr != nullptr) {
        tail->next = new Node(itr->data);
        tail->next->prev = tail;
        tail = tail->next;
        itr = itr->next;
    }
    length = x.length;
}
//deletes the dynamically allocated list
template<typename Object>
DSList<Object>:: ~DSList() {
    clear();
}
//utilized this code from stack overflow
//performs a deep copy with the assignment operator
template<typename Object>
DSList<Object> DSList<Object>::operator=(DSList<Object> &x) {

    clear();
    Node* itr = x.head;
    if (itr != nullptr) {
        head = new Node(itr->data);
        tail = head;
        itr = itr->next;
    }
    while (itr != nullptr) {
        tail->next = new Node(itr->data);
        tail->next->prev = tail;
        tail = tail->next;
        itr = itr->next;
    }
    length = x.length;
    return *this;
}
//returns the size of the linked list
template<typename Object>
int DSList<Object>::size() {
    return length;
}
//returns true if it is empty, false if it does not
template<typename Object>
bool DSList<Object>::empty() {
    if(head == nullptr) {
        return true;
    }
    return false;
}
//deletes all the nodes by iterating to the end of the list and performing pop_front
template<typename Object>
void DSList<Object>::clear() {
    while(length != 0)
    {
        pop_front();
    }
}
//returns the index at which the object is found
template<typename Object>
int DSList<Object>::find(Object x) {
    Node* current = head;
    int counter = 0;
    //iterates through the list and looks at the data of each node
    while(current!=nullptr)
    {
        if(current->data == x)
        {
            return counter;
        }

        counter++;
        current = current->next;

    }
    return -1;
}

template<typename Object>
//adds a object to the front of the list
void DSList<Object>::push_front(Object x) {
    Node* newNode = new Node();
    newNode->data = x;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    //checks if the head is null
    if(head == nullptr)
    {
        head= newNode;
    }
    else
    {
        head->prev = newNode;
        newNode-> next = head;
        head = newNode;
    }

    length++;
}

template<typename Object>
//inserts the object at a certain index
void DSList<Object>::insert(Object x, int index) {
    Node* itr = head;
    //iterates to the index with the for loop
    for (int i = 0; i < index; i++) {
        itr = itr->next;
    }
    Node* temp = new Node(x);
    if (itr->prev != nullptr) {
        itr->prev->next = temp;
        temp->prev = itr->prev;
    }
    if (itr != nullptr) {
        itr->prev = temp;
        temp->next = itr;
    }
    if (index == 0) {
        head = temp;
    }
    if (index == length) {
        tail = temp;
    }
    length++;
}

template<typename Object>
void DSList<Object>::pop_front() {
    //deletes the first element of the list
    if(head!=nullptr)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
        if(head!=nullptr)
        {
            head->prev = nullptr;
        }
    }


    length--;
}

template<typename Object>
//removes the node at the certain index
void DSList<Object>::remove(int index) {
    Node* itr = head;
    for (int i = 0; i < index; i++) {
        itr = itr->next;
    }

    if(itr->prev!= nullptr)
    {
        itr->prev->next = itr->next;

    }
    if(itr->next!=nullptr)
    {
        itr->next->prev = itr->prev;
    }
    if (itr == head) {
        head = itr->next;
    }
    if (itr == tail) {
        tail = itr->prev;
    }
    delete itr;
    length--;
}

template<typename Object>
//finds the object within the linked list and removes it
void DSList<Object>::find_remove(Object x) {
    Node *current = head;
    for(int i =0; i< length; i++)
    {
        if(x == current->data)
        {
            remove(i);
            i--;
        }

        current = current->next;
    }
}
//operator to access a certain index in the linked list
template<typename Object>
Object &DSList<Object>::operator[](const int index) {
    Node* itr = head;
    for (int i = 0; i < index; i++) {
        itr = itr->next;
    }
    return itr->data;
}

//returns the head
template<typename Object>
Object DSList<Object>::first() {
    return head->data;
}

#endif
