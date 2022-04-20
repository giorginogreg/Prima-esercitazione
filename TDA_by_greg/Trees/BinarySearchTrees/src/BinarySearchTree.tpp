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
}

template<class T>
void BinarySearchTree<T>::create(T val) {
    create();
    _root->value = val;
}

template<class T>
void BinarySearchTree<T>::insertRoot(TreeNode<T>* node) {

}

template<class T>
void BinarySearchTree<T>::insertRightNode(TreeNode<T>* node) {
    node->_ancestor = this->_root;
    this->_root->_rSon = node;
}

template<class T>
void BinarySearchTree<T>::insertLeftNode(TreeNode<T>* node) {
    node->_ancestor = this->_root;
    this->_root->_lSon = node;
}

template<class T>
bool BinarySearchTree<T>::empty() const {
    return _root->_ancestor == nullptr
    && _root->_lSon == nullptr
    && _root->_rSon == nullptr;
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
    return node.value;
}

template<class T>
void BinarySearchTree<T>::writeValue(TreeNode<T>* node, T t) {
    node->value = t;
}

template<class T>
void BinarySearchTree<T>::printTree() const {
    printSubTree(_root, "");
}

template<class T>
void BinarySearchTree<T>::printSubTree(TreeNode<T>* root, std::string prependString) const {
    std::cout << prependString;
    std::cout << readValue(*root);
    if(!root->isLeaf()){
        std::cout << std::endl;
        printSubTree(getLeftNode(root),  "├──" );
        printSubTree(getRightNode(root),  "└──" );
    }
}

/**
 * Starting from the root, reach all the leafs
 * While not is leaf, inspect the current node and all the sons.
 * @tparam T
 */
template<class T>
void Tree<T>::preOrder(TreeNode<T>* root) {
    std::cout << readValue(*root);
    std::cout << std::endl;
    if(!root->isLeaf()){
        preOrder(getLeftNode(root));
        preOrder(getRightNode(root));
    }
}

/**
 * Visit all the left nodes first, reaching the leafs.
 * Then visit the node and after the right nodes
 *
 * @tparam T
 * @param root
 */
template<class T>
void Tree<T>::inOrder(TreeNode<T>* root) {
    if(root->isLeaf()) {
        std::cout << readValue(*root);
        std::cout << std::endl;

    } else {
        inOrder(getLeftNode(root));
        std::cout << readValue(*root);
        std::cout << std::endl;

        inOrder(getRightNode(root));
    }

}

/**
 * Mi sposto alla foglia più a dx.
 * Visito tutte le foglie di quel sottoalbero, dopodichè visito il nodo radice del sottoalbero, risalendo.
 * @tparam T
 * @param root
 */
template<class T>
void Tree<T>::postOrder(TreeNode<T>* root) {
    if(root->isLeaf()) {
        std::cout << readValue(*root);
        std::cout << std::endl;

    } else {
        postOrder(getLeftNode(root));
        postOrder(getRightNode(root));
        std::cout << readValue(*root);
        std::cout << std::endl;

    }
}



#endif