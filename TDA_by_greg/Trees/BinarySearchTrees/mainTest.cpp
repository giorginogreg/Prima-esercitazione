//
// Created by Greg on 20/04/22.
//

#include <iostream>
#include <string>

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "./../../../catch.hpp"

#include "include/BinarySearchTree.h"
#include "src/BinarySearchTree.tpp"

TEST_CASE( "Binary Tree Initialization" ) {

    auto tree = new BinarySearchTree<int>(5);

    REQUIRE(tree->readValue(*tree->root()) == 5);
}

TEST_CASE( "Is tree empty / Full" ) {

    auto tree = new BinarySearchTree<int>();

    REQUIRE(tree->empty());
    tree->insertLeftNode(new TreeNode<int>());
    tree->insertRightNode(new TreeNode<int>());
    REQUIRE_FALSE(tree->empty());

}