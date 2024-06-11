#pragma once

#include <vector>
#include <string>
#include "Node.hpp"

using std::string;
using std::vector;

class Graph {
public:
    Graph();
    ~Graph();

    int addNode(int data);
    void addEdge(int source, int destination, int weight);

    vector<Node*> *getNodes();

    string toString();
private:
    vector<Node*> *nodes;
};