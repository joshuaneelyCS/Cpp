#pragma once

template<class T>
class BST {

    bool _insert(T item){
        Node* curr = root;
        while (curr != nullptr) {
            if (curr->value == item) { return false; }
            else if (curr->right != nullptr && item > curr->value) {
                curr = curr->right;
            } else if (curr->left != nullptr && item < curr->value) {
                curr = curr->left;
            } else if (curr->right == nullptr && item > curr->value) {
                curr->right = new Node(item);
                _size++;
                return true;
            } else if (curr->left == nullptr && item < curr->value) {
                curr->left = new Node(item);
                _size++;
                return true;
            }
        }
    }


    bool _remove(T item) {

        Node* curr = root;
        bool found = false;

        // I tried to wrap this in a separate function, but it did not work
        while (true) {
            if (curr->right != nullptr && item > curr->value) {
                if(curr->right->value == item) {
                    found = true;
                    break;
                }
                curr = curr->right;
            } else if (curr->left != nullptr && item < curr->value) {
                if(curr->left->value == item) {
                    found = true;
                    break;
                }
                curr = curr->left;
            } else if (curr->right == nullptr && item > curr->value) {
                break;
            } else if (curr->left == nullptr && item < curr->value) {
                break;
            } else if (curr->value == item) {
                found = true;
                break;
            }
        }
        if (found == false) {
            return false;
        }
        if (curr == nullptr) {
            return false;
        } else {
            Node* parent = curr;

            if (item > parent->value) {
                curr=curr->right;
                if (!has_children(curr)) {
                    delete[] curr;
                    parent->right = nullptr;
                    return true;
                }

                Node* replace = curr->left;
                if (replace == nullptr) {
                    parent->right = curr->right;
                    delete[] curr;
                    _size--;
                    return true;
                }
                while (replace->right->right != nullptr) {
                    replace=replace->right;
                }

                parent->right = replace->right;
                replace->right->right = curr->right;
                replace->right = replace->right->left;
                parent->right->left = replace;

                delete[] curr;
                _size--;
                return true;
            }

            else if (item < parent->value) {
                curr=curr->left;
                if (!has_children(curr)) {
                    delete[] curr;
                    parent->left = nullptr;
                    return true;
                }

                Node* replace = curr->right;
                if (replace == nullptr) {
                    parent->left = curr->left;
                    delete[] curr;
                    _size--;
                    return true;
                }
                while (replace->left->left != nullptr) {
                    replace=replace->left;
                }

                parent->left = replace->left;
                replace->left->left = curr->left;
                replace->left = replace->left->right;
                parent->left->right = replace;

                delete[] curr;
                _size--;
                return true;

            } else if (item == parent->value) {
                if (!has_children(curr)) {
                    root = nullptr;
                    delete[] curr;
                    _size--;
                    return true;
                }
                if (curr->right == nullptr) {
                    root = curr->left;
                    delete[] curr;
                    _size--;
                    return true;
                } else if (curr->left == nullptr) {
                    root = curr->right;
                    delete[] curr;
                    _size--;
                    return true;
                }


                curr=curr->left;
                if (!has_children(curr)) {
                    curr->right = parent->right;
                    root = curr;
                    delete[] parent;
                    _size--;
                    return true;
                }

                Node* replace = curr;
                if (replace->right == nullptr) {
                    curr->right = parent->right;
                    root = curr;
                    delete[] parent;
                    _size--;
                    return true;
                }

                while (replace->right->right != nullptr) {
                    replace=replace->right;
                }

                replace->right->left = curr;
                replace->right->right = parent->right;
                root = replace->right;
                replace->right = nullptr;

                delete[] parent;
                _size--;
                return true;

            }
        }

    }

    bool _contains(T item) const {
        Node* curr = root;
        while (curr != nullptr) {
            if (curr->value == item) { return true; }
            else if (curr->right != nullptr && item > curr->value) {
                curr = curr->right;
            } else if (curr->left != nullptr && item < curr->value) {
                curr = curr->left;
            } else if (curr->right == nullptr && item > curr->value) {
                return false;
            } else if (curr->left == nullptr && item < curr->value) {
                return false;
            }
        }
    }



public:
    struct Node {
        Node* left;
        Node* right;
        T value;

        Node(T v) : left(nullptr), right(nullptr), value(v) {}
    };

    Node* root;
    int _size;

    bool has_children(Node* curr) {
        if (curr->right == nullptr && curr->left == nullptr) {
            return false;
        }
        return true;
    }

    BST() : root(nullptr), _size(0) {
        // implement the contructor here

    }

    ~BST() {
        _clear(root);
        // implement the destructor here
    }

    const Node* getRootNode() const {
        // implement getRootNode here
        return root;
        // return a pointer to the tree's root node
    }

    void _clear(Node* curr) {
        if (curr == nullptr) {
            return;
        }
        _clear(curr->right);
        _clear(curr->left);
        delete[] curr;
    }

    bool insert(T item) {
        if (root == nullptr) {
            root = new Node(item);
            _size++;
            return true;
        } else {
            return _insert(item);
        }
        // implement insert here
        // return true if item was inserted, false if item was already in the tree
    }

    bool remove(T item) {
        if (root == nullptr) {
            return false;
            //throw error
        }
        return _remove(item);
        // implement remove here
        // return true if item was removed, false if item wasn't in the tree
    }

    bool contains(T item) const {
        // implement contains here
        if (root == nullptr) {

        }
        return _contains(item);
        // return true if item is in the tree, false otherwise
    }

    void clear() {
        _clear(root->right);
        _clear(root->left);
        root = nullptr;
        _size = 0;

        // implement clear here
        // remove all nodes from the tree
    }

    int size() const {
        return _size;
        // implement size here
        // return the number of nodes in the tree
    }
};
