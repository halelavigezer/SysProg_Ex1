//
// Created by halel on 4/9/25.
//

#include "Queue.h"

namespace graph {
    Queue::Queue(nood_help *head, nood_help *tail) : head(head), tail(tail), size(0) {}

    void Queue::enqueue(Node_V* node) {
        nood_help* newNode = new nood_help(node); // יצירת איבר חדש
        if (isEmpty()) {
            head = newNode; // אם הטור ריק, העבר את הראש
            tail = newNode; // והקצה הוא גם האיבר החדש
        } else {
            tail->nextU = newNode; // חיבור האיבר החדש לסוף הטור
            newNode->prevU = tail;  // עדכון הקצה הקודם
            tail = newNode; // עדכון הקצה לטווח החדש
        }
        size++; // עדכון גודל הטור
    }

    Node_V* Queue::dequeue() {
        if (isEmpty()) throw "Queue is empty"; // אם ריק, זרוק שגיאה
        nood_help* temp = head; // שמירת הראש
        Node_V* node = temp->orignal_nood; // שמירה על הערך של הראש
        head = head->nextU; // עדכון הראש

        if (head != nullptr) {
            head->prevU = nullptr; // אם יש איבר חדש, עדכן את הקצה הקודם
        } else {
            tail = nullptr; // אם הסרנו את האחרון, גם הקצה נעשה nullptr
        }

        delete temp; // שחרור הזיכרון
        size--; // עדכון הגודל
        return node; // החזרת הערך שהוסר
    }

    bool Queue::isEmpty() {
        return size == 0; // אם הגודל 0, אז ריק
    }

    Queue::~Queue() {
        while (!isEmpty()) {
            dequeue(); // הסרת כל האיברים מהטור ושחרור הזיכרון
        }
    }

} // graph
