#include "Simulator.h"
#include "Person.h"
#include "Location.h"

using namespace std;

void Simulator::addEvent(PersonLocationEvent &event) {
    queue.enqueue(event);
}

bool Simulator::processEvent(ostream *output) {
    if(queue.isEmpty()) {
        if(output != nullptr) {
            *output << "Cannot process any more events; queue is empty.";
        }
        return false;
    }

    PersonLocationEvent event = queue.dequeue();
    string verb;
    if(event.isEnterEvent) {
        verb = "enter";
    } else {
        verb = "exit";
    }
    bool succeeded = event.apply();
    if(output != nullptr) {
        if (succeeded) {
            *output << event.getPerson().getName() << " " << verb << "ed "
                   << event.getLocation().getName() << endl;
        } else {
            *output << event.getPerson().getName() << " was unable to "
                   << verb << " " << event.getLocation().getName() << endl;
        }
    }
    return succeeded;
}
