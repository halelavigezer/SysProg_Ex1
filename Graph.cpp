#include "Graph.h"
#include <iostream>

namespace graph {
    Graph::Graph(int size): size(size) {
        ArrayNode = new Node_V *[size];
        for (int i = 0; i < size; ++i) {
            ArrayNode[i] = new Node_V(i);
        }
        ArrayEdge = new Edge *[size];
        for (int i = 0; i < size; ++i) {
            ArrayEdge[i] = nullptr;
        }
    }

    Graph::~Graph() {
        for (int i = 0; i < size; ++i) {
            Edge *e = ArrayEdge[i];
            while (e != nullptr) {
                Edge *temp = e;
                e = e->next;
                delete temp;
            }
        }
        delete[] ArrayNode;
        delete[] ArrayEdge;
    }

    void Graph::addEdge(int start, int end, int weight) {
        if (start < 0 || start >= size || end < 0 || end >= size)
            throw "Index is out of range";

        ArrayEdge[start] = new Edge(end, weight, ArrayEdge[start]);
        ArrayEdge[end] = new Edge(start, weight, ArrayEdge[end]);
    }

    void Graph::removeEdge(int start, int end) {
        if (start < 0 || start >= size || end < 0 || end >= size)
            throw "Index is out of range";

        // Removing edge start → end
        Edge* s = ArrayEdge[start];
        Edge* before = nullptr;
        while (s != nullptr) {
            if (s->neighbor == end) {
                if (before == nullptr) {
                    ArrayEdge[start] = s->next;
                } else {
                    before->next = s->next;
                }
                delete s;
                break;
            }
            before = s;
            s = s->next;
        }

        // Removing edge end → start
        Edge* s1 = ArrayEdge[end];
        Edge* before1 = nullptr;
        while (s1 != nullptr) {
            if (s1->neighbor == start) {
                if (before1 == nullptr) {
                    ArrayEdge[end] = s1->next;
                } else {
                    before1->next = s1->next;
                }
                delete s1;
                break;
            }
            before1 = s1;
            s1 = s1->next;
        }
    }

    void Graph::print_graph() const {
        for (int i = 0; i < size; ++i) {
            Edge * temp = ArrayEdge[i];
            while (temp != nullptr) {
                if (temp->neighbor > i) {
                    std::cout  <<  "e( "<< i << ", "<< temp->neighbor << " )" << std::endl;
                }
                temp = temp->next;
            }
        }
    }


    Node_V* Graph::getNode(int index) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index is out of range");
        }
        return ArrayNode[index];
    }
} // graph
