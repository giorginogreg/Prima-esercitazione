//
// Created by Greg on 12/04/22.
//

#ifndef TREE_H
#define TREE_H

/**
 * Per ogni nodo N, tutti gli elementi contenuti nel sottoalbero radicato nel figlio sx di N sono minori di N.value
 * Per ogni nodo N, tutti gli elementi contenuti nel sottoalbero radicato nel figlio DX di N sono maggiori di N.value
 */
#include "../../include/Node.h"
#include "../../Lists/pointer_implementation/Linked List/include/LinkedList.h"

template<class T>
struct TreeNode {

    TreeNode* _ancestor;
    T value;
    TreeNode* _lSon;
    TreeNode* _rSon;

    TreeNode() {
        //*value = nullptr;
        _ancestor =  _lSon = _rSon = nullptr;
    }
    TreeNode(T val) {
        value = val;
        _ancestor = _lSon = _rSon = nullptr;
    }
    TreeNode(TreeNode<T>* ancestor) {
        _ancestor = ancestor;
        _lSon = _rSon = nullptr;
    }
    TreeNode(T val, TreeNode<T>* ancestor) {
        value = val;
        _ancestor = ancestor;
        _lSon = _rSon = nullptr;

    }
    TreeNode(T val, TreeNode<T>* ancestor,TreeNode<T>* lSon, TreeNode<T>* rSon ) {
        value = val;
        _ancestor = ancestor;
        _lSon = lSon;
        _rSon = rSon;
    }
    bool isLeaf() {
        return _lSon == nullptr
               && _rSon == nullptr;
    }
};

template<class T>
class Tree {

public:

    typedef TreeNode<T>* tree;

    // operatori
    virtual void create() = 0;
    virtual bool empty() const = 0;

    virtual TreeNode<int> *const root() const = 0;
    virtual TreeNode<T>* ancestor(TreeNode<T>* ) const =  0;
    virtual TreeNode<T>* getLeftNode(TreeNode<T>*) const = 0;
    virtual TreeNode<T>* getRightNode(TreeNode<T>* ) const = 0;
    virtual bool isLeftNodeEmpty(TreeNode<T>) const = 0;
    virtual bool isRightNodeEmpty(TreeNode<T>) const = 0;

    virtual void eraseTree(TreeNode<T>) = 0;

    virtual T readValue(TreeNode<T>) const = 0;
    virtual void writeValue(TreeNode<T>*, T ) = 0;

    virtual void insertRoot(TreeNode<T>*) = 0;
    virtual void insertRightNode(TreeNode<T>*) = 0;
    virtual void insertLeftNode(TreeNode<T>*) = 0;

    virtual void printTree() const = 0;

    // Visit algorithms
    virtual void preOrder(TreeNode<T>* ) = 0; // NLR
    virtual void inOrder(TreeNode<T>* ) = 0; // LNR
    virtual void postOrder(TreeNode<T>* ) = 0; // LRN

    virtual int depth(TreeNode<T>* root) = 0;
private:
    //virtual void printSubTree(TreeNode<T> root, std::string prependString) const = 0;
};


#endif //TREE_H
