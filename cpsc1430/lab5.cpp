#include <iostream>
#include <string>

using namespace std;

class Action
{
public:
  string action;
  Action *nextAction = nullptr;
};

class Routine 
{
public:
  void addToStart(const string &actionDescription);
  int addAfterEach(const string &afterDescription, const string &newActionDescription);
  bool removeFirst(const string &actionDescription);
  Action *head;
};

void printActions(Action *head)
{
  for (Action *current = head; current != nullptr; current = current->nextAction)
    {
      cout << current->action << endl;
    }
}

void menuScreen(Routine currentRoutine)
{
  int userChoice;
  string userActionDescription;
  string newActionDescription;
  while(true)
    {
      cout << "What operation would you like to perform? Enter:" << endl;
      cout << "1 for addToStart" << endl;
      cout << "2 for addAfterEach" << endl;
      cout << "3 for removeFirst" << endl;
      cin >> userChoice;
      switch (userChoice)
        {
        case 1:
          cout << "Please enter the action description" << endl;
          cin >> userActionDescription;
          currentRoutine.addToStart(userActionDescription);
          break;
        case 2:
          cout << "Please enter the action you would like to add something after to" << endl;
          cin >> userActionDescription;
          cout << "Please enter the new action" << endl;
          cin >> newActionDescription;
          currentRoutine.addAfterEach(userActionDescription, newActionDescription);
          break;
        case 3:
          cout << "Please enter the description of the first element you would like to remove" << endl;
          cin >> userActionDescription;
          currentRoutine.removeFirst(userActionDescription);
          break;
        default:
          printActions(currentRoutine.head);
          break;
        }
      printActions(currentRoutine.head);
    }
}

void Routine::addToStart(const string &actionDescription)
{
  Action *temp = new Action;
  temp->action = actionDescription;
  temp->nextAction = head;
  head = temp;
}

int Routine::addAfterEach(const string &afterDescription, const string &newActionDescription)
{
  int timesAdded = 0;
  Action *current = head;
  Action *actionToInsert;
  while (current != nullptr)
    {
      if(current->action == afterDescription)
        {
          actionToInsert = new Action;
          actionToInsert->action = newActionDescription;
          actionToInsert->nextAction = current->nextAction;
          current->nextAction = actionToInsert;
          timesAdded++;
        }
      current = current->nextAction;
    }
  return timesAdded;
}

bool Routine::removeFirst(const string &actionDescription)
{
  Action *current = head;
  Action *previous;
  if(head->action == actionDescription)
    {
      head = current->nextAction;
      delete current;
      return true;
    }
  else
    {
      while(current->nextAction != nullptr)
        {
          if (current->action != actionDescription)
            {
              previous = current;
              current = current->nextAction;
            }
        }
      if (current->action == actionDescription)
        {
          previous->nextAction = current->nextAction;
          delete current;
          return true;
        }
    }
  return false; 
}

int main()
{
  Routine currentRoutine;
  menuScreen(currentRoutine);
  return 0;
}
