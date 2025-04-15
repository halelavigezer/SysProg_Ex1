//
// Created by halel on 4/10/25.
//

#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H
#include "Node_V.h"

namespace graph {
    struct PQNode {
        Node_V *data;
        int d;
        Node_V *father;
        PQNode *next;


        PQNode(Node_V * data,int d,Node_V* father, PQNode *next= nullptr ):data(data),d(d),father(father),next(next){}
    };

class PriorityQueue {
public:
    PQNode *root;
    PriorityQueue();
    ~PriorityQueue();
    void insert(Node_V* data, int d, Node_V* father);
    Node_V* extractMin();
    bool isEmpty();

};

} // graph

#endif //PRIORITYQUEUE_H
