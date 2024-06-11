#include "Graph.hpp"
#include <vector>
#include <string>

using std::vector;
using std::string;

Graph::Graph() {
    nodes = new vector<Node*>;
}

Graph::~Graph() {
    vector<Node*>::iterator it;
    for (it = nodes->begin(); it != nodes->end(); it++) {
        delete *it;
    }
    delete nodes;
}

int Graph::addNode(int data) {
    Node* node = new Node(data);
    nodes->push_back(node);
    // We wanna return the index of the node we just added, for the purposes of adding edges.
    return nodes->size() - 1;
}

void Graph::addEdge(int source, int destination, int weight) {
    // We're not doing an undirected graph anymore, so we need to change up how we're adding edges;
    // nodes[source].edges.push_back(&nodes[destination]);
    // nodes[destination].edges.push_back(&nodes[source]);
    nodes->at(source)->addEdge(nodes->at(destination), weight);
}

vector<Node*>* Graph::getNodes() {
    return nodes;
}

string Graph::toString() {
    string result = "";
    for (int i = 0; i < nodes->size(); i++) {
        result += nodes->at(i)->toString();
    }
    return result;
}