#include "Node.hpp"
#include "Graph.cpp"
#include <iostream>

using std::cout;
using std::endl;

int main() {
    Graph<int> graph;
    graph.addNode(1);
    graph.addNode(2);
    graph.addNode(3);
    graph.addEdge(0, 1);
    graph.addEdge(1, 2);
    cout << "Graph has " << graph.nodes.size() << " nodes." << endl;
    cout << graph.toString();
    return 0;
}