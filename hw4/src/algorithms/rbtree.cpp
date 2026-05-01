#include "rbtree.hpp"
#include <iostream>

void RedBlackTree::rotateLeft(RBNode *&root, RBNode *&ptr) {
    // YOUR CODE HERE
    RBNode* ptr_right = ptr->right;
    ptr->right = ptr_right->left;

    if (ptr->right != nullptr) {
        ptr->right->parent = ptr;
    }

    ptr_right->parent = ptr->parent;

    if (ptr->parent == nullptr) {
        root = ptr_right;
    } else if (ptr == ptr->parent->left) {
        ptr->parent->left = ptr_right;
    } else {
        ptr->parent->right = ptr_right;
    }

    ptr_right->left = ptr;
    ptr->parent = ptr_right;
}

void RedBlackTree::rotateRight(RBNode *&root, RBNode *&ptr) {
    // YOUR CODE HERE
    RBNode* ptr_left = ptr->left;
    ptr->left = ptr_left->right;

    if (ptr->left != nullptr) {
        ptr->left->parent = ptr;
    }

    ptr_left->parent = ptr->parent;

    if (ptr->parent == nullptr) {
        root = ptr_left;
    } else if (ptr == ptr->parent->left) {
        ptr->parent->left = ptr_left;
    } else {
        ptr->parent->right = ptr_left;
    }

    ptr_left->right = ptr;
    ptr->parent = ptr_left;
}

void RedBlackTree::fixViolation(RBNode *&root, RBNode *&ptr) {
    // YOUR CODE HERE
    while (ptr != root && ptr->parent != nullptr && ptr->parent->color == RED) {
        RBNode* parent_pt = ptr->parent;
        RBNode* grand_parent_pt = parent_pt->parent;

        if (grand_parent_pt == nullptr) break;

        //parent is left child of grandparent
        if (parent_pt == grand_parent_pt->left) {
            RBNode* uncle_pt = grand_parent_pt->right;

            //uncle is red
            if (uncle_pt != nullptr && uncle_pt->color == RED) {
                grand_parent_pt->color = RED;
                parent_pt->color = BLACK;
                uncle_pt->color = BLACK;
                ptr = grand_parent_pt;
            } else {
                //triangle
                if (ptr == parent_pt->right) {
                    rotateLeft(root, parent_pt);
                    ptr = parent_pt;
                    parent_pt = ptr->parent;
                }

                //line
                rotateRight(root, grand_parent_pt);
                std::swap(parent_pt->color, grand_parent_pt->color);
                ptr = parent_pt;
            }
        }
        //parent is right child of grandparent
        else {
            RBNode* uncle_pt = grand_parent_pt->left;

            //uncle is red
            if (uncle_pt != nullptr && uncle_pt->color == RED) {
                grand_parent_pt->color = RED;
                parent_pt->color = BLACK;
                uncle_pt->color = BLACK;
                ptr = grand_parent_pt;
            } else {
                //triangle
                if (ptr == parent_pt->left) {
                    rotateRight(root, parent_pt);
                    ptr = parent_pt;
                    parent_pt = ptr->parent;
                }

                //line
                rotateLeft(root, grand_parent_pt);
                std::swap(parent_pt->color, grand_parent_pt->color);
                ptr = parent_pt;
            }
        }
    }

    root->color = BLACK;
}

void RedBlackTree::insert(const int &data, int x, int y) {
    // YOUR CODE HERE
    RBNode* ptr = new RBNode(data, x, y);
    ptr->left = nullptr;
    ptr->right = nullptr;
    ptr->parent = nullptr;
    ptr->color = RED;

    RBNode* parent = nullptr;
    RBNode* curr = root;

    while (curr != nullptr) {
        parent = curr;
        if (ptr->data < curr->data) {
            curr = curr->left;
        } else {
            curr = curr->right;
        }
    }

    ptr->parent = parent;

    if (parent == nullptr) {
        root = ptr;
    } else if (ptr->data < parent->data) {
        parent->left = ptr;
    } else {
        parent->right = ptr;
    }

    fixViolation(root, ptr);
}

RBNode* RedBlackTree::search(int data) {
    RBNode *temp = root;
    while (temp != nullptr) {
        if (data == temp->data) return temp;
        if (data < temp->data) temp = temp->left;
        else temp = temp->right;
    }
    return nullptr;
}