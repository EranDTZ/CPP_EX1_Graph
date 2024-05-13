#include <iostream>
#include <vector>
#include <stdexcept>
#include "Graph.hpp"

//Eran David Tzarum
//ID:207640806

using namespace std;


Graph::Graph() {
}


Graph::~Graph() {}


void Graph::addEdge(int src, int dest) {
    if (src < 0 || src >= numVertices || dest < 0 || dest >= numVertices) {
        throw std::invalid_argument("Invalid node");
    }
    if ((adjMatrix[static_cast<size_t>(src)][static_cast<size_t>(dest)] == 0) && 
        (adjMatrix[static_cast<size_t>(dest)][static_cast<size_t>(src)] == 0)) {
        adjMatrix[static_cast<size_t>(src)][static_cast<size_t>(dest)] = 1;
        adjMatrix[static_cast<size_t>(dest)][static_cast<size_t>(src)] = 1;
    } else {
        cout << "Existing edge" << endl;
    }
}



void Graph::loadGraph(const vector<vector<int>>& graph) {
    for (const auto& row : graph) {
        if (row.size() != graph.size()) {
            throw std::invalid_argument("All rows must be of equal length");
        }
    }

    numVertices = graph.size();
    adjMatrix.resize(graph.size(), vector<int>(graph.size()));

    for (std::vector<int>::size_type i = 0; i < graph.size(); i++) {
        for (std::vector<int>::size_type j = 0; j < graph[i].size(); j++) {
            adjMatrix[i][j] = graph[i][j];
            if(graph[i][j] != graph[j][i]){
                directed = true;
            }
        }
    }
}



void Graph::printGraph(){
    for (std::vector<int>::size_type i = 0; i < adjMatrix.size(); i++) {
        for (std::vector<int>::size_type j = 0; j < adjMatrix[i].size(); j++) {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }
}



int Graph::getNumVertices() const {
    return numVertices;
}



std::vector<int> Graph::getNeighbors(int vertex) const {
    if (vertex < 0 || vertex >= numVertices) {
        throw std::invalid_argument("Invalid vertex");
    }
    return adjMatrix[static_cast<std::vector<int>::size_type>(vertex)];
}



int Graph::getAdjMatrix(int current, int neighbor) const {
    if (current < 0 || current >= numVertices || neighbor < 0 || neighbor >= numVertices) {
        return -1; //invalid V;
    }
    return adjMatrix[static_cast<std::vector<int>::size_type>(current)][static_cast<std::vector<int>::size_type>(neighbor)];
}

std::vector<std::vector<int>> Graph::getAdjMatrix() const{
    return adjMatrix;
}

bool Graph:: getDirected() const {
    return directed;
}