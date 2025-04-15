//
// Created by halel on 4/8/25.
//

#include "Node_V.h"

namespace graph {
    Node_V::Node_V(int data): data(data){
    }
    Node_V::Node_V() : data(-1) {}

    int Node_V::getData() const {
        return data;
    }


} // graph