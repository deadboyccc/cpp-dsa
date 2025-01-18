#include "pch.h"
// optionals
using std::cin;
using std::cout;
using std::endl;
using iipair = std::pair<int, int>;

int primMST(std::unordered_map<int, std::vector<std::pair<int, int>>> &graph,
            int startNode) {
  // Min-heap priority queue to store edges with minimum weight first (weight,
  // node)
  std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                      std::greater<std::pair<int, int>>>
      minHeap;

  // Visited array to track visited nodes
  std::unordered_map<int, bool> visited;
  int totalWeight = 0; // Stores the total weight of the minimum spanning tree

  // Start with the initial node, push its weight (0) and the node itself into
  // the minHeap
  minHeap.push({0, startNode});

  // Loop until all edges are processed
  while (!minHeap.empty()) {
    // Get the edge with the minimum weight
    auto [weight, node] = minHeap.top();
    minHeap.pop();

    // If the node has already been visited, continue to the next
    if (visited[node]) { continue; }

    // Mark the node as visited
    visited[node] = true;

    // Add the weight of the current edge to the total MST weight
    totalWeight += weight;

    // Explore all adjacent nodes of the current node
    for (const auto &edge : graph[node]) {
      auto [adjacentNode, edgeWeight] = edge;

      // If the adjacent node has not been visited, add it to the heap
      if (!visited[adjacentNode]) { minHeap.push({edgeWeight, adjacentNode}); }
    }
  }

  return totalWeight; // Return the total weight of the minimum spanning tree
}

int main() {
  // Example graph (undirected), represented as an unordered_map
  // Each key is a node, and each value is a list of pairs representing
  // (adjacent_node, weight)
  std::unordered_map<int, std::vector<std::pair<int, int>>> graph = {
      {0, {{1, 2}, {3, 1}, {2, 1}}},
      {1, {{0, 2}, {2, 3}}},
      {2, {{1, 3}, {3, 4}}},
      {3, {{2, 4}}}};

  // Starting node for Prim's algorithm
  int startNode = 0;

  // Calculate the total weight of the MST
  int result = primMST(graph, startNode);

  // Output the total weight of the Minimum Spanning Tree
  std::cout << "Total weight of MST: " << result << std::endl;

  return 0;
}