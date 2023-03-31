#include "Person.h"

int Person::nextId = 0;

// assigns nextId to id, then increments nextId for the next person
Person::Person() : id(nextId++) {

}

std::string Person::getName() const {
    return name;
}
