#include "Graph.hpp"
#include "Edge.hpp"
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <limits>
#include <algorithm>

using std::vector;
using std::string;

// It's probably bad form to keep a struct like this in a mostly-unrelated file,
// but I'm doing it for the sake of brevity.
struct CompareEdges {
    bool operator()(const Edge* a, const Edge* b) const {
        return a->weight < b->weight;
    }
};

Graph::Graph() {
    nodes = new vector<Node*>;
    edges = new vector<Edge*>;
}

Graph::~Graph() {
    vector<Node*>::iterator it;
    for (it = nodes->begin(); it != nodes->end(); it++) {
        delete *it;
    }
    delete nodes;

    vector<Edge*>::iterator it2;
    for (it2 = edges->begin(); it2 != edges->end(); it2++) {
        delete *it2;
    }
    delete edges;
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

    // We also need to add the edge to the edges vector for Kruskal's algorithm
    Edge* edge = new Edge();
    edge->source = nodes->at(source);
    edge->destination = nodes->at(destination);
    edge->weight = weight;
    edges->push_back(edge);
}

std::unordered_map<int, int> Graph::dijkstra(int root) {
    // Initialize the distances to all nodes as infinity,
    // except for the root node, which is 0 by definition.
    std::unordered_map<int, int> distances;
    for (int i = 0; i < nodes->size(); i++) {
        distances[i] = INT_MAX;
    }
    distances[root] = 0;

    // Initialize the priority queue with the root node
    // (A priority queue is a min-heap by default, so we're using std::greater to make it a max-heap.)
    std::priority_queue<std::pair<int, int>, vector<std::pair<int, int> >, std::greater<std::pair<int, int> > > queue;
    queue.push(std::make_pair(0, root));
    while (!queue.empty()) {
        // Get the node with the smallest distance
        int current = queue.top().second;
        queue.pop();

        // Iterate through the edges of the current node
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

vector<Edge*> Graph::kruskal() {
    vector<Edge*> toReturn;

    // Sort the edges by weight
    std::sort(edges->begin(), edges->end(), CompareEdges());

    // Initialize the disjoint set
    for (int i = 0; i < nodes->size(); i++) {
        nodes->at(i)->setParent(nullptr);
        nodes->at(i)->setRank(0);
    }

    // Iterate through the edges
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

// Finds the root of a Node object
Node* Graph::find(Node* node) {
    if (node->getParent() == nullptr) {
        return node;
    }
    return find(node->getParent());
}

// Unites two Node objects into the same set
void Graph::unionize(Node* a, Node* b) {
    Node* aRoot = find(a);
    Node* bRoot = find(b);
    if (aRoot->getRank() < bRoot->getRank()) {
        aRoot->setParent(bRoot);
    } else if (aRoot->getRank() > bRoot->getRank()) {
        bRoot->setParent(aRoot);
    } else {
        bRoot->setParent(aRoot);
        aRoot->setRank(aRoot->getRank() + 1);
    }
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