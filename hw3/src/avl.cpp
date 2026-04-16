#include <avl.hpp>

//needed to add this so my stuff will work :)
#include <algorithm>

template<class T>
int AVL<T>::getHeight(BSTNode<T> *node) {
    return (node == NULL) ? -1 : node->height;
}

template<class T>
int AVL<T>::getBalance(BSTNode<T> *node) {
    return (node == NULL) ? 0 : getHeight(node->left) - getHeight(node->right);
}

template<class T>
BSTNode<T> *AVL<T>::rotateRight(BSTNode<T> *y) {
    // YOUR CODE HERE
    BSTNode<T>* x = y->left;
    BSTNode<T>* t2 = x->right;

    // rotation
    x->right = y;
    y->left = t2;

    // update heights
    y->height = 1 + std::max(getHeight(y->left), getHeight(y->right));
    x->height = 1 + std::max(getHeight(x->left), getHeight(x->right));

    return x;
    //return nullptr; // Placeholder
}

template<class T>
BSTNode<T> *AVL<T>::rotateLeft(BSTNode<T> *x) {
    // YOUR CODE HERE
    BSTNode<T>* y = x->right;
    BSTNode<T>* t2 = y->left;

    // rotation
    y->left = x;
    x->right = t2;

    // update heights
    x->height = 1 + std::max(getHeight(x->left), getHeight(x->right));
    y->height = 1 + std::max(getHeight(y->left), getHeight(y->right));

    return y;
    //return nullptr; // Placeholder
}

template<class T>
BSTNode<T> *AVL<T>::insert(T key, BSTNode<T> *node) {
    // YOUR CODE HERE
    if (node == nullptr) {
        return new BSTNode<T>(key, 0, nullptr, nullptr);
    }

    if (key < node->key) {
        node->left = insert(key, node->left);
    }
    else if (key > node->key) {
        node->right = insert(key, node->right);
    }
    else {
        return node; // no duplicates
    }

    // update height
    node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));

    // get balance
    int balance = getBalance(node);

    // LL
    if (balance > 1 && key < node->left->key) {
        return rotateRight(node);
    }

    // RR
    if (balance < -1 && key > node->right->key) {
        return rotateLeft(node);
    }

    // LR
    if (balance > 1 && key > node->left->key) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    // RL
    if (balance < -1 && key < node->right->key) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node; // Placeholder
}


template<class T>
BSTNode<T> *AVL<T>::remove(T key, BSTNode<T> *node) {
    // YOUR CODE HERE
    if (node == nullptr) return nullptr;

    // standard BST remove
    if (key < node->key) {
        node->left = remove(key, node->left);
    }
    else if (key > node->key) {
        node->right = remove(key, node->right);
    }
    else {
        // no child
        if (node->left == nullptr && node->right == nullptr) {
            delete node;
            return nullptr;
        }
        // one child
        else if (node->left == nullptr) {
            BSTNode<T>* temp = node->right;
            delete node;
            return temp;
        }
        else if (node->right == nullptr) {
            BSTNode<T>* temp = node->left;
            delete node;
            return temp;
        }
        // two children
        else {
            BSTNode<T>* temp = this->findMinimum(node->right);
            node->key = temp->key;
            node->right = remove(temp->key, node->right);
        }
    }

    // update height
    node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));

    // get balance
    int balance = getBalance(node);

    // LL
    if (balance > 1 && getBalance(node->left) >= 0) {
        return rotateRight(node);
    }

    // LR
    if (balance > 1 && getBalance(node->left) < 0) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    // RR
    if (balance < -1 && getBalance(node->right) <= 0) {
        return rotateLeft(node);
    }

    // RL
    if (balance < -1 && getBalance(node->right) > 0) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node; // Placeholder
}

template<class T>
BSTNode<T> *AVL<T>::insert(T key) { return this->root = insert(key, this->root); }

template<class T>
BSTNode<T> *AVL<T>::remove(T key) { return this->root = remove(key, this->root); }

template class AVL<int>;
template class AVL<std::pair<int, int>>;