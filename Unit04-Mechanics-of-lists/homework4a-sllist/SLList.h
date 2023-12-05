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
        return head;
    }

    void push_back(T item) {
        Node* newNode = new Node(item);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        count++;
    }

    void pop_back() {
        if (head == tail) {
            delete head;
            head = nullptr;
            tail = nullptr;
        } else {
            Node* current = head;
            while (current->next != tail) {
                current = current->next;
            }
            delete tail;
            tail = current;
            tail->next = nullptr;
        }
        count--;
    }

    const T& front() const {
        return head->value;
    }

    int size() const {
        return count;
    }

    void clear() {
        // implement clear here
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
        count = 0;
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
