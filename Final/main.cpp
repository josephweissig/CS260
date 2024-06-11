#include "Graph.hpp"
#include <iostream>

using std::cout;
using std::endl;

int main() {
    Graph graph;
    graph.addNode(1);
    graph.addNode(2);
    graph.addNode(3);
    graph.addEdge(0, 1, 5);
    graph.addEdge(1, 2, 3);
    cout << graph.toString();
    return 0;
}