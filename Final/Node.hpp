#pragma once

#include <vector>
#include <string>

using std::vector;
using std::string;

struct Edge;
class Node {
public:
    Node(int data);
    ~Node();

    int getData();

    void addEdge(Node* destination, int weight);
    vector<Edge*> *getEdges();

    string toString();
private:
    int data;
    vector<Edge*> *edges;
};