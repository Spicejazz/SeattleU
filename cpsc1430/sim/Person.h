#ifndef SIM_PERSON_H
#define SIM_PERSON_H

#include <string>

class Person {
public:
    Person();
    const int id;
    std::string getName() const;

private:
    std::string name;
    static int nextId;
};


#endif //SIM_PERSON_H
