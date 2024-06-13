#pragma once
#include <iostream>
#include <vector>

template<class T>
int medianOfThree(std::vector<T>& array, int left, int right) {
    // implement medianOfThree here
    int middle = (left + right)/2;
    T temp;
    if(array.at(left)>array.at(middle)) {
        temp = array.at(middle);
        array.at(middle) = array.at(left);
        array.at(left) = temp;
    }
    if(array.at(middle)>array.at(right)) {
        temp = array.at(middle);
        array.at(middle) = array.at(right);
        array.at(right) = temp;
    }
    if(array.at(left)>array.at(middle)) {
        temp = array.at(middle);
        array.at(middle) = array.at(left);
        array.at(left) = temp;
    }
    return middle;
}

template<class T>
int partition(std::vector<T>& array, int left, int right) {
    // implement partition here
    int middle = medianOfThree(array, left, right);
    T pivot = array.at(middle);

    //swaps the pivot and the middle
    T temp = array.at(middle);
    array.at(middle) = array.at(left);
    array.at(left) = temp;

    int up = left + 1;
    int down = right;

    while (up < down) {
        while (array.at(up) <= pivot && up < right) {
            up++;
        }

        while (array.at(down) > pivot && down > left) {
            down--;
        }

        if (up < down) {
            temp = array.at(down);
            array.at(down) = array.at(up);
            array.at(up) = temp;
        }
    }

    temp = array.at(down);
    array.at(down) = array.at(left);
    array.at(left) = temp;

    //returns the pivot value
    return down;
}

template<class T>
void sort_helper(std::vector<T>& array, int left, int right) {
    if((right-1)-left > 0) {
        int middle = partition(array, left, right);
        sort_helper(array, left, middle-1);
        sort_helper(array, middle+1, right);
        return;
    }
}

template<class T>
void sort(std::vector<T>& array) {
    // implement sort here
    // hint: you'll probably want to make a recursive sort_helper function
    sort_helper(array,0,array.size()-1);
}


