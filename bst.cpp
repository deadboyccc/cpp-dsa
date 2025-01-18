#include <iostream>
struct node {
  int data;
  node *lchild, *rchild;
} *root = nullptr;

node *findMin(node *root) {
  // The minimum value in a BST is the leftmost node
  while (root->lchild != nullptr) {
    root = root->lchild;
  }
  return root;
}

node *search(int key) {
  node *p = root;
  while (p) {
    if (p->data == key) {
      return p;
    } else if (key > p->data) {
      p = p->rchild;
    } else {
      p = p->lchild;
    }
  }
  return nullptr;
}
void insert(int key) {
  node *p = root;  // current node
  node *tail, *t;  // tailing and for creating the new inserted node
  // very first node
  if (!root) {
    t = new node;
    t->data = key;
    t->lchild = t->rchild = nullptr;
    root = t;
    return;
  }
  // not first node
  while (p) {
    tail = p;
    if (key < p->data) {
      p = p->lchild;
    } else if (key > p->data) {
      p = p->rchild;
    }
    // no insert for duplicate
    else {
      return;
    }
  }
  t = new node;
  t->data = key;
  t->lchild = t->rchild = nullptr;
  if (key < tail->data) {
    tail->lchild = t;
  } else {
    tail->rchild = t;
  }
}
void I_inorder(node *p) {
  if (p) {
    I_inorder(p->lchild);
    std::cout << p->data << " ";
    I_inorder(p->rchild);
  }
}

// recursive Insert (kinda hard but same pattern with recursive delete)
node *insert(node *root, int value) {
  if (root == nullptr) {
    return new node(value);
  }

  if (value < root->data) {
    root->lchild = insert(root->lchild, value);
  } else if (value > root->data) {
    root->rchild = insert(root->rchild, value);
  }

  return root;
}

// recursive delete

node *deleteNode(node *root, int key) {
  if (root == nullptr) {
    return root;
  }

  if (key < root->data) {
    root->lchild = deleteNode(root->lchild, key);
  } else if (key > root->data) {
    root->rchild = deleteNode(root->rchild, key);
  } else {
    if (root->lchild == nullptr) {
      node *temp = root->rchild;
      delete root;
      return temp;
    } else if (root->rchild == nullptr) {
      node *temp = root->lchild;
      delete root;
      return temp;
    }
    node *temp = findMin(root->rchild);
    root->data = temp->data;
    root->rchild = deleteNode(root->rchild, temp->data);
  }
  return root;
}

// from preorder, create binary tree

node *createBSTFromPreorder(int preorder[], int n) {
  node *root = nullptr;

  for (int i = 0; i < n; i++) {
    root = insert(root, preorder[i]);
  }

  return root;
}

// we finish then we move :) we have to finish and understand use ai and tools
// :) ily try to relax stick your feet + muscle up your torso, and spontaneous
// hand movement :) don't worry you will be fine, we have to get over this
void printTree(node *root, int space = 0, int height = 10) {
  if (!root) return;

  space += height;

  printTree(root->rchild, space);

  // Print current node after space
  std::cout << std::endl;
  for (int i = height; i < space; i++) {
    std::cout << " ";
  }
  std::cout << root->data << "\n";

  // Process left child
  printTree(root->lchild, space);
}
int main(int argc, char const *argv[]) {
  int a[] = {30, 10, 40, 60};
  int n = sizeof(a) / sizeof(int);
  root = createBSTFromPreorder(a, n);

  std::cout << (search(11) ? "Found" : "Not found") << std::endl;
  printTree(root);

  return 0;
}
