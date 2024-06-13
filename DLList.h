#pragma once

#include <iostream>
#include <string>

template<class T>
class DLList {
public:
    // **Important**
    // Normally you would make the Node struct PRIVATE
    // but for this assignment it is important to keep it 
    // PUBLIC
    // Also, the declaration of Node needs to come 
    // before everything else in the class, so leave it here
    // at the beginning.
    struct Node {
        Node* prev;
        Node* next;
        T value;

        Node(T v) : prev(nullptr), next(nullptr), value(v) {}
    };

private:
    int _size;
    Node* _head;
    Node* _tail;
    // Put your private fields/methods here

    void _clear(Node*& ref) {
        if (ref == nullptr) {
            return;
        }
        _clear(ref->next);
        delete ref;
        ref = nullptr;
    }

public:
    DLList() : _size(0), _head(nullptr), _tail(nullptr) {}

    ~DLList() {}

    const Node* get_head() const {
        return _head;
        // implement get_head here
    }

    void push_front(T item) {
        if (_head == nullptr)
        {
            Node* myNode = new Node(item);
            _head = myNode;
            _tail = myNode;
        }
        else
        {
            Node* myNode = new Node(item);
            myNode->next = _head;
            _head->prev = myNode;
            _head = myNode;
        }
        _size++;
        // implement push_front here
    }
    void push_back(T item) {
        if(_tail == nullptr) {
            Node* myNode = new Node(item);
            _head = myNode;
            _tail = myNode;
        }
        else
        {
            Node* myNode = new Node(item);
            myNode->prev = _tail;
            _tail->next = myNode;
            _tail = myNode;
        }
        _size++;
        // implement push_back here
    }
    void insert(T item, int position) {

        if (position > _size) {
            throw std::out_of_range("Out of bounds");
        }

        if (position == 0) {
            push_front(item);
            return;
        }

        if (position == _size) {
            push_back(item);
            return;
        }

        Node* curr = _head;
        for (int i = 0; i < position; i++) {
            curr = curr->next;
        }

        Node* myNode = new Node(item);
        myNode->next = curr;
        myNode->prev = curr->prev;
        curr->prev->next = myNode;
        curr->prev = myNode;

        _size++;
        // implement insert here
    }

    void pop_front() {

        if (_head == nullptr)
        {
            throw std::length_error("List is empty");
        }

        Node* tmp = _head;

        if (_head == _tail) {
            _head = nullptr;
            _tail = nullptr;
        } else {
            _head = tmp->next;
            _head->prev = nullptr;
        }

        delete tmp;
        _size--;
        // implement pop_front here
    }
    void pop_back() {
        if (_head == nullptr)
        {
            throw std::length_error("List is empty");
        }

        Node* tmp = _tail;

        if (_head == _tail) {
            _head = nullptr;
            _tail = nullptr;
        } else {
            _tail = tmp->prev;
            _tail->next = nullptr;
        }

        delete tmp;
        _size--;
        // implement pop_back here
    }
    void remove(int position) {
        if (position > _size - 1 || position < 0)
        {
            throw std::out_of_range(position + " is out of range");
        }

        if (position == 0) {
            pop_front();
            return;
        }

        if (position == _size - 1) {
            pop_back();
            return;
        }

        Node* curr = _head;
        for (int i = 0; i < position; i++) {
            curr = curr->next;
        }

        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
        delete curr;
        curr = nullptr;

        _size--;
        // implement remove here
    }

    const T& front() const {
        if (_head == nullptr)
        {
            throw std::length_error("List is empty");
        }

        return _head->value;
        // implement front here
    }
    const T& back() const {
        if (_tail == nullptr)
        {
            throw std::length_error("List is empty");
        }

        return _tail->value;
        // implement back here
    }
    const T& at(int index) const {

        if (index > _size - 1) {
            throw std::out_of_range("Index is out of range");
        }

        Node* curr = _head;
        for (int i = 0; i < index; i++) {
            curr = curr->next;
        }

        return curr->value;
        // implement at here
    }

    bool contains(const T& item) const {
        Node* curr = _head;
        for (int i = 0; i < _size; i++) {
            if (curr->value == item){
                return true;
            }
            curr = curr->next;
        }
        return false;
        // implement contains here
    }

    int size() const {
        return _size;
        // implement size here
    }

    void clear() {
        _clear(_head);
        _size = 0;
        // implement clear here
    }
};
