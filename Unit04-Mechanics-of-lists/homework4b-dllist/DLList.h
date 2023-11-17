#pragma once

#include <iostream>
#include <string>

template<class T>
class DLList {
public:
    struct Node {
        Node* prev;
        Node* next;
        T value;

        Node(T v) : prev(nullptr), next(nullptr), value(v) {}
    };
    Node* head;
    Node* tail;
    int count;

    DLList() {
        head = nullptr;
        tail = nullptr;
        count = 0;
    }

    ~DLList() {
        clear();
    }

    const Node* get_head() const {
        return head;
    }

    void push_front(T item) {
        Node* newNode = new Node(item);
        if (head != nullptr) {
            newNode->next = head;
            head->prev = newNode;
        } else {
            tail = newNode;
        }
        head = newNode;
        count++;
    }
    void push_back(T item) {
        Node* newNode = new Node(item);
        if (tail != nullptr) {
            newNode->prev = tail;
            tail->next = newNode;
        } else {
            head = newNode;
        }
        tail = newNode;
        count++;
    }
    void insert(T item, int position) {
        if (position < 0 || position > count) {
            throw std::out_of_range("Cannot insert");
        }

        if (position == 0) {
            push_front(item);
        } else if (position == count) {
            push_back(item);
        } else {
            Node* newNode = new Node(item);
            Node* current = nullptr;

            if (position < count / 2) {
                current = head;
                for (int i = 0; i < position; ++i) {
                    current = current->next;
                }
            } else {
                current = tail;
                for (int i = count - 1; i > position; --i) {
                    current = current->prev;
                }
            }

            newNode->prev = current->prev;
            newNode->next = current;
            current->prev->next = newNode;
            current->prev = newNode;
            count++;
        }
    }

    void pop_front() {
       if (head == nullptr) {
            throw std::length_error("List empty");
        }

        Node* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }
        delete temp;
        count--;
    }
    void pop_back() {
        if (tail == nullptr) {
            throw std::length_error("List empty");
        }

        Node* temp = tail;
        tail = tail->prev;
        if (tail != nullptr) {
            tail->next = nullptr;
        } else {
            head = nullptr;
        }
        delete temp;
        count--;
    }
    void remove(int position) {

        Node* current = nullptr;

        if (position == 0) {
            pop_front();
        } else if (position == count - 1) {
            pop_back();
        } else {
            if (position < count / 2) {
                current = head;
                for (int i = 0; i < position; ++i) {
                    current = current->next;
                }
            } else {
                current = tail;
                for (int i = count - 1; i > position; --i) {
                    current = current->prev;
                }
            }

            current->prev->next = current->next;
            current->next->prev = current->prev;
            delete current;
            count--;
        }
    }
    const T& front() const {
        if (head == nullptr) {
            throw std::length_error("List empty");
        }
        return head->value;
    }
    const T& back() const {
        if (tail == nullptr) {
            throw std::length_error("List is empty");
        }
    return tail->value;
    }
    const T& at(int index) const {
        if (index < 0 || index >= count) {
            throw std::out_of_range("Out of range");
        }

        Node* current = nullptr;

        if (index < count / 2) {
            current = head;
            for (int i = 0; i < index; ++i) {
                current = current->next;
            }
        } else {
            current = tail;
            for (int i = count - 1; i > index; --i) {
                current = current->prev;
            }
        }

        return current->value;
    }

    bool contains(const T& item) const {
        Node* current = head;
        while (current != nullptr) {
            if (current->value == item) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    int size() const {
        return count;
    }

    void clear() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
        count = 0;
    }
};
