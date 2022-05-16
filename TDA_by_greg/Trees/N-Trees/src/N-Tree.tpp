//
// Created by Greg on 20/04/22.
//

#include <iostream>
#include <string>
#include "../include/N-Tree.h"

using std::cout;
using std::endl;

template<class T>
void N_Tree<T>::create() {
    _root = new TreeNode_v2<T>();
}

template<class T>
bool N_Tree<T>::empty() const {
    return Tree<T>::nodes_inside == 0;
}

template<class T>
void N_Tree<T>::insertRoot(TreeNode_v2<T> *node) {
    assert(empty());
    assert(node->_level == 0);
    _root = node;
}

template<class T>
TreeNode_v2<T>* N_Tree<T>::root() const {
    assert(!empty());
    return _root;
}

template<class T>
TreeNode_v2<T>* N_Tree<T>::ancestor() const {
    assert(!empty());
    assert(_root->_level > 0);

    return _root->_ancestor;
}

template<class T>
TreeNode_v2<T>* N_Tree<T>::firstSon() const {
    assert(!empty());
    assert(!isLeaf());

    return _root->_sons.firstNodeList();
}

template<class T>
bool N_Tree<T>::isLastSibling() const {
    assert(!empty());

    return _root->_sons.isLastPosition();
}

template<class T>
TreeNode_v2<T>* N_Tree<T>::nextSibling() const {
    assert(!empty());

    return _root->_sons.nextPosition(this);
}

template<class T>
void N_Tree<T>::insertFirstTree(N_Tree<T>* tree) {
    assert(!empty());
    assert(!tree->empty());
    _root = tree->root();
}

template<class T>
void N_Tree<T>::insertSubTree(N_Tree<T>* tree) {
    assert(!empty());
    assert(!tree->empty());
    _root->_sons.insertNodeAfter(firstSon(), tree->root() );
}

template<class T>
bool N_Tree<T>::isLeaf() const {
    assert(!empty());
    return _root->isLeaf();
}

template<class T>
bool N_Tree<T>::isLeftNodeEmpty(TreeNode_v2<T> node) const {
    return false;
}

template<class T>
bool N_Tree<T>::isRightNodeEmpty(TreeNode_v2<T> node) const {
    return false;
}

template<class T>
void N_Tree<T>::eraseTree(TreeNode_v2<T> node) {

    //TODO: implement

}

template<class T>
T N_Tree<T>::readValue(TreeNode_v2<T> node) const {
    return node.value;
}

template<class T>
void N_Tree<T>::writeValue(TreeNode_v2<T> *node, T t) {
    node->value = t;
}


template<class T>
TreeNode_v2<T> *N_Tree<T>::getLeftNode(TreeNode_v2<T> *node) const {
    return nullptr;
}

template<class T>
TreeNode_v2<T> *N_Tree<T>::getRightNode(TreeNode_v2<T> *node) const {
    return nullptr;
}

template<class T>
void N_Tree<T>::insertRightNode(TreeNode_v2<T> *node) {

}

template<class T>
void N_Tree<T>::insertLeftNode(TreeNode_v2<T> *node) {

}

template<class T>
void N_Tree<T>::printTree() const {

}

template<class T>
void N_Tree<T>::preOrder(TreeNode_v2<T> *node) {

}

template<class T>
void N_Tree<T>::inOrder(TreeNode_v2<T> *node) {

}

template<class T>
void N_Tree<T>::postOrder(TreeNode_v2<T> *node) {

}

template<class T>
int N_Tree<T>::depth(TreeNode_v2<T> *root) {
    return 0;
}

