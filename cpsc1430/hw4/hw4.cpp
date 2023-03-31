#include <iostream>
#include <fstream>

using namespace std;

struct Guest 
{
  int pos;
  string fName;
  string lName;
  Guest *next;
  Guest();
};

Guest::Guest()
{
  //default constructor for a new guest
  pos = 0;
  fName = "";
  lName = "";
  next = nullptr;
}

class Queue
{
public:
  Guest *front;
  Guest *rear;
  Queue();
  int getSize();
  void enqueue(Guest*);
  void dequeue();
  void read(string);
};

Queue::Queue()
{
  //default constructor for an empty queue
  front = nullptr;
  rear = front;
}

void Queue::read(string fileName)
{
  ifstream userFile;
  Guest *cNode;
  Guest *prev;
  userFile.open(fileName); //opens file to be read
  
    if(userFile.fail())
      {
        cout << "Please run the program again and enter the correct file name" << endl; //catch case for if the file does not exist
      }
    
    if(userFile.peek() == EOF)
      {
        return; //if the file is empty, exit out
      }
    else
      {
        while(userFile.peek() != EOF)
          {
            //creates new Guest nodes while there is still data to be read from the file. Pushes new Guests to the rear
            cNode = new Guest;
            userFile >> cNode->pos;
            userFile >> cNode->fName;
            userFile >> cNode->lName;
            if(front == nullptr)
              {
                cNode->next = front;
                front = cNode;
              }
            else
              {
                prev->next = cNode;
                cNode->next = nullptr;
              }
            prev = cNode;
          }
        rear = cNode;
      }
    userFile.close();
}

void Queue::enqueue(Guest *toInsert)
{
  //similar to the read function, pushes Guests to the rear or if the queue is empty makes current node the front
  Guest *temp = new Guest;
  temp->fName = toInsert->fName;
  temp->lName = toInsert->lName;
  temp->pos = toInsert->pos;
  temp->next = nullptr;
  if(getSize() == 0)
    {
      front = rear = temp;
    }
  else
    {
      rear->next = temp;
      rear = temp;
    }
}

void Queue::dequeue()
{
  // Removes nodes from the queue as long as the queue is not empty. 
  // I decided to make it a void function because the program doesn't need anything returned
  if(front == nullptr)
    {
      return;
    }
  else
    {
      Guest *temp = front;
      front = front->next;
      if(front == nullptr)
        {
          rear = nullptr;
        }
      delete temp;
    }
}

int Queue::getSize()
{
  //iterates over the Queue linked list to return the size
  int size = 0;
  Guest *current = front;
  while (current != nullptr)
    {
      size++;
      current = current->next;
    }
  return size;
}

void simulate(Queue &source)
{
  //if enough time passes, empty queue
  //add guests to queue as they get to their time
  //simulate passing of time
  // Segmentation fault I emailed Prof Ernsberger about was caused by me doing current = current->next every loop
  // instead of just when I was enqueuing passengers
  int seconds = 0;
  int riders = 0;
  Guest *current = source.front;
  Queue ride;
  while (seconds < 36000 && current != nullptr) //runs for twelve hours and makes sure it can't go out of bounds on the linked list
    {
      if(current->pos == seconds)
        {
          while(current->pos == seconds) //loops over to ensure that multiple guests can enter at the same time
            {
              ride.enqueue(current);
              cout << "time: " << seconds << " " << current->fName << " " << current->lName << " got in line" << endl;
              current = current->next;
            }
        }
      
      if (seconds % 180 == 0 && seconds != 0) //every 180 seconds, aside from when seconds equals 0 it will attempt to dequeue
        {
          if(ride.getSize() != 0)
            {
              for (int i = 0; ride.getSize() != 0 && i < 8; i++) //dequeues guests until empty or 8 guests are in the ride
                {
                  ride.dequeue();
                  riders++;
                }
              cout << "time: " << seconds << " starting ride with " << riders <<" passengers." << " Queue size: " << ride.getSize() << endl;
              riders = 0;
            }
          else
            {
              // case for if queue is empty
              cout << "time: " << seconds << " Not running ride since nobody was in line." << endl;
            }
        }
      seconds++;
    }
  cout << "Park is closing." << endl;
}

void menuScreen()
{
  Queue file;
  string userChoice;
  cout << "Please enter the name of the file you would like to use" << endl;
  cin >> userChoice;
  file.read(userChoice);
  simulate(file);
}

int main()
{
  menuScreen();
  return 0;
}
