#include <bst.hpp>

template<class T>
BSTNode<T>::BSTNode() {
    this->left = this->right = NULL;
    this->height = 0;
}

template<class T>
BSTNode<T>::BSTNode(T key, int height, BSTNode *left, BSTNode *right) {
    this->key = key;
    this->height = height;
    this->left = left;
    this->right = right;
}

template<class T>
BSTNode<T>::~BSTNode() {
    this->left = this->right = NULL;
}

template<class T>
BST<T>::BST() { this->root = NULL; }

template<class T>
BST<T>::~BST() { this->clear(this->root); }

template<class T>
void BST<T>::clear(BSTNode<T> *node) {
    // YOUR CODE HERE
<<<<<<< HEAD
    if (node == nullptr) return;

    clear(node->left);
    clear(node->right);
    delete node;
=======
>>>>>>> ec8c6336c37716261a571477eaca8255d0116b11
}

template<class T>
BSTNode<T> *BST<T>::find(T key, BSTNode<T> *node) {
    // YOUR CODE HERE
<<<<<<< HEAD

    BSTNode<T>* current = node;
    while(current != nullptr){
        if(current->key == key){
            return current;
        } else if (current->key < key){
            current = current->right;
        } else {
            current = current->left;
        }
    }
    return nullptr;
    //return nullptr; // Placeholder
=======
    return nullptr; // Placeholder
>>>>>>> ec8c6336c37716261a571477eaca8255d0116b11
}


template<class T>
BSTNode<T> *BST<T>::findMaximum(BSTNode<T> *node) {
    // YOUR CODE HERE
<<<<<<< HEAD
    if (node == nullptr){
        return nullptr;
    }

    //to find max, just keep going right till null
    BSTNode<T>* current = node;
    while(current->right != nullptr){
        current = current->right;
    }

    return current;
    //return nullptr; // Placeholder
=======
    return nullptr; // Placeholder
>>>>>>> ec8c6336c37716261a571477eaca8255d0116b11
}


template<class T>
BSTNode<T> *BST<T>::findMinimum(BSTNode<T> *node) {
    // YOUR CODE HERE
<<<<<<< HEAD
    if (node == nullptr){
        return nullptr;
    }

    //to find min, just keep going left till null
    BSTNode<T>* current = node;
    while(current->left != nullptr){
        current = current->left;
    }

    return current;
    //return nullptr; // Placeholder
=======
    return nullptr; // Placeholder
>>>>>>> ec8c6336c37716261a571477eaca8255d0116b11
}


template<class T>
BSTNode<T> *BST<T>::insert(T key, BSTNode<T> *node) {
    // YOUR CODE HERE
<<<<<<< HEAD
    if (node == nullptr) {
        return new BSTNode<T>(key, 0, nullptr, nullptr);
    }

    if (key < node->key) {
        node->left = insert(key, node->left);
    }
    else if (key > node->key) {
        node->right = insert(key, node->right);
    }

    return node;
=======
    return nullptr; // Placeholder
>>>>>>> ec8c6336c37716261a571477eaca8255d0116b11
}

template<class T>
BSTNode<T> *BST<T>::remove(T key, BSTNode<T> *node) {
    // YOUR CODE HERE
<<<<<<< HEAD
    if (node == nullptr) return nullptr;

    if (key < node->key) {
        node->left = remove(key, node->left);
    }
    else if (key > node->key) {
        node->right = remove(key, node->right);
    }
    else {
        //no children
        if (node->left == nullptr && node->right == nullptr) {
            delete node;
            return nullptr;
        }

        //one child
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

        //two children
        else {
            BSTNode<T>* temp = findMinimum(node->right);
            node->key = temp->key;
            node->right = remove(temp->key, node->right);
        }
    }

    return node;
=======
    return nullptr; // Placeholder
>>>>>>> ec8c6336c37716261a571477eaca8255d0116b11
}


template<class T>
BSTNode<T> *BST<T>::find(T key) { return find(key, root); }

template<class T>
BSTNode<T> *BST<T>::findMaximum() { return findMaximum(root); }

template<class T>
BSTNode<T> *BST<T>::findMinimum() { return findMinimum(root); }

template<class T>
BSTNode<T> *BST<T>::insert(T key) { return root = insert(key, root); }

template<class T>
BSTNode<T> *BST<T>::remove(T key) { return root = remove(key, root); }

template class BST<int>;
template class BST<std::pair<int, int>>;