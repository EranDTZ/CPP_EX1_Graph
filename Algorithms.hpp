#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP
#include "Graph.hpp"
#include <iostream>

//Eran David Tzarum
//ID:207640806

class Algorithms {
public:
  static bool isConnected(const Graph& g);
  static void DFS(const Graph& g, int vertex, std::vector<bool>& visited);
  static std::string shortestPath(const Graph& g, int start, int end);
  static bool isContainsCycle(const Graph& g);  // prints a cycle if found , els prints "0";
  static std::string isBipartite(const Graph& g);
  static std::string isBipartiteString(const Graph& g);
  // static bool negativeCycle(const Graph& g);

  private:

    static bool isCycledfs(std::size_t v, std::vector<bool>& visitedV, std::vector<bool>& backedge, 
                     const std::vector<std::vector<int>>& adjMatrix, std::vector<int>& path, int parent, bool isDirected);
};

#endif
