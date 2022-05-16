//
// Created by Greg on 12/04/22.
//

#ifndef TREE_V2_H
#define TREE_V2_H

/**
 * Per ogni nodo N, tutti gli elementi contenuti nel sottoalbero radicato nel figlio sx di N sono minori di N.value
 * Per ogni nodo N, tutti gli elementi contenuti nel sottoalbero radicato nel figlio DX di N sono maggiori di N.value
 */
#include "../../include/Node.h"
#include "../../Lists/pointer_implementation/Linked List/include/LinkedList.h"

template<class T>
struct TreeNode_v2 {

    TreeNode_v2* _ancestor;
    T value;
    LinkedList<TreeNode_v2<T>*>* _sons;
    int _level;

    TreeNode_v2() {
        _ancestor = nullptr;
        _sons = new LinkedList< TreeNode_v2<T>*>();
    }
    TreeNode_v2(T val) {
        TreeNode_v2<T>();
        value = val;
    }
    TreeNode_v2(TreeNode_v2<T>* ancestor) {
        TreeNode_v2<T>();
        _ancestor = ancestor;
    }

    TreeNode_v2(T value_to_assign, TreeNode_v2<T>* ancestor) {
        (TreeNode_v2<T>(value_to_assign));
        _ancestor = ancestor;
    }

    TreeNode_v2(T value_to_assign, TreeNode_v2<T>* ancestor, int level) {
        (TreeNode_v2<T>(value_to_assign));
        _ancestor = ancestor;
        _level = level;
    }

    bool isLeaf() {
        return _sons->isEmpty();
    }
};

template<class T>
class Tree {

public:

    typedef TreeNode_v2<T>* tree;

    // operatori
    virtual void create() = 0;
    virtual bool empty() const = 0;

    virtual TreeNode_v2<T>* root() const = 0;
    virtual TreeNode_v2<T>* ancestor() const =  0;
    virtual TreeNode_v2<T>* getLeftNode(TreeNode_v2<T> *) const = 0;
    virtual TreeNode_v2<T>* getRightNode(TreeNode_v2<T> *) const = 0;
    virtual bool isLeftNodeEmpty(TreeNode_v2<T>) const = 0;
    virtual bool isRightNodeEmpty(TreeNode_v2<T>) const = 0;

    virtual void eraseTree(TreeNode_v2<T>) = 0;

    virtual T readValue(TreeNode_v2<T>) const = 0;
    virtual void writeValue(TreeNode_v2<T>*, T ) = 0;

    virtual void insertRoot(TreeNode_v2<T>*) = 0;
    virtual void insertRightNode(TreeNode_v2<T>*) = 0;
    virtual void insertLeftNode(TreeNode_v2<T>*) = 0;

    virtual void printTree() const = 0;

    // Visit algorithms
    virtual void preOrder(TreeNode_v2<T>* ) = 0; // NLR
    virtual void inOrder(TreeNode_v2<T>* ) = 0; // LNR
    virtual void postOrder(TreeNode_v2<T>* ) = 0; // LRN

    virtual int depth(TreeNode_v2<T>* root) = 0;

    int nodes_inside = 0;
private:
    //virtual void printSubTree(TreeNode<T> root, std::string prependString) const = 0;
};


#endif //TREE_V2_H
