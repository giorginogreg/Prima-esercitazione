//
// Created by Greg on 12/04/22.
//

#ifndef BINARYSEARCHTREES_H
#define BINARYSEARCHTREES_H

/**
 * Per ogni nodo N, tutti gli elementi contenuti nel sottoalbero radicato nel figlio sx di N sono minori di N.value
 * Per ogni nodo N, tutti gli elementi contenuti nel sottoalbero radicato nel figlio DX di N sono maggiori di N.value
 */

#include "../../../include/Node.h"
#include "../../include/Tree.h"




template <class T>
class BinarySearchTree: public Tree<T> {

public:
    virtual void create();

    // Observers
    bool empty() const;
    virtual TreeNode<T> root() const;
    virtual TreeNode<T> ancestor(TreeNode<T> node) const;
    virtual TreeNode<T> getLeftNode(TreeNode<T> node) const;
    virtual TreeNode<T> getRightNode(TreeNode<T> node) const;
    virtual bool isLeftNodeEmpty(TreeNode<T> node) const;
    virtual bool isRightNodeEmpty(TreeNode<T> node) const;
    virtual T readValue(TreeNode<T> node) const;

    // Modifiers
    virtual void eraseTree(TreeNode<T> node);
    virtual void writeValue(TreeNode<T> &node, T t);
    virtual void insertRoot(TreeNode<T> node);
    virtual void insertRightNode(TreeNode<T>* node);
    virtual void insertLeftNode(TreeNode<T>* node);

private:
    TreeNode<T> _root;

};



#endif //BINARYSEARCHTREES_H
