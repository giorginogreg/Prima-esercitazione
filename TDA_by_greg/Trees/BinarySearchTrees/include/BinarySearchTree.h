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

    BinarySearchTree<T>() { create(); }
    BinarySearchTree<T>(T val) { create(val); }
    BinarySearchTree<T>(const BinarySearchTree<T> &tree);

    virtual ~BinarySearchTree() = default;

    void create();
    void create(T);

    // Observers
    bool empty() const;
    TreeNode<T>* const root() const;
    TreeNode<T>* ancestor(TreeNode<T>* node) const;
    TreeNode<T>* getLeftNode(TreeNode<T>* node) const;
    TreeNode<T>* getRightNode(TreeNode<T>* node) const;
    bool isLeftNodeEmpty(TreeNode<T> node) const;
    bool isRightNodeEmpty(TreeNode<T> node) const;
    T readValue(TreeNode<T> node) const;

    // Modifiers
    void eraseTree(TreeNode<T> node);
    void writeValue(TreeNode<T>* node, T t);
    void insertRoot(TreeNode<T>* node);
    void insertRightNode(TreeNode<T>* node);
    void insertLeftNode(TreeNode<T>* node);

    void printTree() const;

    void preOrder(TreeNode<T>* node) ;
    void inOrder(TreeNode<T>* node) ;
    void postOrder(TreeNode<T>* node) ;

    int depth(TreeNode<T> *root) override;

private:
    TreeNode<T>* _root = new TreeNode<T>();

    void printSubTree(TreeNode<T>* root, std::string prependString) const;
};

#include "../src/BinarySearchTree.tpp"

#endif //BINARYSEARCHTREES_H
