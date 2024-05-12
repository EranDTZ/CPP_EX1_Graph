#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>

//Eran David Tzarum
//ID:207640806

class Graph {

private:

  std::vector<std::vector<int>> adjMatrix;

  int numVertices;

  bool directed = false;

public:

  Graph(); //empty constructor;
  ~Graph(); //annihilator;
  void addEdge(int src, int dest);
  void loadGraph(const std::vector<std::vector<int>>& graph);
  void printGraph();
  int getNumVertices() const;
  std::vector<int> getNeighbors(int vertex) const;
  int getAdjMatrix(int current, int neighbor) const;
  std::vector<std::vector<int>> getAdjMatrix() const;
  bool getDirected() const;
};

#endif
