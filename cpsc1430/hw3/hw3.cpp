#include <iostream>
#include <fstream>

using namespace std;

class Person
{
  //basic linked list, holds name, the position in line, and a pointer to the next Person object
public:
  string name;
  int posInLine;
  Person *next;
};

class Wrapper
{
  //A wrapper class that holds the head position of the person linked list and the sorting functions
public:
  Person *head;
  Person *sorted;
  Wrapper();
  void readFile(string fileName);
  void sortedInstert(Person *newNode);
  void insertSortFile(Person *thisHead);
  void display(Person *cHead);
};

Wrapper::Wrapper()
{
  head = nullptr;
  sorted = nullptr;
}

void Wrapper::display(Person *cHead)
{
  //iterates through the linked list and displays name and position in line
  while(cHead != nullptr)
    {
      cout << cHead->name << ": " << cHead->posInLine << endl;
      cHead = cHead->next;
    }
}

void Wrapper::readFile(string fileName)
{
  //takes the filename then opens said file and adds name and position in line to the linked list
  fstream cFile;
  Person *cPerson;
  Person *prev;
  cFile.open(fileName);
  if(cFile.fail())
    {
      cout << "Please run the program again and use a valid filename" << endl;
      return;
    }
  
  while (cFile.peek() != EOF)
    {
      cPerson = new Person;
      cFile >> cPerson->name;
      cFile >> cPerson->posInLine;
        if (head == nullptr)
          {
            head = cPerson;
            prev = head;
          }
        prev->next = cPerson;
        prev = cPerson;
    }
  cFile.close();
  return;
}

void Wrapper::insertSortFile(Person *thisHead)
{
  //insertion sort algorithm
  sorted = nullptr;
  Person *current = thisHead;
  while (current != nullptr)
    {
      Person *next = current->next;
      sortedInstert(current);
      current = next;
    }
  head = sorted;
}

void Wrapper::sortedInstert(Person *newPerson)
{
  //sorts current Person node taken from insertSortFile
  if (sorted == nullptr || sorted->posInLine >= newPerson->posInLine)
    {
      newPerson->next = sorted;
      sorted = newPerson;
    }
  else
    {
      Person *current = sorted;
      while (current->next != nullptr && current->next->posInLine < newPerson->posInLine)
        {
          current = current->next;
        }
      newPerson->next = current->next;
      current->next = newPerson;
    }
}

void menuScreen()
{
    string fileName;
    cout << "Please enter the desired file name" << endl;
    cin >> fileName;
    cout << "Unsorted:" << endl; 
    Wrapper file;
    file.readFile(fileName);
    file.display(file.head);
    cout << "Sorted:" << endl;
    file.insertSortFile(file.head);
    file.display(file.head);
}

int main()
{
  while (true)
    {
      menuScreen();
    }
  return 0;
}