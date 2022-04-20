//
// Created by Greg on 12/04/22.
//


#include <iostream>
#include <string>

#include "include/BinarySearchTree.h"

using std::cout;
using std::endl;

int main() {
    typedef int T;

    auto L1 = new BinarySearchTree<T>(5);
    L1->insertLeftNode(new TreeNode<T>(2));
    L1->insertRightNode(new TreeNode<T>(3));

    auto R1 = new BinarySearchTree<T>(5);
    R1->insertLeftNode(new TreeNode<T>(4));
    R1->insertRightNode(new TreeNode<T>(1));

    auto t = new BinarySearchTree<T>(10);
    t->insertLeftNode(L1->root());
    t->insertRightNode(R1->root());

    return 0;
}
