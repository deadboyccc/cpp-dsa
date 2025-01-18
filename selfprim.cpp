#include "pch.h"
using icpair = std::pair<int, char>; // int = weight, char = node char
using Graph = std::unordered_map<char, std::vector<icpair>>; // graph
using GraphMinHeap =
    std::priority_queue<icpair, std::vector<icpair>, std::greater<icpair>>;
int primMST(Graph &graph, char start) {
  int                            total = 0;
  GraphMinHeap                   minHeap;
  std::unordered_map<char, bool> visited;
  for (auto node : graph) { visited[node.first] = false; }
  minHeap.push({0, start});
  while (!minHeap.empty()) {
    auto [weight, node] = minHeap.top();
    minHeap.pop();
    if (visited[node]) { continue; }
    total += weight;
    visited[node] = true;
    for (auto neighbor : graph[node]) {
      if (!visited[neighbor.second]) { minHeap.push(neighbor); }
    }
  }
  return total;
}
int main(int argc, char const *argv[]) {
  Graph target = {
      {'a', {{2, 'b'}, {1, 'c'}}},
      {'b', {{2, 'a'}, {4, 'd'}}},
      {'c', {{1, 'a'}, {5, 'd'}, {3, 'e'}}},
      {'d', {{4, 'b'}, {5, 'c'}, {1, 'e'}}},
      {'e', {{3, 'c'}, {1, 'd'}}},

  };
  std::cout << primMST(target, 'a');
  return 0;
}
