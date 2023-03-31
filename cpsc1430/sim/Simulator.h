#ifndef SIM_SIMULATOR_H
#define SIM_SIMULATOR_H

#include <iostream>
#include "EventQueue.h"

class Simulator {
    EventQueue queue;

public:
    /**
     * Adds an event to the end of the queue of pending events.
     */
    void addEvent(PersonLocationEvent &event);
    /**
     * Attempts to process the first event in the queue of pending
     * events and print the outcome to the given ostream. Will process
     * an event but not print results if ostream is null.
     *
     * Returns true if the event succeeded, false if it failed or there
     * was no event to process.
     */
    bool processEvent(std::ostream *output);
};


#endif //SIM_SIMULATOR_H
