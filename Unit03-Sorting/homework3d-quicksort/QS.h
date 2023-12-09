#pragma once
#include <algorithm>
#include <vector>

template<class T>
int medianOfThree(std::vector<T>& array, int left, int right) {
    // implement medianOfThree here
    int middle = left + (right - left) / 2;

    if (array[right] < array[left])
        std::swap(array[right], array[left]);
    if (array[middle] < array[left])
        std::swap(array[middle], array[left]);
    if (array[right] < array[middle])
        std::swap(array[right], array[middle]);

    return middle;
}

template<class T>
int partition(std::vector<T>& array, int left, int right) {
    // implement partition here
    int switch_point_index = medianOfThree(array, left, right);
    T switch_point = array[switch_point_index];
    int i = left - 1;
    int j = right + 1;

    while (true) {
        do {
            i++;
        } while (array[i] < switch_point);

        do {
            j--;
        } while (array[j] > switch_point);

        if (i >= j)
            return j;

        std::swap(array[i], array[j]);
    }
}

template<class T>
void sort_helper(std::vector<T>& array, int left, int right) {
    if (left < right) {
        int switch_point = partition(array, left, right);
        sort_helper(array, left, switch_point);
        sort_helper(array, switch_point + 1, right);
    }
}

template<class T>
void sort(std::vector<T>& array) {
    
    sort_helper(array, 0, array.size() - 1);
    // implement sort here
    // hint: you'll probably want to make a recursive sort_helper function
}
