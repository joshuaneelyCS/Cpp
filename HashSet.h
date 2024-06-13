#pragma once

#include <iostream>

#include <functional>
using std::hash;

#include <list>
using std::list;

template<class T>

class HashSet {

    hash<T> hashFunction;
    const double _factor = 0.8;
    int _size;
    int _capacity;
    list<T>* _buckets;

    void _grow() {
        int oldCapactiy = _capacity;
        _capacity*=2;
        list<T>* oldBuckets = _buckets;
        _buckets = new list<T>[_capacity];

        for (int i = 0; i < oldCapactiy; i++) {
            list<T> &myList = oldBuckets[i];
            for (T const &item : myList) {
                list<T> &bucket = _getBucket(item);
                bucket.push_back(item);
            }
        }
        delete[] oldBuckets;
    }

    list<T>& _getBucket (T const &item) {
        int hashcode = hashFunction(item);
        int position = hashcode % _capacity;
        return _buckets[std::abs(position)];
    }

    bool _contains(T const& item, list<T> const& bucket) const {
        if (bucket.size() == 0) {
            return false;
        }
        for (T const& value : bucket) {
            if (item == value) {
                return true;
            }
        }
        return false;
    }

public:
    HashSet() : _size(0), _capacity(10), _buckets(new list<T>[_capacity]) { }

    ~HashSet() {
        delete[] _buckets;
    }

    bool insert(T item) {
        if (_capacity*_factor < _size) {
            _grow();
        }
        list<T> &bucket = _getBucket(item);
        if (_contains(item, bucket)) {
            return false;
        }
        bucket.push_back(item);
        _size++;
        return true;
    }


    bool remove(T item) {
        list<T>& bucket = _getBucket(item);
        if (_contains(item, bucket)){
            bucket.remove(item);
            _size--;
            return true;
        }
        return false;

        // implement remove here
        // return true if item was removed, false if item wasn't in the set
    }

    bool contains(T item) const {
        int hashcode = hashFunction(item);
        int position = hashcode % _capacity;
        list<T> &bucket = _buckets[std::abs(position)];
        return _contains(item, bucket);
        // implement contains here
        // return true if item is in the set, false otherwise
    }

    void clear() {
        for (int i = 0; i < _capacity; i++) {
            _buckets[i].clear();
        }
        _size = 0;
        // implement clear here
        // remove all elements from the set
    }

    int size() const {
        // implement size here
        // return the number of elements in the set
        return _size;
    }
};
