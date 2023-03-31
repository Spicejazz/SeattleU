#ifndef SPECIES_H
#define SPECIES_H
#include <string>

struct Species {
  std::string name;
  int ageThresholds[5];
  int foodConsumption;
  bool likesBaths;
};

static const int NUM_SPECIES = 6;
static const Species SPECIES[] = {
        { "Mayfly", {1, 2, 5, 16, 20}, 5, false },
        { "Elephant", {20, 100, 250, 600, 800}, 40, true },
        {"Dog", {1, 3, 5, 10, 15}, 10, true},
        {"Cat", {1, 3, 6, 12, 18}, 8, false},
        {"Penguin", {2, 4, 6, 8, 10}, 8, true},
        {"Parrot", {1, 4, 6, 9, 12}, 6, false}
};

// ages: egg, baby, adolescent, adult, elder
// age thresholds are when they transition _out_ of that age
static const int NUM_AGE_GROUPS = 5;
static const std::string AGE_GROUPS[NUM_AGE_GROUPS] = {
                                                       "egg",
                                                       "baby",
                                                       "adolescent",
                                                       "adult",
                                                       "elder"
};

#endif //SPECIES_H
