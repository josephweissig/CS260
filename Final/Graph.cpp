#include "Graph.hpp"
#include "Edge.hpp"
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <limits>

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

std::unordered_map<int, int> Graph::dijkstra(int root) {
    std::unordered_map<int, int> distances;
    for (int i = 0; i < nodes->size(); i++) {
        distances[i] = INT_MAX;
    }
    distances[root] = 0;

    std::priority_queue<std::pair<int, int>, vector<std::pair<int, int> >, std::greater<std::pair<int, int> > > queue;
queue.push(std::make_pair(0, root));
while (!queue.empty()) {
        int current = queue.top().second;
        queue.pop();

        for (auto& edge : *nodes->at(current)->getEdges()) {
            int destination = edge->destination->getData();
            int weight = edge->weight;
            if (distances[current] + weight < distances[destination]) {
                distances[destination] = distances[current] + weight;
                queue.push(std::make_pair(distances[destination], destination));
            }
        }
    }
    return distances;
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