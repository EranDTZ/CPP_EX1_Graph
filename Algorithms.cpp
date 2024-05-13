#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <stdexcept>
#include <limits> 
#include <climits>
#include <cstddef> // for std::size_t
#include "Algorithms.hpp"
#include "Graph.hpp"

using namespace std;

//Eran David Tzarum
//ID:207640806




bool Algorithms::isConnected(const Graph& g) {
    std::vector<bool>::size_type numVertices = static_cast<std::vector<bool>::size_type>(g.getNumVertices());
    std::vector<bool> visitedV(numVertices, false);

    std::vector<bool>::size_type startVertex = static_cast<std::vector<bool>::size_type>(-1);
    for (std::vector<bool>::size_type i = 0; i < numVertices; ++i) {
        if (!visitedV[i]) {
            startVertex = i;
            break;
        }
    }

    if (startVertex == static_cast<std::vector<bool>::size_type>(-1))
        return true;

    DFS(g, static_cast<int>(startVertex), visitedV);

    for (bool v : visitedV) {
        if (!v) {
            return false;
        }
    }

    return true;
}

void Algorithms::DFS(const Graph& g, int vertex, std::vector<bool>& visitedV) {
    visitedV[static_cast<std::vector<bool>::size_type>(vertex)] = true;

    std::vector<bool>::size_type numVertices = static_cast<std::vector<bool>::size_type>(g.getNumVertices());
    for (std::vector<bool>::size_type neighbor = 0; neighbor < numVertices; ++neighbor) {
        if (g.getAdjMatrix(vertex, static_cast<int>(neighbor)) && !visitedV[neighbor]) {
            DFS(g, static_cast<int>(neighbor), visitedV);
        }
    }
}




std::string Algorithms::shortestPath(const Graph& g, int start, int end) {
    int numVertices = g.getNumVertices();

    std::vector<bool> visitedV(static_cast<size_t>(numVertices), false);
    std::vector<int> predecessor(static_cast<size_t>(numVertices), -1);
    std::queue<int> q;
    std::string String;

    q.push(start);
    visitedV[static_cast<size_t>(start)] = true;

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        if (current == end) {
            break;  //break bfs when reaching destination;
        }

        for (int neighbor = 0; neighbor < numVertices; ++neighbor) {
            if (g.getAdjMatrix(current, neighbor) && !visitedV[static_cast<size_t>(neighbor)]) {
                visitedV[static_cast<size_t>(neighbor)] = true;
                predecessor[static_cast<size_t>(neighbor)] = current;
                q.push(neighbor);
            }
        }
    }

    if (predecessor[static_cast<size_t>(end)] == -1) {
        String = "-1";
        std::cout << "-1 (there is no path between " << start << " and " << end << ")" << "\n";
        return String;
    }

    std::stack<int> pathStack;
    int current = end;
    while (current != start) {
        pathStack.push(current);
        current = predecessor[static_cast<size_t>(current)];
    }
    pathStack.push(start);

    while (!pathStack.empty()) {
        String += std::to_string(pathStack.top());
        // std::cout << pathStack.top();
        pathStack.pop();
        if (!pathStack.empty()) {
            String += "->";
            // std::cout << "->";
        }
    }
    return String;
}



bool Algorithms::isCycledfs(std::size_t v, std::vector<bool>& visitedV, std::vector<bool>& backedge, 
                     const std::vector<std::vector<int>>& adjMatrix, std::vector<int>& path, int parent, bool Directed) {
  visitedV[v] = true;
  backedge[v] = true;
  path.push_back(v); //add current V to the path;

  for (size_t neighbor = 0; neighbor < adjMatrix[v].size(); neighbor++) {
    if (adjMatrix[v][neighbor] != 0) {  //if there is edge from v to neighbor;
      if (!visitedV[neighbor]) {  
        if (isCycledfs(neighbor, visitedV, backedge, adjMatrix, path, v, Directed)) {
          return true;  //if cycle is found
        }
      } else if (Directed && backedge[neighbor]) {
        return true;  //if directed graph and i backedge cycle found;
      } else if (!Directed && neighbor != parent) {
        return true;  //if undirected graph and i not the parent cycle found;
      }
    }
  }

  backedge[v] = false; 
  path.pop_back(); //remove current v from the path;
  return false;  //no cycle;
}



bool Algorithms::isContainsCycle(const Graph& g) {
  const std::vector<std::vector<int>> & adjMatrix = g.getAdjMatrix();
  vector<bool> visitedV(adjMatrix.size(), false);
  vector<bool> backedge(adjMatrix.size(), false);
  bool Directed = g.getDirected();
  std::vector<int> path; //initialize path vector;

  for (size_t i = 0; i < adjMatrix.size(); i++) {
    if (!visitedV[i]) {
      if (isCycledfs(i, visitedV, backedge, adjMatrix, path, -1, Directed)) {
        //print the cycle if found;
        std::cout << "The cycle is: ";
        for (int node : path) {
          std::cout << node << "->";
        }
        std::cout << path[0] << std::endl; //print the starting V to complete the cycle;
        return true;
      }
    }
  }
  return false;
}




std::string Algorithms::isBipartite(const Graph& g) {
  const std::vector<std::vector<int>>& adjMatrix = g.getAdjMatrix();
  std::size_t numVertices = static_cast<std::size_t>(g.getNumVertices());

  std::vector<int> colors(numVertices, -1); //initialize color V to -1;
  std::vector<int> visitedA; //visited V for A;
  std::vector<int> visitedB; //visited V for B;

  //set colors by BFS;
  for (std::size_t i = 0; i < numVertices; ++i) {
    if (colors[i] == -1) {
      colors[i] = 0;
      std::queue<int> q;
      q.push(i);
      visitedA.push_back(i);

      while (!q.empty()) {
        int current = q.front();
        q.pop();

        for (std::size_t neighbor = i; neighbor < numVertices; ++neighbor) {
          //if there is edge from current to neighbor;
          if (adjMatrix[static_cast<std::size_t>(current)][static_cast<std::size_t>(neighbor)] != 0) {
            //if neighbor uncolored set the opposite color;
            if (colors[static_cast<std::size_t>(neighbor)] == -1) {
              colors[static_cast<std::size_t>(neighbor)] = 1 - colors[static_cast<std::size_t>(current)];
              q.push(neighbor);
              if (colors[neighbor] == 0)
              {
                visitedA.push_back(neighbor);
              }
              else {
                visitedB.push_back(neighbor);
                }
            } else if (colors[static_cast<std::size_t>(neighbor)] == colors[static_cast<std::size_t>(current)]) {
              cout << "Graph is not bipartite\n";
              return "0";
            }
          }
        }
      }
    }
  }

  //string for print;
  std::string String = "The graph is bipartite: A={";

  for (std::size_t i = 0; i < visitedA.size(); ++i) {
      String += to_string(visitedA[i]);
      String += (i < visitedA.size() - 1) ? ", " : "}, B={";
  }

  for (std::size_t i = 0; i < visitedB.size(); ++i) {
      String += to_string(visitedB[i]);
      String += (i < visitedB.size() - 1) ? ", " : "}";
  }
  // cout << String << "\n";
  return String;
}




// bool Algorithms::negativeCycle(const Graph& g) {
//   //check if graph is connected;
//   if (!isConnected(g)) {
//     return true;
//   }

//   int numVertices = g.getNumVertices();

//   //set distances to all v to INT_MAX;
//   std::vector<int> distances(static_cast<size_t>(numVertices), INT_MAX);
//   distances[0] = 0; //set v 0 to source

//   //relax for |V| - 1;
//   for (int i = 0; i < numVertices - 1; ++i) {
//     //iterate through all v;
//     for (unsigned int u = 0; static_cast<size_t>(u) < numVertices; ++u) {
//       //get neighbors from adjmatrix;
//       std::vector<int> neighbors = g.getAdjMatrix()[u];

//       //check for neighbors and edge weights;
//       for (unsigned int v = 0; v < numVertices; ++v) {
//         //check if edge from u to v;
//         if (neighbors[v] == 1) {
//           int weight = -1; //set edge weights all -1;
//           //relax the edge (u, v);
//           if (distances[u] != INT_MAX && distances[u] + weight < distances[v]) {
//             distances[v] = distances[u] + weight;

//             //if distance is updated after |V| - 1 iterations there's a negative cycle;
//             if (i == numVertices - 2 && distances[v] < 0) {
//               return true;
//             }
//           }
//         }
//       }
//     }
//   }

//   //no negative cycles;
//   return false;
// }