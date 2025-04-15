#ifndef QUEUE_H
#define QUEUE_H
#include "Node_V.h"

namespace graph {
    struct nood_help {
        Node_V* orignal_nood;
        nood_help* nextU;
        nood_help* prevU;


        nood_help(Node_V* orignal_nood, nood_help* nextU = nullptr, nood_help* prevU = nullptr)
            : orignal_nood(orignal_nood), nextU(nextU), prevU(prevU) {}
    };

    class Queue {
    public:
        nood_help* head;
        nood_help* tail;
        int size;
        Queue(nood_help* head = nullptr, nood_help* tail = nullptr);

        void enqueue(Node_V* node);
        Node_V* dequeue();
        bool isEmpty();
        ~Queue();

    };

} // graph

#endif //QUEUE_H
