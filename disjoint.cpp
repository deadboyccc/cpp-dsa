
#include "pch.h"
// Function to find the root of a node with path compression
int find(int node, std::vector<int> &parent)
{
  // if the parent of the node isn't itself
  if (parent[node] != node)
  {
    parent[node] = find(parent[node], parent); // Path compression
    // change it's parent to AP
  }
  return parent[node]; // then return
}

// Function to union two sets
void unionSets(int u, int v, std::vector<int> &parent, std::vector<int> &rank)
{
  int rootU = find(u, parent);
  int rootV = find(v, parent);

  if (rootU != rootV) // if they aren't in the same set
  {
    // Union by rank
    if (rank[rootU] > rank[rootV]) // if the rank of V bigger than of U, parent[V] = U
    {
      parent[rootV] = rootU;
    }
    else if (rank[rootU] < rank[rootV])
    {
      parent[rootU] = rootV;
    }
    else
    // if they are the same rank then mix them + add rank
    {
      parent[rootV] = rootU;
      rank[rootU]++;
    }
  }
}

// Function to demonstrate the Disjoint Set operations
void exampleDisjointSet()
{
  int n = 10;                  // Number of elements (0 to 9)
  std::vector<int> parent(n);  // nodes
  std::vector<int> rank(n, 0); // rank + all zero

  // Initialize the parent for each element
  for (int i = 0; i < n; i++)
  {
    parent[i] = i; // set all nodes to be their own respective parent
  }

  // Perform some union operations
  // unionSets(e1,e2,parent vector, rank vector)
  unionSets(1, 2, parent, rank);
  unionSets(2, 3, parent, rank);
  unionSets(4, 5, parent, rank);
  unionSets(6, 7, parent, rank);
  unionSets(5, 6, parent, rank);

  // Find and display the root of each element
  std::cout << "Roots of each element:\n";
  for (int i = 0; i < n; i++)
  {
    std::cout << "Element " << i << " -> Root: " << find(i, parent) << "\n";
  }

  // Check if two elements are in the same set
  std::cout << "\nChecking connectivity:\n";
  std::cout << "1 and 3 are in the same set: " << (find(1, parent) == find(3, parent)) << "\n"; // Should be true
  std::cout << "4 and 7 are in the same set: " << (find(4, parent) == find(7, parent)) << "\n"; // Should be false
}

int main()
{

  exampleDisjointSet(); // Run the example

  return 0;
}
