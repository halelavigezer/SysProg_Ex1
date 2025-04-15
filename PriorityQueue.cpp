//
// Created by halel on 4/10/25.
//

#include "PriorityQueue.h"


namespace graph {
    PriorityQueue::PriorityQueue():root(nullptr) {}
    void PriorityQueue::insert(Node_V* data, int d, Node_V* father) {
        PQNode* newNode = new PQNode(data, d, father);
        if (root == nullptr || d < root->d) {
            newNode->next = root;
            root = newNode;
            return;
        }
        // מציאת המקום המתאים
        PQNode* current = root;
        while (current->next != nullptr && current->next->d <= d) {
            current = current->next;
        }

        newNode->next = current->next;
        current->next = newNode;
    }
    Node_V* PriorityQueue::extractMin() {
        if (isEmpty()) {
            return nullptr;
        }

        PQNode* temp = root;
        root = root->next;

        Node_V* result = temp->data;
        delete temp;

        return result;
    }
    bool PriorityQueue::isEmpty() {
        return root == nullptr;
    }
    PriorityQueue::~PriorityQueue() {
        while (root != nullptr) {
            PQNode* temp = root;
            root = root->next;
            delete temp;
        }
    }









} // graph