#include <linked_list.hpp>

template<class T>
LinkedListNode<T>::LinkedListNode(T value, LinkedListNode<T>* next, LinkedListNode<T>* prev) {
    this->value = value;
    this->next = next;
    this->prev = prev;
}

template<class T>
LinkedListNode<T>::~LinkedListNode() {
    delete(this->next);
    //this->next = NULL; // come back to this...
}


template<class T>
LinkedList<T>::LinkedList() {
     this->root = NULL;
     this->length = 0;
}

template<class T>
LinkedList<T>::~LinkedList() {
    // YOUR CODE HERE
    delete(this->root)
    // END OF YOUR CODE
}


template<class T>
LinkedListNode<T>* LinkedList<T>::insert(T value) {
    // YOUR CODE HERE
    currentNode = this->root; //possible edge case when length = 0
    while (!currentNode){
        if (currentNode->value == value) { //prob can't use this lmao, will get back to it
            return currentNode; //return pointer to node that already exists
        } else if (!currentNode->next) {
            LinkedListNode* node = new LinkedListNode(value, nullptr, &currentNode)
            this->length++;
            return &node;
        } else {
            currentNode = currentNode->next;
            std::cout << "switch to next node" << std::endl;
        }
    }

    if(currentNode == nullptr){
        LinkedListNode* node = new LinkedListNode(value, nullptr, &currentNode)
        this->length++;
        return &node;
    }

    std::cout << "oh shit 1" << std::endl;
    return nullptr;
    
    // END OF YOUR CODE
}

template<class T>
LinkedListNode<T>* LinkedList<T>::find(T value) {
    // YOUR CODE HERE
    currentNode = this->root;
    while (!currentNode){
        if (currentNode->value == value){
            return currentNode;
        } else {
            currentNode = currentNode->next;
        }
    }

    return nullptr;
    // END OF YOUR CODE
}

template<class T>
LinkedListNode<T>* LinkedList<T>::remove(T value) {
    // YOUR CODE HERE
    currentNode = this->root;
    while(!currentNode){
        if (currentNode->value == value){
            if(currentNode->next != nullptr){
                nextNode = currentNode->next;
                prevNode = currentNode->prev;
                prevNode->next = nextNode;
                nextNode->prev = prevNode;
                currentNode->next = nullptr;
                currentNode->prev = nullptr;
                delete(currentNode)
                this->length--;
            } else {
                if(currentNode->prev != prev){
                    prevNode = currentNode->prev;
                    prevNode->next = nullptr;
                    currentNode->prev = nullptr;
                    delete(currentNode)
                    this->length--;
                } else { //only this value is in the linked list, so remove it and linkedlist empty
                    this->root = nullptr;
                    delete(currentNode)
                    this->length--;
                }
                
            }
        } else {
            currentNode = currentNode->next;
        }
    }

    return this->root;
    // END OF YOUR CODE
}

template<class T>
int LinkedList<T>::size() {
    // YOUR CODE HERE 
    return this->length;
    // END OF YOUR CODE
}

template class LinkedListNode<int>;
template class LinkedList<int>;
