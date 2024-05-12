
# Graph Algorithms
Hi , my name is Eran David Tzarum a Computer Science student.
ID:207640806

This project was made to implements a Graph class and various graph algorithms in C++. The Graph class represents a graph using an adjacency matrix, and the algorithms perform operations like determining connectivity, finding cycles, and checking for bipartiteness.

## Files

- **Graph.hpp**: Header file containing the declaration of the Graph class.
- **Graph.cpp**: Source file containing the implementation of the Graph class methods.
- **Algorithms.hpp**: Header file containing the declaration of the Algorithms class with various graph algorithms.
- **Algorithms.cpp**: Source file containing the implementation of the Algorithms class methods.
- **Demo.cpp**: Demo program demonstrating the usage of the Graph class and the implemented algorithms.

## Graph Class

### Constructors

- `Graph()`: Default constructor.
- `~Graph()`: Destructor.

### Methods

- `void addEdge(int src, int dest)`: Adds an edge between source vertex `src` and destination vertex `dest`.
- `void loadGraph(const std::vector<std::vector<int>>& graph)`: Loads a graph from a given adjacency matrix.
- `void printGraph()`: Prints the adjacency matrix representing the graph.
- `int getNumVertices() const`: Returns the number of vertices in the graph.
- `std::vector<int> getNeighbors(int vertex) const`: Returns the neighbors of a given vertex.
- `int getAdjMatrix(int current, int neighbor) const`: Returns the weight of the edge between two vertices.
- `std::vector<std::vector<int>> getAdjMatrix() const`: Returns the entire adjacency matrix.
- `bool getDirected() const`: Returns whether the graph is directed or not.

## Algorithms Class

### Methods

- `static bool isConnected(const Graph& g)`: Checks if the graph is connected.
- `static void DFS(const Graph& g, int vertex, std::vector<bool>& visited)`: Performs Depth-First Search traversal.
- `static std::string shortestPath(const Graph& g, int start, int end)`: Finds the shortest path between two vertices.
- `static bool isContainsCycle(const Graph& g)`: Checks if the graph contains a cycle.
- `static std::string isBipartite(const Graph& g)`: Checks if the graph is bipartite.
- `static std::string isBipartiteString(const Graph& g)`: Helper function for checking bipartiteness.
- `static bool isCycledfs(std::size_t v, std::vector<bool>& visitedV, std::vector<bool>& backedge, const std::vector<std::vector<int>>& adjMatrix, std::vector<int>& path, int parent, bool isDirected)`: Helper function for cycle detection.

## Demo Program

The `Demo.cpp` program serves as a demonstration of how to use the Graph class and the implemented algorithms. It includes examples of creating a graph, loading graphs, and applying algorithms to them.

To run the demo program, compile it using `make` in the terminal. it will run `Demo.cpp` automatically .
but the main func in `Demo.cpp` closed in comments "//" , so you will need to release it and then compile .
After compiling, it will run the main function provided in `Demo.cpp`.


## Notes

- This implementation assumes that the graph is represented using an adjacency matrix.
- Make sure to handle exceptions for invalid input in the algorithms.
