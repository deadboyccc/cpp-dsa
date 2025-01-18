#include "pch.h"
using namespace std;

char find(char x, unordered_map<char, char>& parent) {
  if (parent[x] != x) {
    parent[x] = find(parent[x], parent);
  }
  return parent[x];
}

void unionSets(char x, char y, unordered_map<char, char>& parent,
               unordered_map<char, int>& rank) {
  char rootX = find(x, parent);
  char rootY = find(y, parent);

  if (rootX != rootY) {
    if (rank[rootX] > rank[rootY]) {
      parent[rootY] = rootX;
    } else if (rank[rootX] < rank[rootY]) {
      parent[rootX] = rootY;
    } else {
      parent[rootY] = rootX;
      rank[rootX]++;
    }
  }
}

int main() {
  unordered_map<char, char> parent;
  unordered_map<char, int> rank;

  string nodes = "abcdefg";
  for (char node : nodes) {
    parent[node] = node;
    rank[node] = 0;
  }

  unionSets('a', 'b', parent, rank);
  unionSets('b', 'c', parent, rank);
  unionSets('d', 'e', parent, rank);
  unionSets('e', 'f', parent, rank);
  unionSets('f', 'g', parent, rank);
  for (auto element : nodes) {
    cout << "Root of " << element << " is: " << find(element, parent)
         << " ,and it's rank is" << rank[element] << endl;
  }

  return 0;
}
