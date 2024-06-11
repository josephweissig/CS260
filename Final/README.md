# CS 260 Final Project

## Graphs

Graphs are sets of nodes, with a set of pairs of nodes creating edges. They are the computerized implementation of graph theory in mathematics, which is used to model anything where individual components are partially defined by their relationships to one another; this broad applicability is why they're so important in many fields like computer science, physics, and the social sciences.

The basic operations we want to fulfill are:

- `adjacent(G, x, y)`: tests whether there is an edge from the node x to the node y.
- `neighbors(G, x)`: lists all nodes that are adjacent to x.
- `addNode(G, x)`: adds the node x.
- `addEdge(G, x, y, z)`: adds the edge z from the vertex x to the vertex y.
- `getNodeValue(G, x)`: returns the value associated with node x.
- `setNodeValue(G, x, v)`: sets the value associated with node x to v.

(Shamelessly [stolen from Wikipedia](https://en.wikipedia.org/wiki/Graph_(abstract_data_type)#Operations))

## C++ Graph program structure

### Node structure

```cpp
#include <vector>

template <typename T>
struct Node {
    T data;
    std::vector<Node<T>*> edges;
};
```

A generic `Node` struct lets us store whatever kind of data we want. This is maybe the most simplistic implementation we could construct, with a single `Node` object holding onto its value and edges. We're using a `std::vector` here to save us time and effort from creating an extensible array or list; for our purposes, a `vector` will be fast enough while being flexible enough for any demo graph.

### Graph class

```cpp
#include <vector>
#include <string>

template <typename T>
class Graph {
public:
    Graph();
    int addNode(T data);
    void addEdge(int source, int destination);
    unordered_map<int, int> dijkstra(int root);
    vector<Edge*> kruskal();
    vector<Node*>* getNodes();
    string toString();
private:
    vector<Node*> *nodes;
    vector<Edge*> *edges;
    Node* find(Node* node);
    void unionize(Node* a, Node* b);
};
```

The `Graph` class holds a vector of `Node` objects, and has functions for adding `Node`s and creating edges between. It also holds the methods for getting structures related to Dijkstra's and Kruskal's algorithms, along with related private utility functions for those.

## Algorithms

### Dijkstra's algorithm

```cpp
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
```

This is an algorithm for finding the shortest path between nodes when the graph is weighted (numerical values tied to edges). Worst-case, it runs in O(n^2) time, where n is the number of nodes, since it's looping through each node, and with each node it's finding the shortest path to connected nodes.

### Kruskal's algorithm

```cpp
vector<Edge*> Graph::kruskal() {
    vector<Edge*> toReturn;

    std::sort(edges->begin(), edges->end(), CompareEdges());

    for (int i = 0; i < nodes->size(); i++) {
        nodes->at(i)->setParent(nullptr);
        nodes->at(i)->setRank(0);
    }

    for (int i = 0; i < edges->size(); i++) {
        Node* source = edges->at(i)->source;
        Node* destination = edges->at(i)->destination;
        if (source == nullptr || destination == nullptr) {
            continue;
        }
        if (find(source) != find(destination)) {
            toReturn.push_back(edges->at(i));
            unionize(source, destination);
        }
    }

    return toReturn;
}
```

This is an algorithm for finding a minimum spanning tree in a connected, edge-weighted graph, where a minimum spanning tree is the set of edges that connect all nodes together with the minimum possible total edge weight. It runs in O(n log n) time, where n is the number of edges; when the edges are sorted by weight in O(n log n) time, the rest of the algorithm can run in essentially-constant time, so the complexity can be simplified to just the sorting step.

## Testing

[Example graph](<graph example.jpg>)

The above example graph is recreated in `main.cpp`, where each `Node` and `Edge` is added to the graph manually. We then print out the graph, which writes the held value of each `Node` as well as all connected `Edge`s.

We then print the Dijkstra algorithm (with root at `Node` 0), which should match the green notes on the example graph.

Then we print the Kruskal minimum spanning tree, which should match the following:

[Kruskal output](<kruskal output.png>)
