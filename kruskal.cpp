#include "pch.h"
// Structure to represent an edge with a weight
// class and nodes are kinda similiar
class Edge {
 public:
  int u, v, weight;
  bool operator<(const Edge &other) const
  // const = we dont' change any attributes of THIS object
  {
    return weight < other.weight;
  }
};

// Function to find the root of a node with path compression
int find(int node, std::vector<int> &parent) {
  if (parent[node] != node) {
    parent[node] = find(parent[node], parent);  // Path compression
  }
  return parent[node];
}

// Function to union two sets
void unionSets(int u, int v, std::vector<int> &parent, std::vector<int> &rank) {
  int rootU = find(u, parent);
  int rootV = find(v, parent);
  if (rootU != rootV) {
    if (rank[rootU] > rank[rootV]) {
      parent[rootV] = rootU;
    } else if (rank[rootU] < rank[rootV]) {
      parent[rootU] = rootV;
    } else {
      parent[rootV] = rootU;
      rank[rootU]++;
    }
  }
}

// Kruskal's algorithm to find the Minimum Spanning Tree
std::vector<Edge> kruskalMST(int n, std::vector<Edge> &edges) {
  std::vector<Edge> mst;  // Stores the edges in the MST
  std::vector<int> parent(n);
  std::vector<int> rank(n, 0);

  // Initialize the parent for each element
  for (int i = 0; i < n; i++) {
    parent[i] = i;
  }

  // Sort edges by weight
  std::sort(edges.begin(), edges.end());

  // Process each edge in increasing order of weight
  for (const auto &edge : edges) {
    int u = edge.u;
    int v = edge.v;

    // Check if including this edge would form a cycle
    if (find(u, parent) != find(v, parent)) {
      mst.push_back(edge);            // Add edge to MST
      unionSets(u, v, parent, rank);  // Union the sets
    }
  }

  return mst;
}

int main() {
  // Number of vertices
  int n = 6;

  // List of edges (u, v, weight)
  std::vector<Edge> edges = {{0, 1, 4}, {0, 2, 4}, {1, 2, 2},
                             {1, 3, 5}, {2, 3, 5}, {2, 4, 6},
                             {3, 4, 3}, {3, 5, 8}, {4, 5, 9}};

  // Find the MST using Kruskal's algorithm
  std::vector<Edge> mst = kruskalMST(n, edges);

  // Display the MST edges and total weight
  std::cout << "Edges in the Minimum Spanning Tree:\n";
  int totalWeight = 0;
  for (const auto &edge : mst) {
    std::cout << "Edge (" << edge.u << ", " << edge.v
              << ") with weight: " << edge.weight << "\n";
    totalWeight += edge.weight;
  }
  std::cout << "Total weight of MST: " << totalWeight << "\n";

  return 0;
}
