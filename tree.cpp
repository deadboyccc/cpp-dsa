#include <iostream>
#include <queue>
#include <stack>
struct node {
  int data;
  node *lchild;
  node *rchild;
};
void I_Preorder(node *root) {
  std::stack<node *> q;
  while (root || !q.empty()) {
    if (root) {
      std::cout << root->data << " ";
      q.push(root);
      root = root->lchild;
    } else {
      root = q.top();
      q.pop();
      root = root->rchild;
    }
  }
}
void I_Postorder(node *root) {
  std::stack<node *> s1, s2;
  if (root) {
    s1.push(root);
    while (!s1.empty()) {
      node *current = s1.top();
      s1.pop();
      s2.push(current);
      if (current->lchild) s1.push(current->lchild);
      if (current->rchild) s1.push(current->rchild);
    }
    while (!s2.empty()) {
      std::cout << s2.top()->data << " ";
      s2.pop();
    }
  }
}
int height(node *root) {
  int x = 0, y = 0;
  if (!root) {
    return 0;
  }
  x = height(root->lchild);
  y = height(root->rchild);
  return 1 + std::max(x, y);
}
int count(node *root) {
  if (root) {
    return count(root->lchild) + count(root->rchild) + 1;
  }
  return 0;
}
void Level_order(node *root) {
  std::queue<node *> q;
  q.push(root);
  std::cout << root->data << " ";
  while (!q.empty()) {
    node *p = q.front();
    q.pop();
    if (p->lchild) {
      std::cout << p->lchild->data << " ";
      q.push(p->lchild);
    }
    if (p->rchild) {
      std::cout << p->rchild->data << " ";
      q.push(p->rchild);
    }
  }
}

void I_Inorder(node *root) {
  std::stack<node *> q;
  while (root || !q.empty()) {
    if (root) {
      q.push(root);
      root = root->lchild;
    } else {
      root = q.top();
      q.pop();
      std::cout << root->data << " ";
      root = root->rchild;
    }
  }
}
void R_Preorder(node *root) {
  if (root) {
    std::cout << root->data << " ";
    R_Preorder(root->lchild);
    R_Preorder(root->rchild);
  }
}
void R_Inorder(node *root) {
  if (root) {
    R_Inorder(root->lchild);
    std::cout << root->data << " ";
    R_Inorder(root->rchild);
  }
}
void R_postorder(node *root) {
  if (root) {
    R_postorder(root->lchild);
    R_postorder(root->rchild);
    std::cout << root->data << " ";
  }
}
node *createTree() {
  node *root = new node;

  std::cout << "Enter root's data: \n" << std::endl;
  std::cin >> root->data;
  root->lchild = root->rchild = nullptr;
  std::queue<node *> q;
  q.push(root);
  while (!q.empty()) {
    node *current = q.front();
    q.pop();

    int x;
    std::cout << "Enter left child of\n " << current->data;
    std::cin >> x;
    if (x != -1) {
      current->lchild = new node;
      current->lchild->data = x;
      current->lchild->lchild = current->lchild->rchild = nullptr;
      q.push(current->lchild);
    }
    std::cout << "Enter the right child of\n " << current->data;
    std::cin >> x;
    if (x != -1) {
      current->rchild = new node;
      current->rchild->data = x;
      current->rchild->lchild = current->rchild->rchild = nullptr;
      q.push(current->rchild);
    }
  }
  return root;
}

int main(int argc, char const *argv[]) {
  node *root = new node;
  root->data = 10;
  root->lchild = new node;
  root->lchild->data = 20;
  root->lchild->lchild = root->lchild->rchild = nullptr;
  root->rchild = new node;
  root->rchild->data = 30;
  root->rchild->lchild = root->rchild->rchild = nullptr;
  std::cout << "\nRecursive Preorder\n";
  R_Preorder(root);
  std::cout << "\nRecursive Inorder\n";
  R_Inorder(root);
  std::cout << "\nRecursive Postorder\n";
  R_postorder(root);
  std::cout << "\nIterative Preorder using Stack\n";
  I_Preorder(root);
  std::cout << "\nIterative Inorder\n";
  I_Inorder(root);
  std::cout << "\nLevel traversal \n";
  Level_order(root);
  std::cout << "\ncount = " << count(root) << std::endl;
  std::cout << "\nHeight = " << height(root) << std::endl;
  std::cout << "\n Iterative Postorder\n";
  I_Postorder(root);

  return 0;
}
