#include "PersonLocationEvent.h"
#include "Location.h"
#include "Person.h"

PersonLocationEvent::PersonLocationEvent(Person &person, Location &location, bool isEnterEvent)
: isEnterEvent(isEnterEvent)
, person(person)
, location(location) {
}

bool PersonLocationEvent::apply() {
    if(isEnterEvent) {
        return location.addPerson(person);
    } else {
        return location.removePerson(person.id);
    }
}

const Person &PersonLocationEvent::getPerson() const {
    return person;
}

const Location &PersonLocationEvent::getLocation() const {
    return location;
}

