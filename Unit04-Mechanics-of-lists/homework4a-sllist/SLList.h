#pragma once
#include <iostream>
using namespace std;

template <class T>
class SLList {
public:
    struct Node {
        Node* next;
        T value;

        Node(T v) : next(nullptr), value(v) {}
    };

    SLList() {
        head = nullptr;
        tail = nullptr;
        count = 0;
    }

    ~SLList() {
        clear();
    }

    const Node* get_head() const {
        // implement get_head here
    }

    void push_back(T item) {
        // implement push_back here
        // step 1: create node
        Node* newNode = new Node(item);
        // step 2: update tail next to point to the new node
        if (tail != nullptr) {
            tail->next = nullptr;
        }
        // step 3: change head and tail
        tail = newNode;
        if (head == nullptr) {
            head = newNode;
        }
        count++;
    }

    void pop_back() {
        // implement pop_back here
    }

    const T& front() const {
        // implement front here
    }

    int size() const {
        // implement size here
    }

    void clear() {
        // implement clear here
        while (head != nullptr)
            remove 0;
    }

    void remove(int position) {
        if (head == nullptr) 
            return;
        
        if (position == 0) {
            Node* tmp = head;
            head = head->next;
            delete tmp;
        }
        else {
            //get a pointer to the item before position
            
            Node* itr = head;
            for (int i = 0; i < (position-1); i++)
                itr = itr->next;
            
            Node* tmp = itr->next;
            itr->next = itr->next->next;
            delete tmp;
        }
        count--;
    }

    void print() {
        cout << "The items in the linked list are: ";
        Node* itr = head;
        while (itr != nullptr) {
            cout << itr->value << ", ";
            itr = itr->next;
        }
        cout << endl;
    }

    private:
        Node* head;
        Node* tail;
        int count;
};
