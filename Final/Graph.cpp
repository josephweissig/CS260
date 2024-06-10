#include "Graph.hpp"
#include <vector>
#include <string>

using std::vector;
using std::string;

template <typename T>
Graph<T>::Graph() {
    nodes = vector<Node<T> >();
}

template <typename T>
int Graph<T>::addNode(T data) {
    Node<T> node;
    node.data = data;
    nodes.push_back(node);
    // We wanna return the index of the node we just added, for the purposes of adding edges.
    return nodes.size() - 1;
}

template <typename T>
void Graph<T>::addEdge(int source, int destination) {
    // For now, we're creating an undirected graph, so we need to add edges in both directions.
    nodes[source].edges.push_back(&nodes[destination]);
    nodes[destination].edges.push_back(&nodes[source]);
}

template <typename T>
string Graph<T>::toString() {
    string result = "";
    for (int i = 0; i < nodes.size(); i++) {
        result += "Node " + std::to_string(i) + " has " + std::to_string(nodes[i].edges.size()) + " edges.\n";
    }
    return result;
}