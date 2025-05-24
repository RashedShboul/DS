#include "../include/ds/BST.hpp"
#include <iostream>
#include <cassert>

void test_basic_operations() {
    std::cout << "Testing basic operations...\n";
    ds::BST tree;
    
    // Test empty tree
    assert(tree.size() == 0);
    assert(!tree.search(5));
    
    // Test insertion
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);
    
    assert(tree.size() == 7);
    assert(tree.search(50));
    assert(tree.search(30));
    assert(tree.search(70));
    assert(!tree.search(25));  // Should not exist
    
    // Test min/max
    assert(tree.find_min() == 20);
    assert(tree.find_max() == 80);
    
    std::cout << "Basic operations test passed!\n";
}

void test_removal() {
    std::cout << "\nTesting removal operations...\n";
    ds::BST tree;
    
    // Build a tree
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);
    
    // Test removing leaf node
    assert(tree.remove(20));
    assert(!tree.search(20));
    assert(tree.size() == 6);
    
    // Test removing node with one child
    assert(tree.remove(30));
    assert(!tree.search(30));
    assert(tree.search(40));  // Child should still exist
    assert(tree.size() == 5);
    
    // Test removing node with two children
    assert(tree.remove(50));  // Root node
    assert(!tree.search(50));
    assert(tree.search(60));  // Successor should still exist
    assert(tree.size() == 4);
    
    // Test removing non-existent node
    assert(!tree.remove(25));
    assert(tree.size() == 4);  // Size should not change
    
    std::cout << "Removal operations test passed!\n";
}

void test_successor() {
    std::cout << "\nTesting successor operations...\n";
    ds::BST tree;
    
    // Build a tree
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);
    
    // Test successor for various nodes
    assert(tree.inorder_successor(20) == 30);
    assert(tree.inorder_successor(30) == 40);
    assert(tree.inorder_successor(40) == 50);
    assert(tree.inorder_successor(50) == 60);
    assert(tree.inorder_successor(60) == 70);
    assert(tree.inorder_successor(70) == 80);
    
    // Test successor for non-existent node
    try {
        tree.inorder_successor(25);
        assert(false);  // Should not reach here
    } catch (const std::runtime_error& e) {
        // Expected exception
    }
    
    // Test successor for max node
    try {
        tree.inorder_successor(80);
        assert(false);  // Should not reach here
    } catch (const std::runtime_error& e) {
        // Expected exception
    }
    
    std::cout << "Successor operations test passed!\n";
}

void test_traversal() {
    std::cout << "\nTesting traversal...\n";
    ds::BST tree;
    
    // Build a tree
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);
    
    std::cout << "Inorder traversal (should be sorted): ";
    tree.inorder_treversal();
    std::cout << "\n";
    
    std::cout << "Traversal test completed!\n";
}

void test_edge_cases() {
    std::cout << "\nTesting edge cases...\n";
    ds::BST tree;
    
    // Test operations on empty tree
    assert(tree.size() == 0);
    assert(!tree.search(5));
    assert(!tree.remove(5));
    
    try {
        tree.find_min();
        assert(false);  // Should not reach here
    } catch (const std::runtime_error& e) {
        // Expected exception
    }
    
    try {
        tree.find_max();
        assert(false);  // Should not reach here
    } catch (const std::runtime_error& e) {
        // Expected exception
    }
    
    // Test single node tree
    tree.insert(5);
    assert(tree.size() == 1);
    assert(tree.search(5));
    assert(tree.find_min() == 5);
    assert(tree.find_max() == 5);
    
    // Test removing root when it's the only node
    assert(tree.remove(5));
    assert(tree.size() == 0);
    assert(!tree.search(5));
    
    std::cout << "Edge cases test passed!\n";
}

int main() {
    try {
        test_basic_operations();
        test_removal();
        test_successor();
        test_traversal();
        test_edge_cases();
        
        std::cout << "\nAll tests passed successfully!\n";
    } catch (const std::exception& e) {
        std::cerr << "Test failed: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
} 