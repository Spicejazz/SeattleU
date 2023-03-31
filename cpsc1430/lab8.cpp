#include <iostream>
#include<gtest/gtest.h>

using namespace std;

class Node
{
public:
  string data;
  Node *next;
};

class Queue
{
public:
  Node *head;
  Node *tail;
  Queue();
  Queue(Queue&);
  ~Queue();
  Queue copyQueue(Queue&);
  int size();
  bool isEmpty();
  void enqueue(string);
  Node *dequeue();
  string peek();
};

Queue::Queue()
{
  head = nullptr;
  tail = nullptr;
}

Queue::Queue(Queue &oldQueue)
{
  head = new Node;
  head->data = oldQueue.head->data;
  head->next = oldQueue.head->next;
  tail = new Node;
  tail->data = oldQueue.tail->data;
  tail->next = nullptr;
}

Queue::~Queue()
{
    Node *temp;
    while(head != nullptr)
    {
        temp = head;
        head = head->next;
        delete temp;
    }
}

Queue Queue::copyQueue(Queue &oldQueue)
{
  head = oldQueue.head;
  tail = oldQueue.tail;
  return *this;
}

int Queue::size()
{
  int qSize = 0;
  if (isEmpty())
    {
      return qSize;
    }
  else
    {
      for (Node *current = head; current != nullptr; current = current->next)
        {
          qSize++;   
        }
      return qSize;
    }
}

bool Queue::isEmpty()
{
  if(head == nullptr && tail == nullptr)
    {
      return true;
    }
  else
    {
      return false;
    }
}

void Queue::enqueue(string dat)
{
  Node *toInsert = new Node;
  toInsert->data = dat;
  if(isEmpty())
    {
      head = tail = toInsert;
    }
  else
    {
      tail->next = toInsert;
      tail = toInsert;
    }
}

Node *Queue::dequeue()
{
  if (isEmpty())
    {
      return nullptr;
    }
  else
    {
      Node *temp = head;
      head = head->next;
      if(head == nullptr)
        {
          tail = nullptr;
        }
      return temp;
    }
}

string Queue::peek()
{
  if (isEmpty())
    {
      return nullptr;
    }
  else
    {
      return head->data;
    }
}

// TEST(QueueTest, VerifyIsEmptyQueue)
// {
//   Queue empty;
//   EXPECT_EQ(empty.size(), 0);
//   EXPECT_EQ(empty.isEmpty(), true);
// }

// TEST(QueueTest, VerifySingleItemQueue)
// {
//   Queue single;
//   single.enqueue("a");
//   EXPECT_EQ(single.size(), 1);
//   EXPECT_EQ(single.isEmpty(), false);
//   EXPECT_EQ(single.peek(), "a");
//   EXPECT_EQ(single.dequeue()->data, "a");
// }

// TEST(QueueTest, TestCopyConstructor)
// {
//   Queue constructTest;
//   constructTest.enqueue("b");
//   Queue copyConstruct = constructTest;
//   copyConstruct.enqueue("c");
//   EXPECT_EQ(constructTest.size(), 1);
//   EXPECT_EQ(copyConstruct.size(), 2);
// }

// TEST(QueueTest, TestCopyQueueFunction)
// {
//   Queue orig;
//   Queue copy;
//   orig.enqueue("d");
//   copy.enqueue("e");
//   copy.copyQueue(orig);
//   EXPECT_EQ(orig.peek(), "d");
//   EXPECT_EQ(copy.peek(), "d");
// }

int main()
{
  //main test to ensure that test cases worked since example code did not compile in class on 5/27
  Queue empty;
  cout << empty.size() << endl;
  cout << empty.isEmpty() << endl;
  Queue single;
  single.enqueue("a");
  cout << single.size() << endl;
  cout << single.isEmpty() << endl;
  cout << single.peek() << endl;
  cout << single.dequeue()->data << endl;
  Queue constructTest;
  constructTest.enqueue("b");
  Queue  copyConstruct = constructTest;
  constructTest.enqueue("c");
  cout << constructTest.size() << endl;
  cout << copyConstruct.size() << endl;
  Queue orig;
  Queue copy;
  orig.enqueue("d");
  copy.enqueue("e");
  copy.copyQueue(orig);
  cout << orig.peek() << endl;
  cout << copy.peek() << endl;
  // testing::InitGoogleTest(); 
  // return RUN_ALL_TESTS();
  return 0;
}
