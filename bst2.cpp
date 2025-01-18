#include <iostream>
struct Node {
  int data;
  Node *left, *right;
  Node(int val) : data(val), left(nullptr), right(nullptr) {}
} *root = nullptr;

void insert(int val) {
  if (!root) {
    Node *t = new Node(val);
    root = t;
    return;
  }
  Node *current = root;
  Node *tail = nullptr;
  while (current) {
    tail = current;
    if (val > current->data) {
      current = current->right;
    } else if (val < current->data) {
      current = current->left;
    } else {
      return;
    }
  }

  Node *t = new Node(val);
  if (val > tail->data) {
    tail->right = t;
  } else {
    tail->left = t;
  }
}

void inorder(Node *p) {
  if (p) {
    inorder(p->left);
    std::cout << p->data << " ";
    inorder(p->right);
  }
}

Node *deleteNode(Node *root, int key) {
  if (!root) {
    return nullptr;
  }
  if (key > root->data) {
    root->right = deleteNode(root->right, key);
  } else if (key < root->data) {
    root->left = deleteNode(root->left, key);
  } else {
    if (!root->left && !root->right) {
      delete root;
      return nullptr;
    } else if (!root->left) {
      Node *t = root->right;
      delete root;
      return t;
    } else if (!root->right) {
      Node *t = root->left;
      delete root;
      return t;
    } else {
      Node *temp = root->right;
      while (temp && temp->left) {
        temp = temp->left;
      }

      root->data = temp->data;

      root->right = deleteNode(root->right, temp->data);
    }
  }
  return root;
}

int main(int argc, char const *argv[]) {
  insert(10);
  insert(20);
  insert(5);
  deleteNode(root, 5);
  inorder(root);

  return 0;
}
