#pragma once
#include<cstddef>

namespace ds {
class BST {
    private:
    struct TreeNode
    {
        int key; 
        TreeNode* left, *right;  
        TreeNode(int key, TreeNode* left = nullptr, TreeNode* right = nullptr) : 
            key(key), left(left), right(right) {}
    };
    TreeNode* root; 
    size_t _size; 


    TreeNode* insert(TreeNode*, int value); 
    TreeNode* search_node(TreeNode*, int val) const noexcept; 
    TreeNode* find_min_node(TreeNode*) const noexcept; 
    TreeNode* find_max_node(TreeNode*) const noexcept; 
    TreeNode* inorder_successor(TreeNode*, int) const noexcept; 
    TreeNode* remove(TreeNode*, int); 
    void inorder_treversal(TreeNode*) const noexcept; 
    void destroy(TreeNode*) noexcept; 

    public: 
    BST(); 
    ~BST(); 
    void clear() noexcept; 
    void insert(int key) noexcept; 
    bool search(int key) const noexcept; 
    size_t size() const noexcept; 
    int find_max() const; 
    int find_min() const; 
    bool remove(int key) noexcept; 
    int inorder_successor(int key) const; 
    void inorder_treversal() const noexcept; 
}; 
}