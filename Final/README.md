# CS 260 Final Project

## Graphs

Graphs are sets of nodes, with a set of pairs of nodes creating edges. They are the computerized implementation of graph theory in mathematics, which is used to model anything where individual components are partially defined by their relationships to one another; this broad applicability is why they're so important in many fields like computer science, physics, and the social sciences.

The basic operations we want to fulfill are:

- `adjacent(G, x, y)`: tests whether there is an edge from the node x to the node y.
- `neighbors(G, x)`: lists all nodes that are adjacent to x.
- `addNode(G, x)`: adds the node x.
- `removeNode(G, x)`: removes the node x, if it exists.
- `addEdge(G, x, y, z)`: adds the edge z from the vertex x to the vertex y.
- `removeEdge(G, x, y)`: removes the edge from the vertex x to the vertex y, if it exists.
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
    vector<Node<T> > nodes;
    string toString();
};
```

The `Graph` class holds a vector of `Node` objects, and has functions for adding `Node`s and creating edges between. 
