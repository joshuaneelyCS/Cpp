#pragma once

#include <vector>
#include <set>
#include <algorithm>


template<class T>
class VectorSet {
    std::vector<T> myvector;
public:

    VectorSet() {}

    bool contains(T item) const {
        // implement contains here
        return (std::find(myvector.begin(), myvector.end(), item) != myvector.end());
        // return true if item is in the set and false if not
    }

    bool insert(T item) {
        // implement insert here
        for(int i = 0; i < myvector.size(); i++)
            if (item == myvector[i]) {
                return false;
            }
        myvector.push_back(item);
        return true;
        // return true if item is inserted and false if item is already in the
        // set
    }

    bool remove(T item) {
        // implement remove here
        auto iterator = std::find(myvector.begin(), myvector.end(), item);
        if (iterator != myvector.end()) {
            myvector.erase(iterator);
            return true;
        }
        return false;
        // return true if item is removed and false if item wasn't in the set
    }

    int size() const {
        // implement size here
        return myvector.size();
        // return the number of items in the set
    }

    bool empty() const {
        // implement empty here
        if (myvector.empty()) {
            return true;
        }
        return false;
        // return true if the set is empty and return false otherwise
    }

    void clear() {
        // implement clear here
        myvector.clear();
        // remove all items from the set
    }
};
