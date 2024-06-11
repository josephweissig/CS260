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
    Node* getParent();
    void setParent(Node* parent);
    int getRank();
    void setRank(int rank);

    void addEdge(Node* destination, int weight);
    vector<Edge*> *getEdges();

    string toString();
private:
    int data;
    // Added parent and rank properties for Kruskal's algorithm
    Node* parent;
    int rank;
    vector<Edge*> *edges;
};