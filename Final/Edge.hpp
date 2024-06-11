#pragma once

#include "Node.hpp"

struct Edge {
    Node* source;
    Node* destination;
    int weight;
};