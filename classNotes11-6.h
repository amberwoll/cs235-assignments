#pragma once
#include <iostream>
// means don't compile an h file more than once, should be included at the top of any h file
// this is supposed to a .h file
using namespace std;

template <class T>
//when using this class in other places, it knows that anything can be given any value for node
class SLList {
public:
    struct Node {
        Node* next;
        T value; 

        // Node(T v) : next(nullptr), value(v) {} This does the same as the following lines
        Node(T v) {
            value = v;
            next = nullptr;
        }
    };
    

    SLList() {
        cout << "SLList constructor is called" << endl;
        head = nullptr;
        tail = nullptr;
        count = 0;

    }

    ~SLList() {
        cout << "SLList deconstructor is called" << endl;
    }

    void push_back(T item) {

    }

    const T& at(int index) const {

    }

    void clear() {

    }

private:
    Node* head;
    Node* tail;
    int count;
};


