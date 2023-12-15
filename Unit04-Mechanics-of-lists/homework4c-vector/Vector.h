#pragma once

#include <iostream>
#include <string>
#include <algorithm>

template<class T>
class Vector {
public:
    T* arr;
    int currentSize;
    int capacity;

    Vector() : arr(nullptr), currentSize(0), capacity(0) {}

    ~Vector() {
        delete[] arr;
    }

    void resizeIfNeeded() {
        if (currentSize >= capacity) {
            capacity = std::max(1, capacity * 2);
            T* newArr = new T[capacity];
            for (int i = 0; i < currentSize; ++i) {
                newArr[i] = arr[i];
            }
            delete[] arr;
            arr = newArr;
        }
    }

    void push_back(T item) {
        resizeIfNeeded();
        arr[currentSize++] = item;
    }

    void insert(T item, int position) {
        if (position < 0 || position > currentSize) {
            throw std::out_of_range("Index out of range");
        }
        resizeIfNeeded();
        for (int i = currentSize; i > position; i--) {
            arr[i] = arr[i - 1];
        }
        arr[position] = item;
        currentSize++;
    }

    void remove(int position) {
        if (position < 0 || position >= currentSize) {
            throw std::out_of_range("Index out of range");
        }
        for (int i = position; i < currentSize - 1; ++i) {
            arr[i] = arr[i + 1];
        }
        currentSize--;
    }

    T& operator[](int index) {
        if (index < 0 || index >= currentSize) {
            throw std::out_of_range("Index out of range");
        }
        return arr[index];
    }

    int size() const {
        return currentSize;
    }

    void clear() {
        currentSize = 0;
        capacity = 0;
        delete[] arr;
        arr = nullptr;
    }
};
