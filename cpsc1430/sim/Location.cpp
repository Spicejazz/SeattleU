#include "Location.h"
#include "Person.h"

Location::Location(std::string &name, int capacity)
: name(name)
, capacity(capacity)
, occupants(new Person*[capacity])
, currentOccupancy(0) {
}

bool Location::addPerson(Person &person) {
    if(currentOccupancy == capacity) {
        return false;
    }
    occupants[currentOccupancy] = &person;
    currentOccupancy++;
    return true;
}

bool Location::removePerson(int personId) {
    // find the index of the matching Person*
    int index = indexOfPerson(personId);
    // shift everyone over to cover up space occupied by person
    if(index >= 0) {
        for(int i = index + 1; i < currentOccupancy; i++) {
            occupants[i-1] = occupants[i];
        }
        occupants[currentOccupancy] = nullptr;
        currentOccupancy--;
        return true;
    }
    return false;
}

std::string Location::getName() const {
    return name;
}

bool Location::containsPerson(int personId) const {
    return indexOfPerson(personId) >= 0;
}

int Location::indexOfPerson(int personId) const {
    int index = -1;
    for(int i = 0; index < 0 && i < currentOccupancy; i++) {
        if(occupants[i]->id == personId) {
            index = i;
        }
    }
    return index;
}


