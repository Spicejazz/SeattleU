#ifndef EGGBYTES_H
#define EGGBYTES_H

#include <string>
#include "Creature.h"

class Farm {
public:
    const static int MAX_CREATURES = 4;

    int getNumCreatures() const;
    Creature * getCreature(int) const;
    bool canAddCreature() const;
    void advance();
    int addCreature(Creature *);
    void removeCreature(int index);
    Farm();

private:
    Creature * creatures[MAX_CREATURES];
    int numCreatures = 0;
};

#endif //EGGBYTES_H
