#pragma once

#include <iostream>
#include <string>

template<class T>
class Vector {
public:

    T* arr;
    int currentSize = 0;

    Vector() {
    }

    ~Vector() {
        delete[] arr;
    }

    void push_back(T item) {
        arr[currentSize++] = item;
        // implement push_back here
    }

    void insert(T item, int position) {
        if (position < 0 || position >= currentSize) {
            throw std::out_of_range("Index out of range");
        }
        for (int i = currentSize; i > position; i--) {
            arr[i] = arr[i - 1];
        }
        arr[position] = item;
        currentSize++;
        // implement insert here
    }

    void remove(int position) {
        if (position < 0 || position >= currentSize) {
            throw std::out_of_range("Index out of range");
        }
        for (int i = position; i < currentSize - 1; ++i) {
            arr[i] = arr[i + 1];
        }
        currentSize--;
        // implement remove here
    }

    T& operator[](int index) {
        if (index < 0 || index >= currentSize) {
            throw std::out_of_range("Index out of range");
        }
        return arr[index];
        // implement operator[] here
    }

    int size() const {
        return currentSize;
        // implement size here
    }

    void clear() {
        while (currentSize > 0) {
            remove(0);
            currentSize--;
        }
        // implement clear here
    }
};
