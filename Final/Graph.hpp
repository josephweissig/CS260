#pragma once

#include <vector>
#include <string>
#include <unordered_map>
#include "Node.hpp"

using std::string;
using std::vector;
using std::unordered_map;

class Graph {
public:
    Graph();
    ~Graph();

    int addNode(int data);
    void addEdge(int source, int destination, int weight);

    unordered_map<int, int> dijkstra(int root);
    vector<Edge*> kruskal();

    vector<Node*>* getNodes();

    string toString();
private:
    vector<Node*> *nodes;
    // Adding a vector for edges for use in Kruskal's algorithm
    vector<Edge*> *edges;
    Node* find(Node* node);
    void unionize(Node* a, Node* b);
};