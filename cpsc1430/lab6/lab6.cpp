#include <iostream>
#include <fstream>

using namespace std;

struct Node
{
  string num;
  Node *nextNode = nullptr;
};

class Wrapper
{
public:
  Node *head;
  Wrapper();
  void read(string userChoice);
  void sortWhileRead(Node *thisHead);
  void display(Node *thisHead);
};

Wrapper::Wrapper()
{
  head = nullptr;
}

void Wrapper::display(Node *thisHead)
{
  for (Node *current = thisHead; current != nullptr; current = current->nextNode)
    {
      cout << current->num << endl;
    }
}

void Wrapper::read(string userChoice)
{
  ifstream cFile;
  Node *cNode;
  cFile.open(userChoice);
  
  if(cFile.fail())
    {
      cout << "Please run the program again and use a valid filename" << endl;
      return;
    }
  if(cFile.peek() == EOF)
    {
      return;
    }
  else
  {      
  while (cFile.peek() != EOF)
    {
      cNode = new Node;
      cFile >> cNode->num;
      sortWhileRead(cNode);
    }
  cFile.close();
}
}

void Wrapper::sortWhileRead(Node *thisHead)
{
  Node *current = head;
  if(head == nullptr || head->num <= thisHead->num)
  {
    thisHead->nextNode = head;
    head = thisHead;
    return;
  }
  else
  {
    while (current->nextNode != nullptr && current->nextNode->num > thisHead->num)
    {
      if (current->num == thisHead->num)
      {
        //not quite sure how to get the duplicate deletion working.
        delete thisHead;
        return;
      }
      current = current->nextNode;
    }
    current->nextNode = thisHead;
    current = thisHead;
  }
}

int main()
{
  string userChoice;
  cout << "Please enter the name of the file you would like" << endl;
  cin >> userChoice;
  Wrapper file;
  file.read(userChoice);
  file.display(file.head);
  return 0;
}
