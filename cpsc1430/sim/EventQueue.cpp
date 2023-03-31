#include "EventQueue.h"

void EventQueue::enqueue(PersonLocationEvent &event) {
    Node *newNode = new EventQueue::Node { event, nullptr };
    if(tail == nullptr) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

PersonLocationEvent EventQueue::dequeue() {
    if(head == nullptr) {
        throw EmptyQueue();
    }
    PersonLocationEvent event = head->event;
    Node *toRemove = head;
    if(head == tail) {
        head = tail = nullptr;
    } else {
        head = head->next;
    }
    delete toRemove;
    return event;
}

bool EventQueue::isEmpty() const {
    return tail == nullptr;
}
