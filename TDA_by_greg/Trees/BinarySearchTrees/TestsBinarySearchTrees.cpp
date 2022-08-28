//
// Created by Greg on 20/04/22.
//

#include <iostream>
#include <string>

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "./../../../catch.hpp"

#include "include/BinaryTree.h"

TEST_CASE( "Binary Tree Initialization" ) {

    auto tree = new BinaryTree<int>(5);

    REQUIRE(tree->readValue(*(tree->root())) == 5);
}

TEST_CASE( "Is tree empty / Full" ) {

    auto tree = new BinaryTree<int>();

    REQUIRE(tree->empty());
    tree->insertLeftNode(new TreeNode<int>());
    tree->insertRightNode(new TreeNode<int>());
    REQUIRE_FALSE(tree->empty());

}

TEST_CASE( "Test that right node is filled correctly" ) {

    auto tree = new BinaryTree<int>();
    auto node = new TreeNode<int>(5);
    tree->insertRightNode(node);
    REQUIRE(tree->getRightNode(tree->root()) == node);

}


TEST_CASE( "Test that left node is filled correctly" ) {

    auto tree = new BinaryTree<int>();
    auto node = new TreeNode<int>(5);
    tree->insertLeftNode(node);
    REQUIRE(tree->getLeftNode(tree->root()) == node);

}

TEST_CASE( "Test that writing value in a node works correctly" ) {

    auto tree = new BinaryTree<int>();
    auto node = new TreeNode<int>(5);
    tree->insertLeftNode(node);
    tree->writeValue(tree->getLeftNode(tree->root()), 50);
    REQUIRE(tree->readValue(*(tree->getLeftNode(tree->root()))) == 50 );

}