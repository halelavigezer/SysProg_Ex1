//
// Created by halel on 4/8/25.
//


#ifndef GRAPH_H
#define GRAPH_H

#include "Node_V.h"

namespace graph {
    struct Edge {
        int neighbor;
        int weight;
        Edge *next;


        Edge(int n, int w, Edge *next = nullptr) : neighbor(n), weight(w), next(next) {
        }
    };

    class Graph {
    public:
        int const size;
        Node_V **ArrayNode;
        Edge **ArrayEdge;

        Graph(int size);
        ~Graph();

        void addEdge(int start, int end, int w =1);//?
        void removeEdge(int start, int end);
        void print_graph() const;
        Node_V* getNode(int index);


    };
} // graph

#endif //GRAPH_H
