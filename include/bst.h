// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_

#include <string>

template<typename T>
class BST {
 private:
  struct Node {
    T key;
    int count;
    Node* left;
    Node* right;

    explicit Node(const T& value)
        : key(value), count(1), left(nullptr), right(nullptr) {}
  };

  Node* root;

  void clear(Node* node) {
    if (node == nullptr)
      return;

    clear(node->left);
    clear(node->right);
    delete node;
  }

  void insert(Node*& node, const T& value) {
    if (node == nullptr) {
      node = new Node(value);
      return;
    }

    if (value < node->key) {
      insert(node->left, value);
    } else if (value > node->key) {
      insert(node->right, value);
    } else {
      node->count++;
    }
  }

  int search(Node* node, const T& value) const {
    if (node == nullptr)
      return 0;

    if (value < node->key)
      return search(node->left, value);

    if (value > node->key)
      return search(node->right, value);

    return node->count;
  }

  int depth(Node* node) const {
    if (node == nullptr)
      return 0;

    int l = depth(node->left);
    int r = depth(node->right);

    return (l > r ? l : r) + 1;
  }

 public:
  BST() : root(nullptr) {}

  ~BST() {
    clear(root);
  }

  void insert(const T& value) {
    insert(root, value);
  }

  int search(const T& value) const {
    return search(root, value);
  }

  int depth() const {
    return depth(root);
  }
};

#endif  // INCLUDE_BST_H_
