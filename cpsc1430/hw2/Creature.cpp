#ifndef CREATURE_CPP
#define CREATURE_CPP

#include <iostream>
#include "Creature.h"

using namespace std;

Creature::Creature(const Species &species, const string &name)
  : species(species), name(name), age(0), happiness(500), fullness(500), cleanliness(500)
{
  //used : method to initialize species.
}

string Creature::generateName()
{
  //takes a random number from 1-12 and selects a name based off the number
  int nameSelect = rand()%12 + 1;
    switch (nameSelect)
      {
      case 1:
        return "Bill";
      case 2:
        return "Jim";
      case 3:
        return "Clarice";
      case 4:
        return "Mike";
      case 5:
        return "Quebert";
      case 6:
        return "Jason";
      case 7:
        return "Matt";
      case 8:
        return "Drew";
      case 9:
        return "Simon";
      case 10:
        return "Rosie";
      case 11:
        return "Teddy";
      case 12:
        return "Bonnie";
      default:
        return "chum";
      }
}

string Creature::getDetails() const
{
  //first makes the happy face based on happiness, then appends all required data together in a string
  string happyFace;
  if (happiness >= 800)
    {
      happyFace = ":D";
    }
  else if(happiness < 800)
    {
      happyFace = ":)";
    }
  else if(happiness < 550)
    {
      happyFace = ":|";
    }
  else if(happiness < 450)
    {
      happyFace = "):";
    }
  else if (happiness < 200)
    {
      happyFace = "D:";
    }
  string temp = getName() + "(" + species.name + ", " + getAgeStage() + "): " + happyFace + " fullness=" + to_string(fullness)
   + ", cleanliness=" + to_string(cleanliness);
  return temp;
}

string Creature::getAgeStage() const
{
  //gets the age group based on the age and age thresholds
  if (age < species.ageThresholds[0])
    {
      return AGE_GROUPS[0];
    }
  else if (age < species.ageThresholds[1])
    {
      return AGE_GROUPS[1];
    }
  else if (age < species.ageThresholds[2])
    {
      return AGE_GROUPS[2];
    }
  else if (age < species.ageThresholds[3])
    {
      return AGE_GROUPS[3];
    }
  else if (age < species.ageThresholds[4])
    {
      return AGE_GROUPS[4];
    }
  else
    {
      return AGE_GROUPS[5];
    }
}

string Creature::getName() const
{
  //returns the name
  return name;
}

bool Creature::canCreateEgg() const
{
  //checks if the creature is between adult and elder age
  if((age >= species.ageThresholds[3]) && (age < species.ageThresholds[4]) && (happiness >= 700))
    {
      return true;
    }
  else
    {
      return false;
    }
}

bool Creature::isAlive() const
{
  //checks if the age is below the elder threshhold
  if (age < species.ageThresholds[4])
    {
      return true;
    }
  else
    {
      return false;
    }
}

bool Creature::wantsToRunAway() const
{
  //checks if the fullness and happiness is below threshholds
  if (fullness < 50 || happiness < 100)
    {
      return true;
    }
  else
    {
      return false;
    }
}

void Creature::clean()
{
  //sets cleanliness to max and changes happiness based on likesbaths
  cleanliness = MAX_ATTRIBUTE_VALUE;
  if(species.likesBaths)
    {
      happiness += 100;
    }
  else
    {
      happiness -=100;
    }
}

void Creature::feed()
{
  //feeds and changes happiness if it is above the max attribute
  if(fullness > MAX_ATTRIBUTE_VALUE)
    {
      happiness -= 20;
    }
  fullness = MAX_ATTRIBUTE_VALUE;
}

void Creature::rename(const string &nName)
{
  //sets name to the name in parameter
  name = nName;
}

void Creature::advance()
{
  //increments age lowers fullness and cleanliness. Also does checks to raise or lower happiness
  age++;
  fullness -= species.foodConsumption;
  cleanliness -= 100;
  if (fullness > MAX_ATTRIBUTE_VALUE)
    {
      fullness = MAX_ATTRIBUTE_VALUE;
    }
  else if(fullness < 0)
    {
      fullness = 0;
    }
  
  if(cleanliness > MAX_ATTRIBUTE_VALUE)
    {
      cleanliness = MAX_ATTRIBUTE_VALUE;
    }
  else if (cleanliness < 0)
    {
        cleanliness = 0;
    }
  
  if(happiness > MAX_ATTRIBUTE_VALUE)
    {
      happiness = MAX_ATTRIBUTE_VALUE;
    }
  else if (happiness < 0)
    {
      happiness = 0;
    }
  
    if(fullness >= 600 || fullness <= 900)
      {
        happiness += 50;
      }
    else if (fullness > 900 || fullness < 250)
      {
        happiness -= 50;
      }
    if (cleanliness < 300)
      {
        happiness -= 50;
      }
}
#endif
