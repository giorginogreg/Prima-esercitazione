//
// Created by Greg on 20/04/22.
//

#ifndef BINARYSEARCHTREES_N_TREE_H
#define BINARYSEARCHTREES_N_TREE_H

#include "../../include/Tree_v2.h"

template <class T>
class N_Tree: public Tree<T> {

public:

    void create();
    bool empty() const;
    void insertRoot(TreeNode_v2<T> *node);
    TreeNode_v2<T>* root() const;
    TreeNode_v2<T>* ancestor() const;
    bool isLeaf() const;
    TreeNode_v2<T>* firstSon() const;
    bool isLastSibling() const;
    TreeNode_v2<T>* nextSibling() const;

    void insertFirstTree(N_Tree<T>* tree);
    void insertSubTree(N_Tree<T>* tree);

    TreeNode_v2<T> *getLeftNode(TreeNode_v2<T> *) const;
    TreeNode_v2<T> *getRightNode(TreeNode_v2<T> *) const;
    bool isLeftNodeEmpty(TreeNode_v2<T> node) const;
    bool isRightNodeEmpty(TreeNode_v2<T> node) const;

    void eraseTree(TreeNode_v2<T> node);

    T readValue(TreeNode_v2<T> node) const;
    void writeValue(TreeNode_v2<T> *node, T t);
    void insertRightNode(TreeNode_v2<T> *node);
    void insertLeftNode(TreeNode_v2<T> *node);

    void printTree() const;

    void preOrder(TreeNode_v2<T> *node);
    void inOrder(TreeNode_v2<T> *node);
    void postOrder(TreeNode_v2<T> *node);

    int depth(TreeNode_v2<T> *root);

private:
    TreeNode_v2<T>* _root;

};

#include "../src/N-Tree.tpp"

#endif //BINARYSEARCHTREES_N_TREE_H
