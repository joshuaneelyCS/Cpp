#pragma once

#include <iostream>

#include <string>

template<class T>
class Vector {

    int _size;
    int _capacity;
    T* _array;

    void _grow() {
        T* tmp = _array;
        size_t old = _capacity;
        _capacity *= 2;
        _array = new T[_capacity];
        for (size_t i = 0; i < old; i++){
            _array[i] = tmp[i];
        }
        delete[] tmp;
    }

public:
    Vector() : _size(0), _capacity(10), _array(new T[_capacity]){}

    ~Vector() {delete[] _array;}

    void push_back(T item) {
        // implement push_back here
        if (_size == _capacity) { _grow(); }
        _array[_size++] = item;
    }

    void insert(T item, int position) {
        if (position > _size || position < 0) { //try insert at size
            throw std::out_of_range("Index out of range");
        }
        if (_capacity == _size) { _grow(); }
        for (int i = _size; i > position; i--) {
            _array[i] = _array[i-1];
        }
        _array[position] = item;
        _size++;
        // implement insert here
    }

    void remove(int position) {
        //out of range error
        if (position > _size - 1 || position < 0) { //try insert at size
            throw std::out_of_range("Index out of range");
        }
        for (int i = position; i < _size - 1; i++) {
            _array[i] = _array[i+1];
        }
        _size--;
        // implement remove here
    }

    T& operator[](int index) {
        if (index > _size - 1 || index < 0) { //try insert at size
            throw std::out_of_range("Index out of range");
        }
        return _array[index];
        // implement operator[] here
    }

    int size() const {
        return _size;
        // implement size here
    }

    void clear() {
        _size = 0;
        // implement clear here
    }
};
