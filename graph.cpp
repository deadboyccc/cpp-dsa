#include "pch.h"
// #include <iostream>
// #include <list>
// #include <queue>
// #include <set>
// #include <stack>
// #include <unordered_map>
// #include <algorithm>
// #include <limits>
long long factorial(unsigned int a) {
  long long result = 1;
  for (unsigned int i = 1; i <= a; ++i) { result *= i; }
  return result;
}
// Dijkstra's algorithm to find the shortest path from a start node to all other
// nodes in a graph
void dijkstra(
    const std::unordered_map<char, std::vector<std::pair<char, int>>> &graph,
    char                                                               start) {
  // Map to store the shortest distance from the start node to each node
  std::unordered_map<char, int> distances;

  // Map to store the previous node in the optimal path
  std::unordered_map<char, char> previous;

  // Directly use std::greater to create a min-heap based on distances
  std::priority_queue<std::pair<int, char>, std::vector<std::pair<int, char>>,
                      std::greater<>>
      minHeap;

  // Initialize distances: set all distances to infinity
  for (const auto &pair : graph) {
    distances[pair.first] =
        std::numeric_limits<int>::max(); // Max value represents infinity
  }

  // Distance from start node to itself is 0
  distances[start] = 0;

  // Push the starting node onto the priority queue with distance 0
  minHeap.push({0, start});

  // Main loop to process nodes in the priority queue
  while (!minHeap.empty()) {
    // Extract the node with the smallest distance
    auto [currentDistance, currentNode] = minHeap.top();
    minHeap.pop();

    // If the current distance is greater than the recorded distance, skip it
    if (currentDistance > distances[currentNode]) {
      continue; // This node has already been processed with a shorter distance
    }

    // Explore neighbors of the current node
    for (const auto &neighbor : graph.at(currentNode)) {
      char neighborNode = neighbor.first; // Neighbor node
      int  edgeWeight = neighbor.second;  // Weight of the edge to the neighbor

      // Calculate the new distance to the neighbor through the current node
      int newDistance = currentDistance + edgeWeight;

      // If the new distance is shorter, update the distance and the path
      if (newDistance < distances[neighborNode]) {
        distances[neighborNode] = newDistance; // Update the shortest distance
        previous[neighborNode] = currentNode;  // Update the path
        minHeap.push({newDistance,
                      neighborNode}); // Add the neighbor to the priority queue
      }
    }
  }

  // Output the results: shortest distance from start to each node
  for (const auto &pair : distances) {
    std::cout << "Distance from " << start << " to " << pair.first << " is "
              << pair.second << "\n";
  }
}

void DFS(std::unordered_map<char, std::list<char>> &graph, char start,
         std::vector<char> &result) {
  // initial conditions and stack creation
  char             current; // for the current char explore
  std::stack<char> s;
  std::set<char>   visited;
  // 1. Push the starting vertex onto the stack and mark it as visited
  s.push(start);
  visited.insert(start);
  // 2. While the stack is not empty:
  while (!s.empty()) {
    // 3. Pop the top element from the stack and add it to the result

    current = s.top();
    s.pop();
    result.push_back(current);
    // 4. Explore neighbors
    for (char neighbor : graph[current]) {
      if (visited.find(neighbor) == visited.end()) {
        s.push(neighbor);
        visited.insert(neighbor);
      }
    }
  }
}

void BFS(std::unordered_map<char, std::list<char>> &graph, char start,
         std::vector<char> &result) {
  // initial conditions and queue creation
  std::set<char>   visited;
  char             current;
  std::queue<char> q;
  q.push(start);

  visited.insert(start);
  // the loop, 1-visited a vertex(o/p or vec result). 2-exploring(adding it's
  // neighbors to queue), 3-repeat until queue is empty
  while (!q.empty()) {
    current = q.front();
    q.pop();
    result.push_back(current);
    for (char neighbor : graph[current]) {
      if (visited.find(neighbor) == visited.end()) {
        visited.insert(neighbor);
        q.push(neighbor);
      }
    }
  }
}

int main() {
  std::unordered_map<char, std::list<char>> graph = {
      {'A', {'B', 'C'}}, {'B', {'D', 'E'}}, {'C', {'F', 'G'}},
      {'D', {'H', 'I'}}, {'E', {'J'}},      {'F', {'K'}},
      {'G', {'L'}},      {'H', {'M'}},      {'I', {'N'}},
      {'J', {'O'}},      {'K', {'P'}},      {'L', {'Q'}},
      {'M', {'R'}},      {'N', {'S'}},      {'O', {'T'}},
      {'P', {'U'}},      {'Q', {'V'}},      {'R', {'W'}},
      {'S', {'X'}},      {'T', {'Y'}},      {'U', {'Z'}}};
  std::vector<char> result;

  // BFS(graph, 'A', result);
  // DFS(graph, 'A', result);
  // for (int i = 0; i < 10; i++)

  // {
  //   std::cout << result[i] << " ";
  // }
  // std::cout << factorial(10);
  // std::unordered_map<char, std::vector<std::pair<char, int>>> shortestPath =
  // {
  //     {'A', {{'B', 1}, {'D', 1}}},
  //     {'B', {{'C', 3}, {'D', 1}}},
  //     {'C', {{'D', 1}}},
  //     {'D', {{'A', 1}, {'C', 5}, {'E', 7}}},
  //     {'E', {{'D', 7}}},
  //     {'F', {{'A', 3}}}};

  // Declare the graph as an adjacency list
  std::unordered_map<char, std::vector<std::pair<char, int>>> graph3 = {
      {'A', {{'B', 1}, {'D', 1}}},
      {'B', {{'A', 1}, {'C', 3}}},
      {'C', {{'B', 3}, {'D', 2}}},
      {'D', {{'A', 1}, {'C', 2}}}};

  dijkstra(graph3, 'A');

  return 0;
}