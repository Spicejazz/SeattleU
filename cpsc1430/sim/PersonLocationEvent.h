#ifndef SIM_PERSONLOCATIONEVENT_H
#define SIM_PERSONLOCATIONEVENT_H

class Person;
class Location;

class PersonLocationEvent {
public:
    PersonLocationEvent(Person &, Location &, bool);
    bool apply();
    const bool isEnterEvent;
    const Person & getPerson() const;
    const Location & getLocation() const;
private:
    Person &person;
    Location &location;
};


#endif //SIM_PERSONLOCATIONEVENT_H
