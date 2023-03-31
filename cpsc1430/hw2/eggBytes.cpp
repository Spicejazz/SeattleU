#include <string>
#include <iostream>
#include "eggBytes.h"

using namespace std;

Farm::Farm() {
    for(int i = 0; i < MAX_CREATURES; i++) {
        creatures[i] = nullptr;
    }
}

int Farm::getNumCreatures() const {
    return numCreatures;
}

Creature *Farm::getCreature(int index) const {
    if(index < 0 || index >= numCreatures) {
        return nullptr;
    }
    return creatures[index];
}

void Farm::advance() {
    for(int i = 0; i < MAX_CREATURES; i++) {
        Creature *creature = creatures[i];
        if(creature == nullptr) {
            continue;
        }
        creature->advance();
        cout << creature->getDetails() << endl;
        if(!creature->isAlive()) {
            cout << creature->getName() << " has died :(" << endl;
            removeCreature(i);
            return;
        }
        if(creature->wantsToRunAway()) {
            cout << creature->getName() << " has run away :(" << endl;
            removeCreature(i);
            return;
        }
        if(numCreatures < MAX_CREATURES && creature->canCreateEgg() && rand() % 100 == 1) {
            Creature *child = new Creature(creature->species,  Creature::generateName());
            int newChildIndex = addCreature(child);
            if(newChildIndex == -1) {
                delete child;
            } else {
                cout << creature->getName() << " had a baby! Say hi to " << child->getName() << endl;
            }
        }
    }
}

bool Farm::canAddCreature() const {
    return numCreatures < MAX_CREATURES;
}

int Farm::addCreature(Creature *creature) {
    if(canAddCreature()) {
        for(int i = 0; i < MAX_CREATURES; i++) {
            if(creatures[i] == nullptr) {
                creatures[numCreatures] = creature;
                numCreatures++;
                return i;
            }
        }
    }
    return -1;
}

void Farm::removeCreature(int index) {
    if(creatures[index] != nullptr) {
        delete creatures[index];
        creatures[index] = nullptr;
        numCreatures--;
    }
}

void printMenu(bool canAddCreature, bool hasCurrentCreature) {
    cout << "n: Select next creature" << endl;
    if(hasCurrentCreature) {
        cout << "f: Feed current creature " << endl
             << "c: Clean current creature " << endl
             << "r: Rename current creature " << endl
             << "g: Give away current creature" << endl;
    }
    if(canAddCreature) {
        cout << "a: Add creature " << endl;
    }
    cout << "t: Advance time" << endl;
    cout << "Press ctrl+c at any time to exit." << endl;
}

int selectNextCreature(Farm &farm, int previousIndex) {
    for(int i = (previousIndex + 1) % Farm::MAX_CREATURES; i != previousIndex; i = (i + 1) % Farm::MAX_CREATURES) {
        Creature *c = farm.getCreature(i);
        if(c != nullptr) {
            return i;
        }
    }
    return previousIndex;
}

Creature *promptNewCreature() {
    int speciesIndex;
    while(true) {
        cout << "Choose a species for the new creature:" << endl;
        for (int i = 0; i < NUM_SPECIES; i++) {
            cout << i << ": " << SPECIES[i].name << endl;
        }
        cin >> speciesIndex;
        if(speciesIndex >= 0 && speciesIndex < NUM_SPECIES) {
            break;
        }
        cout << "Invalid number. Please choose again." << endl;
    }
    string creatureName;
    cout << "Enter a name for the new creature:" << endl;
    cin >> creatureName;
    return new Creature(SPECIES[speciesIndex], creatureName);
}

void menuLoop(Farm &farm) {
    int currentCreatureIndex = 0;
    while(true) {
        Creature *currentCreature = farm.getCreature(currentCreatureIndex);
        cout << "Current creature: " << (currentCreature == nullptr ? " none" : currentCreature->getDetails()) << endl;
        cout << "You have " << farm.getNumCreatures() << " creature(s)." << endl;
        printMenu(farm.canAddCreature(), currentCreature != nullptr);
        char menuOption;
        cin >> menuOption;
        if(currentCreature != nullptr) {
            switch(menuOption) {
                case 'f':
                    currentCreature->feed();
                    farm.advance();
                    continue;
                case 'c':
                    currentCreature->clean();
                    farm.advance();
                    continue;
                case 'g':
                    farm.removeCreature(currentCreatureIndex);
                    currentCreatureIndex = selectNextCreature(farm, currentCreatureIndex);
                    continue;
                case 'r':
                    cout << "Enter a new name:" << endl;
                    string newName;
                    cin >> newName;
                    currentCreature->rename(newName);
                    continue;
            }
        }
        switch(menuOption) {
            case 'n':
                currentCreatureIndex = selectNextCreature(farm, currentCreatureIndex);
                break;
            case 'a':
                if(farm.canAddCreature()) {
                    int newIndex = farm.addCreature(promptNewCreature());
                    if(newIndex != -1) {
                        currentCreatureIndex = newIndex;
                    }
                } else {
                    cout << "The farm is full." << endl;
                }
                break;
            case 't':
                farm.advance();
                break;
            case 'e':
            case 'x':
                return;
            default:
                cout << "Invalid option " << menuOption << "." << endl;
        }
    }
}

int main() {
    Creature *c = new Creature(SPECIES[0], "Bob");
    Farm farm;
    farm.addCreature(c);
    menuLoop(farm);
    return 0;
}
