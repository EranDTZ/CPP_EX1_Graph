#include "doctest.h"
#include "Algorithms.hpp"
#include "Graph.hpp"

using namespace std;

//Eran David Tzarum
//ID:207640806

TEST_CASE("Graph loadGraph and getAdjMatrix test") {
    Graph g;
    std::vector<std::vector<int>> graph = {
        {0, 1, 0, 1},
        {1, 0, 1, 0},
        {0, 1, 0, 1},
        {1, 0, 1, 0}
    };
    g.loadGraph(graph);
    auto adjMatrix = g.getAdjMatrix();

    CHECK_EQ(adjMatrix, graph);
}

TEST_CASE("Graph getNumVertices test") {
    Graph g;
    g.loadGraph({{0, 1, 0}, {1, 0, 0}, {0, 0, 0}});
    CHECK_EQ(g.getNumVertices(), 3);
}

TEST_CASE("Graph getNeighbors test") {
    Graph g;
    g.loadGraph({{0, 1, 0}, {1, 0, 1}, {0, 1, 0}});
    auto neighbors = g.getNeighbors(1);

    std::vector<int> expected = {1, 0, 1};
    CHECK_EQ(neighbors, expected);
}

TEST_CASE("Graph getAdjMatrix test") {
    Graph g;
    std::vector<std::vector<int>> graph = {
        {0, 3, 0},
        {1, 0, 5},
        {0, 9, 0}
    };
    g.loadGraph(graph);
    auto adjMatrix = g.getAdjMatrix();

    CHECK_EQ(adjMatrix, graph);
}

TEST_CASE("Graph getDirected test") {
    Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {0, 0, 1},
        {0, 0, 0}};

    g.loadGraph(graph);
    CHECK(g.getDirected() == true);

    g.loadGraph({{0, 4, 0}, {1, 0, 0}, {0, 0, 0}});
    CHECK(g.getDirected() == true);
}

TEST_CASE("Graph invalid getNeighbors test") {
    Graph g;
    g.loadGraph({{0, 1, 0}, {1, 0, 0}, {0, 0, 0}});
    CHECK_THROWS(g.getNeighbors(-1));
    CHECK_THROWS(g.getNeighbors(3));
}

TEST_CASE("Graph invalid getAdjMatrix test") {
    Graph g;
    g.loadGraph({{0, 1, 0}, {1, 0, 0}, {0, 0, 0}});
    CHECK_EQ(g.getAdjMatrix(0, 3), -1);
    CHECK_EQ(g.getAdjMatrix(3, 0), -1);
}

TEST_CASE("Algorithms isConnected test") {
    Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0, 1},
        {1, 0, 1, 0},
        {0, 1, 0, 1},
        {1, 0, 1, 0}};
    g.loadGraph(graph);
    CHECK(Algorithms::isConnected(g) == true);

    g.loadGraph({{0, 1, 0}, {1, 0, 1}, {0, 1, 0}});
    CHECK(Algorithms::isConnected(g) == true);
}

TEST_CASE("Algorithms shortestPath test") {
    Graph g;
    vector<vector<int>> graph = {
    {0, 1, 0, 0, 0},
    {1, 0, 1, 0, 0},
    {0, 1, 0, 1, 0}, 
    {0, 0, 1, 0, 1},
    {0, 0, 0, 1, 0}};

    g.loadGraph(graph);
    CHECK_EQ(Algorithms::shortestPath(g, 0, 4), "0->1->2->3->4");
    CHECK_EQ(Algorithms::shortestPath(g, 1, 3), "1->2->3");
    CHECK_EQ(Algorithms::shortestPath(g, 0, 2), "0->1->2");
}

TEST_CASE("Algorithms isContainsCycle test") {
    Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0, 0},
        {1, 0, 1, 0},
        {0, 1, 0, 1},
        {0, 0, 1, 0}};
    g.loadGraph({{0, 1, 0, 0}, {1, 0, 1, 0}, {0, 1, 0, 1}, {0, 0, 1, 0}});
    CHECK(Algorithms::isContainsCycle(g) == false);

    g.loadGraph({{0, 1, 0, 0}, {1, 0, 1, 1}, {0, 1, 0, 1}, {0, 1, 1, 0}});
    CHECK(Algorithms::isContainsCycle(g) == true);
}

TEST_CASE("Algorithms isBipartite test") {
    Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK_EQ(Algorithms::isBipartite(g), "The graph is bipartite: A={0, 2}, B={1}");
}

TEST_CASE("Algorithms isBipartite test 2") {
    Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0, 0},
        {1, 0, 1, 1},
        {0, 1, 0, 1},
        {0, 1, 1, 0}};
    g.loadGraph({{0, 1, 0, 0}, {1, 0, 1, 1}, {0, 1, 0, 1}, {0, 1, 1, 0}});
    CHECK_EQ(Algorithms::isBipartite(g), "0");

}

TEST_CASE("Test isConnected")
{
    // ariel::Graph g;
    Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    // CHECK(ariel::Algorithms::isConnected(g) == true);
    CHECK(Algorithms::isConnected(g) == true);

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    // CHECK(ariel::Algorithms::isConnected(g) == false);
    CHECK(Algorithms::isConnected(g) == false);
}

TEST_CASE("Test shortestPath")
{
    // ariel::Graph g;
    Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    // CHECK(ariel::Algorithms::shortestPath(g, 0, 2) == "0->1->2");
    CHECK(Algorithms::shortestPath(g, 0, 2) == "0->1->2");

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    // CHECK(ariel::Algorithms::shortestPath(g, 0, 4) == "-1");
    CHECK(Algorithms::shortestPath(g, 0, 4) == "-1");
}
TEST_CASE("Test isContainsCycle")
{
    // ariel::Graph g;
    Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    // CHECK(ariel::Algorithms::isContainsCycle(g) == false);
    CHECK(Algorithms::isContainsCycle(g) == false);


    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    // CHECK(ariel::Algorithms::isContainsCycle(g) == true);
    CHECK(Algorithms::isContainsCycle(g) == true);
}
TEST_CASE("Test isBipartite")
{
    // ariel::Graph g;
    Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    // CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 2}, B={1}");
    CHECK(Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 2}, B={1}");


    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    // CHECK(ariel::Algorithms::isBipartite(g) == "0");
    CHECK(Algorithms::isBipartite(g) == "0");

    vector<vector<int>> graph3 = {
        {0, 1, 2, 0, 0},
        {1, 0, 3, 0, 0},
        {2, 3, 0, 4, 0},
        {0, 0, 4, 0, 5},
        {0, 0, 0, 5, 0}};
    g.loadGraph(graph3);
    // CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 2, 4}, B={1, 3}");
    CHECK(Algorithms::isBipartite(g) == "0");
}
TEST_CASE("Test invalid graph")
{
    // ariel::Graph g;
    Graph g;
    vector<vector<int>> graph = {
        {0, 1, 2, 0},
        {1, 0, 3, 0},
        {2, 3, 0, 4},
        {0, 0, 4, 0},
        {0, 0, 0, 5}};
    CHECK_THROWS(g.loadGraph(graph));
}
