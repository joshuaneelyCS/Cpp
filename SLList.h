#pragma once

template <class T>
class SLList {
public:
    struct Node {
        Node* next;
        T value;

        Node(T v) : next(nullptr), value(v) {}
    };

    Node* _head;
    int _size;

    void _clear()  {
        Node* iter = _head;
        for (int i = 0; i < _size - 1; i++) {
            Node* tmp = iter->next;
            delete[] iter;
            iter = tmp;
        }
        _size=0;
    }

    Node* _iterate(int pos) {
        Node* iter = _head;
        for (int i = 0; i < pos; i++) {
            iter=iter->next;
        }
        return iter;
    }

    SLList() : _head(nullptr), _size(0) {}

    ~SLList() {
        _clear();
    }

    const Node* get_head() const {
        return _head;
        // implement get_head here
    }

    void push_back(T item) {
        // implement push_back here
        Node* myNode = new Node(item);
        if (_head == nullptr) {
            _head=myNode;
            _size++;
            return;
        }

        Node* iter = _iterate(_size-1);

        iter->next = myNode;
        _size++;
    }

    void pop_back() {
        
        if (_size==1) {
            _head=nullptr;
            _size--;
            return;
        }

        Node* iter = _iterate(_size-2);

        iter->next = nullptr;
        _size--;
        // implement pop_back here
    }

    const T& front() const {
        return _head->value;
        // implement front here
    }

    int size() const {
        return _size;
        // implement size here
    }

    void clear() {
        _clear();
        // implement clear here
    }
};
