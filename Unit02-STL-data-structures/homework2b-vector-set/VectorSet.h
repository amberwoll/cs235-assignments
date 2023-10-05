#pragma once
#include <vector> 

template<class T>
class VectorSet {
public:

    std::vector<T> some_vector;

    bool contains(T item) const {
        // implement contains here
        for (const T& thing : some_vector) {
            if (thing == item) {
                return true;
            }
        }
        return false;
    }
        // return true if item is in the set and false if not
    

    bool insert(T item) {
        // implement insert here
        if (contains(item)) {
            return false;
        }
        some_vector.push_back(item);
        return true;
        }

        // return true if item is inserted and false if item is already in the
        // set

    bool remove(T item) {
        // implement remove here
        if (!contains(item)) {
            return false;
        } else {
            for (auto it = some_vector.begin(); it != some_vector.end();) {
                if (*it == item) {
                    it = some_vector.erase(it);
                } else {
                    ++it;
                }
            }        
            return true;
        }
        }
        // return true if item is removed and false if item wasn't in the set

    int size() const {
        // implement size here
        return some_vector.size();
        // return the number of items in the set
    }

    bool empty() const {
        // implement empty here
        if (some_vector.size() == 0) {
            return true;
        }
        return false;
        // return true if the set is empty and return false otherwise
    }

    void clear() {
        // implement clear here
        return some_vector.clear();
        // remove all items from the set
    }
};
