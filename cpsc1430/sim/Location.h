#ifndef SIM_LOCATION_H
#define SIM_LOCATION_H

#include <string>

class Person;

class Location {
public:
    Location(std::string &name, int capacity);
    /**
     * Attempts to add the given person to the list of occupants
     * in this location.
     * @return true if the person is now in the location, false
     *   if this location was already full
     */
    bool addPerson(Person &);
    /**
     * Attempts to remove a person from this location whose id
     * matches the given value.
     * @param personId - the id of the person to remove
     * @return true if the person was in the room, false otherwise
     */
    bool removePerson(int personId);
    std::string getName() const;
    bool containsPerson(int personId) const;

private:
    const std::string name;
    int capacity;
    Person **occupants;
    int currentOccupancy;

    int indexOfPerson(int personId) const;
};


#endif //SIM_LOCATION_H
