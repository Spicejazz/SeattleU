#ifndef SIM_EVENTQUEUE_H
#define SIM_EVENTQUEUE_H

#include <exception>
#include "PersonLocationEvent.h"

class EventQueue {
public:
    void enqueue(PersonLocationEvent &);
    PersonLocationEvent dequeue();
    bool isEmpty() const;

    class EmptyQueue : public std::exception {};
private:
    struct Node {
        PersonLocationEvent event;
        Node *next;
    };
    Node *head = nullptr;
    Node *tail = nullptr;
};


#endif //SIM_EVENTQUEUE_H
