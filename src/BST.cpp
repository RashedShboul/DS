#include "../include/ds/BST.hpp"

#include <iostream>
#include <stdexcept>
namespace ds {

BST::BST() : root(nullptr), _size(0) {}

BST::~BST() { this->clear(); }

void BST::destroy(TreeNode* root) noexcept {
  if (root == nullptr) return;
  destroy(root->left);
  destroy(root->right);
  delete root;
}

void BST::clear() noexcept {
  this->destroy(root);
  root = nullptr;
  _size = 0;
}

BST::TreeNode* BST::insert(TreeNode* node, int key) {
  if (!node) return new TreeNode(key);
  if (key < node->key)
    node->left = insert(node->left, key);
  else if (key > node->key)
    node->right = insert(node->right, key);
  // else: duplicate, do nothing
  return node;
}
void BST::insert(int key) noexcept {
  root = insert(root, key);
  ++_size;
}

BST::TreeNode* BST::search_node(TreeNode* root, int key) const noexcept {
  if (!root) return nullptr;
  if (root->key == key)
    return root;
  else if (root->key > key)
    return search_node(root->left, key);
  else
    return search_node(root->right, key);
}
bool BST::search(int key) const noexcept {
  if (this->search_node(root, key)) return true;
  return false;
}

BST::TreeNode* BST::find_min_node(TreeNode* root) const noexcept {
  if (!root) return nullptr;
  if (root->left)
    return find_min_node(root->left);
  else
    return root;
}
int BST::find_min() const {
  TreeNode* ptr = find_min_node(root);
  if (ptr)
    return ptr->key;
  else
    throw std::runtime_error("empty tree");
}

BST::TreeNode* BST::find_max_node(TreeNode* root) const noexcept {
  if (!root) return nullptr;
  if (root->right)
    return find_max_node(root->right);
  else
    return root;
}
int BST::find_max() const {
  TreeNode* ptr = find_max_node(root);
  if (ptr)
    return ptr->key;
  else
    throw std::runtime_error("empty tree");
}

size_t BST::size() const noexcept { return _size; }

void BST::inorder_treversal(TreeNode* root) const noexcept {
  if (!root) return;
  inorder_treversal(root->left);
  std::cout << root->key << ' ';
  inorder_treversal(root->right);
}
void BST::inorder_treversal() const noexcept { this->inorder_treversal(root); }

BST::TreeNode* BST::inorder_successor(TreeNode* node, int key) const noexcept {
  TreeNode* current = this->search_node(root, key);
  if (!current) return nullptr;
  if (current->right)
    return find_min_node(current->right);
  else {
    TreeNode* successor = nullptr;
    TreeNode* ancestor = root;
    while (ancestor != current) {
      if (current->key < ancestor->key) {
        successor = ancestor;
        ancestor = ancestor->left;
      } else
        ancestor = ancestor->right;
    }
    return successor;
  }
}
int BST::inorder_successor(int key) const {
  if (!root) throw std::runtime_error("empty tree");
  TreeNode* ptr = this->inorder_successor(root, key);
  if (!ptr) throw std::runtime_error("there is no successor");
  return ptr->key;
}

BST::TreeNode* BST::remove(TreeNode* root, int key) {
  if (!root)
    return root;
  else if (root->key > key)
    root->left = remove(root->left, key);
  else if (root->key < key)
    root->right = remove(root->right, key);
  else {
    // leaf node
    if (!root->left && !root->right) {
      delete root;
      root = nullptr;
      --_size;
    } else if (root->right && root->left) {
      TreeNode* temp = find_min_node(root->right);
      root->key = temp->key;
      root->right = remove(root->right, temp->key);
    } else {
      TreeNode* tmp = root;
      root = root->left ? root->left : root->right;
      delete tmp;
      --_size;
    }
  }
  return root;
}
bool BST::remove(int key) noexcept {
  if (!search(key)) return false;
  root = remove(root, key);
  return true;
}

}  // namespace ds