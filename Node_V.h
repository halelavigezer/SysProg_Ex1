//
// Created by halel on 4/8/25.
//

#ifndef NODE_V_H
#define NODE_V_H

namespace graph {

class Node_V {
private:
    int data;
public:

    Node_V(int data);
    Node_V(); // בנאי ברירת מחדל
    int getData() const;

};

} // graph

#endif //NODE_V_H
