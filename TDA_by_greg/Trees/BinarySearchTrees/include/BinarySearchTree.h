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

    void create() override;
    void create(T);

    // Observers
    bool empty() const override;
    TreeNode<T>* const root() const override;
    TreeNode<T>* ancestor(TreeNode<T>* node) const override;
    TreeNode<T>* getLeftNode(TreeNode<T>* node) const override;
    TreeNode<T>* getRightNode(TreeNode<T>* node) const override;
    bool isLeftNodeEmpty(TreeNode<T> node) const override;
    bool isRightNodeEmpty(TreeNode<T> node) const override;
    T readValue(TreeNode<T> node) const override;

    // Modifiers
    void eraseTree(TreeNode<T> node) override;
    void writeValue(TreeNode<T>* node, T t) override;
    void insertRoot(TreeNode<T>* node) override;
    void insertRightNode(TreeNode<T>* node) override;
    void insertLeftNode(TreeNode<T>* node) override;

    void printTree() const override;

    void preOrder(TreeNode<T>* node) override;
    void inOrder(TreeNode<T>* node) override;
    void postOrder(TreeNode<T>* node) override;

    int depth(TreeNode<T> *root) override;

private:
    TreeNode<T>* _root = new TreeNode<T>();

    void printSubTree(TreeNode<T>* root, std::string prependString) const;
};

#include "../src/BinarySearchTree.tpp"

#endif //BINARYSEARCHTREES_H
