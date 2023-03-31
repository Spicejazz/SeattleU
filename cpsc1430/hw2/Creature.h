#ifndef CREATURE_H
#define CREATURE_H

#include <string>
#include "Species.h"

static const int MAX_ATTRIBUTE_VALUE = 1000;

class Creature {
public:
  const Species &species;
  
  static std::string generateName();
  Creature(const Species &species, const std::string &name);
  std::string getDetails() const;
  std::string getName() const;
  bool canCreateEgg() const;
  bool isAlive() const;
  bool wantsToRunAway() const;
  void clean();
  void feed();
  void rename(const std::string &nName);
  void advance();
  std::string getAgeStage() const;
private:
  std::string name;
  int age;
  int happiness;
  int fullness;
  int cleanliness;
};


#endif //CREATURE_H
