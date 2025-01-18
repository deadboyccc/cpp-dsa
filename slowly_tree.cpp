#include <iostream>
#include <queue>
#include <stack>
// Write Tree struct with constructor & deconstructor
struct node {
  int data;
  node *lchild, *rchild;
  node() : data(0), lchild(nullptr), rchild(nullptr) {}
  node(int a) : data(a), rchild(nullptr), lchild(nullptr) {}
  node(int a, node *l, node *r) : data(a), lchild(l), rchild(r) {}
};
// write create function for a tree that takes a node pointer and returns a
// pointer to the node created in heap
node *createTree() {
  node *root = new node();
  int x;
  std::queue<node *> q;
  // using level order=queue FIFO(first in first out) to create a tree
  std::cout << "Enter the value of root: \n";
  std::cin >> x;
  root->data = x;
  q.push(root);
  while (!q.empty()) {
    node *current = q.front();
    q.pop();
    std::cout << "Enter the left child of " << current->data;
    std::cin >> x;
    if (x != -1) {
      current->lchild = new node(x);
      q.push(current->lchild);
    }
    std::cout << "Enter the right child of " << current->data;
    std::cin >> x;
    if (x != -1) {
      current->rchild = new node(x);
      q.push(current->rchild);
    }
  }
  return root;
}
// write recursive pre,in,post order
//! RECURSIVE PRE = root(print),lchild,rchild
void R_preorder(node *root) {
  if (root) {
    std::cout << root->data << " ";
    R_preorder(root->lchild);
    R_preorder(root->rchild);
  }
}
//! RECURSIVE IN = lchild,root(print),rchild
void R_inorder(node *root) {
  if (root) {
    R_inorder(root->lchild);
    std::cout << root->data << " ";
    R_inorder(root->rchild);
  }
}
//! Recursive Post = lchild,rchild,root
void R_postorder(node *root) {
  if (root) {
    R_postorder(root->lchild);
    R_postorder(root->rchild);
    std::cout << root->data << " ";
  }
}

// write iterative in order

void I_inorder(node *root) {
  std::stack<node *> s;
  while (root || !s.empty()) {
    if (root) {
      s.push(root);
      root = root->lchild;
    } else {
      root = s.top();
      s.pop();
      std::cout << root->data << " ";
      root = root->rchild;
    }
  }
}
// iterative preorder
void I_preorder(node *root) {
  std::stack<node *> s;
  while (root || !s.empty()) {
    if (root) {
      s.push(root);
      std::cout << root->data << " ";
      root = root->lchild;
    } else {
      root = s.top();
      s.pop();
      root = root->rchild;
    }
  }
}
// write iterative post order
// write level order
void level(node *root) {
  std::queue<node *> q;
  q.push(root);
  while (!q.empty()) {
    node *current = q.front();
    q.pop();
    if (current) {
      std::cout << current->data << " ";
      q.push(current->lchild);
      q.push(current->lchild);
    }
  }
}
// write count
// height
// deg 1 count
int deg1(node *root) {
  if (!root) {
    return 0;
  }
  int x = deg1(root->lchild);
  int y = deg1(root->rchild);
  if ((root->lchild && !root->rchild) || (root->rchild && !root->lchild)) {
    return x + y + 1;
  } else {
    return x + y;
  }
}
// and trace all t he previous functions slowly and carefully , google search
// how to trace using a helper, to better get recursion int
int main(int argc, char const *argv[]) {
  node *l = new node(20);
  node *r = new node(30);
  node *root = new node(10, l, r);

  std::cout << "\n Recursive preorder\n";
  R_preorder(root);
  std::cout << "\n Recursive inorder\n";
  R_inorder(root);
  std::cout << "\n Recursive Postorder\n";
  R_postorder(root);
  std::cout << "\nIterative Preorder\n";
  I_preorder(root);
  std::cout << "\nIterative inorder\n";
  I_inorder(root);
  std::cout << "\n level traversal \n";
  level(root);
  std::cout << "\ndeg 1 count\n";
  std::cout << deg1(root);
  return 0;
}
