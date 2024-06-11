#include "Node.hpp"
#include "Edge.hpp"
#include <vector>
#include <string>

using std::vector;
using std::string;

Node::Node(int data) {
    this->data = data;
    edges = new vector<Edge*>();
}

Node::~Node() {
    vector<Edge*>::iterator it;
    for (it = edges->begin(); it != edges->end(); it++) {
        delete *it;
    }
}

int Node::getData() {
    return data;
}

void Node::addEdge(Node* destination, int weight) {
    Edge* edge = new Edge();
    edge->source = this;
    edge->destination = destination;
    edge->weight = weight;
    edges->push_back(edge);
}

vector<Edge*>* Node::getEdges() {
    return edges;
}

string Node::toString() {
    string result = "• Node with data: " + std::to_string(data) + " has " + std::to_string(edges->size()) + " edges:\n";
    vector<Edge*>::iterator it;
    for (it = edges->begin(); it != edges->end(); it++) {
        result += "\t• Edge to " + std::to_string((*it)->destination->getData()) + " with weight " + std::to_string((*it)->weight) + "\n";
    }
    return result;
}