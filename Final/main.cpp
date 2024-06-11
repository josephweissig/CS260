#include "Graph.hpp"
#include "Edge.hpp"
#include <iostream>

using std::cout;
using std::endl;

int main() {
    // Create the example graph from the image in the repo:
    Graph graph;
    graph.addNode(0);
    graph.addNode(1);
    graph.addNode(2);
    graph.addNode(3);
    graph.addNode(4);
    graph.addNode(5);
    graph.addNode(6);
    graph.addNode(7);
    graph.addNode(8);

    graph.addEdge(0, 1, 2);
    graph.addEdge(0, 2, 4);
    graph.addEdge(0, 3, 20);
    graph.addEdge(1, 2, 3);
    graph.addEdge(1, 4, 8);
    graph.addEdge(2, 3, 14);
    graph.addEdge(2, 5, 7);
    graph.addEdge(3, 5, 9);
    graph.addEdge(3, 6, 5);
    graph.addEdge(4, 7, 3);
    graph.addEdge(5, 4, 6);
    graph.addEdge(5, 7, 7);
    graph.addEdge(5, 8, 2);
    graph.addEdge(5, 6, 8);
    graph.addEdge(6, 8, 8);
    graph.addEdge(7, 8, 4);

    cout << graph.toString() << endl;

    unordered_map<int, int> distances = graph.dijkstra(0);
    unordered_map<int, int>::iterator it;
    for (it = distances.begin(); it != distances.end(); it++) {
        cout << "Distance to node " << it->first << ": " << it->second << endl;
    }

    vector<Edge*> mst = graph.kruskal();
    cout << endl << "Minimum spanning tree:" << endl;
    for (int i = 0; i < mst.size(); i++) {
        cout << "Edge from " << mst[i]->source->getData() << " to " << mst[i]->destination->getData() << " with weight " << mst[i]->weight << endl;
    }

    return 0;
}