//
// Created by Greg on 12/04/22.
//

#ifndef BINARYSEARCHTREE_TPP
#define BINARYSEARCHTREE_TPP

#include <iostream>
#include "../../include/Tree.h"
#include "../include/BinarySearchTree.h"


template<class T>
BinarySearchTree<T>::BinarySearchTree(const BinarySearchTree<T> &tree) {

}

template<class T>
void BinarySearchTree<T>::create() {
    _root->_ancestor = nullptr;
    _root->_lSon = nullptr;
    _root->_rSon = nullptr;
    _root->value = nullptr;
}

template<class T>
void BinarySearchTree<T>::create(T val) {
    create();
    _root->value = &val;
}

template<class T>
void BinarySearchTree<T>::insertRoot(TreeNode<T>* node) {

}

template<class T>
void BinarySearchTree<T>::insertRightNode(TreeNode<T>* node) {
    TreeNode<T> t(node);
    node->_rSon = &t;
}

template<class T>
void BinarySearchTree<T>::insertLeftNode(TreeNode<T>* node) {
    TreeNode<T> t(node);
    node->_lSon = &t;
}


template<class T>
bool BinarySearchTree<T>::empty() const {
    return _root->_ancestor == nullptr
    && _root->_lSon == nullptr
    && _root->_rSon == nullptr
    && _root->value == nullptr;
}

template<class T>
TreeNode<T> *const BinarySearchTree<T>::root() const {
    return _root;
}

template<class T>
TreeNode<T>* BinarySearchTree<T>::ancestor(TreeNode<T>* node) const {
    return node->_ancestor;
}

template<class T>
TreeNode<T>* BinarySearchTree<T>::getLeftNode(TreeNode<T>* node) const {
    return node->_lSon;
}

template<class T>
TreeNode<T>* BinarySearchTree<T>::getRightNode(TreeNode<T>* node) const {
    return node->_rSon;
}

template<class T>
bool BinarySearchTree<T>::isLeftNodeEmpty(TreeNode<T> node) const {
    return node._lSon == nullptr;
}

template<class T>
bool BinarySearchTree<T>::isRightNodeEmpty(TreeNode<T> node) const {
    return node._rSon == nullptr;
}

template<class T>
void BinarySearchTree<T>::eraseTree(TreeNode<T> node) {

}

template<class T>
T BinarySearchTree<T>::readValue(TreeNode<T> node) const {
    return *(node.value);
}

template<class T>
void BinarySearchTree<T>::writeValue(TreeNode<T>* node, T t) {
    *(node->value) = t;
}

template<class T>
void Tree<T>::printTree() const {

}

template<class T>
void Tree<T>::printSubTree(TDA_Greg::Node<T>) const {

}

#endif