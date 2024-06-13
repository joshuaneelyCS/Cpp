#pragma once

struct Node {
    Node* left;
    Node* right;
    int value;
    int height;

    Node(int v) : left(nullptr), right(nullptr), value(v), height(1) {}
};

// Hint: you might find it helpful to write an update_height function that takes
// a Node* and updates its height field based on the heights of its children

void update_height(Node* & root) {
    if (root->left == nullptr && root->right == nullptr) {
        root->height = 1;
    }
    else if (root->left == nullptr) {
        root->height = root->right->height + 1;
    }
    else if (root->right == nullptr) {
        root->height = root->left->height + 1;
    }
    else if (root->left->height < root->right->height) {
        root->height = root->right->height + 1;
    }
    else if (root->left->height > root->right->height) {
        root->height = root->left->height + 1;

    } else if (root->left->height == root->right->height) {
        root->height = root->left->height + 1;
    }
}

void promote_left(Node*& root) {
    // implement promote_left here
    Node* tmp = root->left;
    root->left = root->left->right;
    tmp->right = root;
    root = tmp;
    update_height(root->right);
    update_height(root);
}

void promote_right(Node*& root) {
    // implement promote_right here
    Node* tmp = root->right;
    root->right = root->right->left;
    tmp->left = root;
    root = tmp;
    update_height(root->left);
    update_height(root);
}

int calc_balance(Node* root) {
    if (root->left == nullptr && root->right == nullptr) {
        return 0;
    } else if (root->left == nullptr) {
        return root->right->height;
    } else if (root->right == nullptr) {
        return -1 * (root->left->height);
    }
    return root->right->height - root->left->height;
}

void rebalance(Node*& root) {
    // implement rebalance here
    //std::cout << root->value << "\n";
    if (root->left == nullptr && root->right == nullptr) {
       // std::cout << "both are empty\n";
        update_height(root);
       // std::cout << root->value << "'s height: " << root->height << " returned\n";
        return;
    } else if (root->left == nullptr) {
        //std::cout << "left it empty\n";
        rebalance(root->right);
        update_height(root);

        if (calc_balance(root) > 1 ) {
            if (calc_balance(root->right) < 0) {
                promote_left(root->right);
            }
            promote_right(root);
        }
        //std::cout << root->value << " returned\n";
        return;

    } else if (root->right == nullptr) {
        //std::cout << "right it empty\n";
        rebalance(root->left);
        update_height(root);
        //std::cout << root->value << "'s height: " << root->height << " returned\n";
        if (calc_balance(root) < -1 ) {
            //std::cout << "got passed first";
            if (calc_balance(root->left) > 0) {
                //std::cout << "got passed second";
                promote_right(root->left);
            }
            promote_left(root);
        }
        //std::cout << root->value << " returned\n";
        return;
    }

   // std::cout << "Both are not empty\n";
    rebalance(root->right);
    rebalance(root->left);

    if (calc_balance(root) > 1) {
        if(calc_balance(root->right) < 0) {
            promote_left(root->right);
        }
        promote_right(root);
    } else if (calc_balance(root) < -1) {
        if(calc_balance(root->left) > 0) {
            promote_right(root->left);
        }
        promote_left(root);
    }
   // update_height(root);


}
