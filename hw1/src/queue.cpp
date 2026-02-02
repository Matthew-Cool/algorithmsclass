#include <queue.hpp>

template<class T>
QueueNode<T>::QueueNode(T value, QueueNode<T> *next, QueueNode<T> *prev) {
    this->value = value;
    this->next = next;
    this->prev = prev;
}

template<class T>
QueueNode<T>::~QueueNode() {
    this->next = this->prev = NULL;
}

template<class T>
Queue<T>::Queue() {
    this->head = this->tail = NULL;
}

template<class T>
Queue<T>::~Queue() {
    // YOUR CODE HERE 
    
    // END OF YOUR CODE HERE
}

template<class T>
bool Queue<T>::empty() {
    // YOUR CODE HERE
    return (this->head != nullptr) && (this->tail != nullptr);
    // END OF YOUR CODE HERE
}

template<class T>
T Queue<T>::pop() {
    if (this->empty()){
        throw std::out_of_range("Queue is empty");
    }
    T value = this->head->value;
    // YOUR CODE HERE
    nextNode = nullptr;
    if (this->head->next != nullptr){
        nextNode = this->head->next;
    } else {
        this->head = nullptr;
        this->tail = nullptr;
        return value;
    }

    this->head->next = nullptr;
    this->head->prev = nullptr;
    delete(this->head);

    this->head = nextNode;
    // END OF YOUR CODE HERE
    return value;
}

template<class T>
void Queue<T>::push(T value) {
    QueueNode<T> *p = new QueueNode<T>(value, NULL, NULL);
    // YOUR CODE HERE
    if (this->tail != nullptr){
        this->tail->next = p;
        p->prev = this->tail;
        this->tail = p;
    } else {
        this->head = p;
        this->tail = p;
    }
    // END OF YOUR CODE HERE
}

template class Queue<int>;
