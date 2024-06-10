#ifndef _GRAPHHPP_
#define _GRAPHHPP_

#include <vector>
#include <string>
#include "Node.hpp"

using std::string;
using std::vector;

template <typename T>
class Graph {
public:
    Graph();
    int addNode(T data);
    void addEdge(int source, int destination);
    vector<Node<T> > nodes;
    string toString();
};

#endif // _GRAPHHPP_