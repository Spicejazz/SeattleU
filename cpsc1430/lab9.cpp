#include <iostream>
#include <time.h>

using namespace std;

struct Card
{
    int val;
    Card *next;
};

class Stack
{
    public:
    Card *head;
    Stack();
    void push(int);
    int pop();
    bool isEmpty();
};

Stack::Stack()
{
    head = nullptr;
}

void Stack::push(int data)
{
    Card *temp = new Card;
    temp->val = data;
    temp->next = head;
    head = temp;
}

int Stack::pop()
{
    if (isEmpty())
    {
        return -1;
    }
    
    Card *temp;
    temp = head;
    int tempVal = temp->val;
    head = head->next;
    return tempVal;
}

bool Stack::isEmpty()
{
    if (head == nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void generateDecks(Stack &p1, Stack &p2)
{
    srand(time(NULL));
    for (int i = 0; i < 32; i++)
    {
        p1.push(rand() % 24 + 1);
        p2.push(rand() % 24 + 1);
    }
}

void playRound(Stack &p1, Stack &p1Discard, Stack &p2, Stack &p2Discard)
{
    int p1Temp;
    int p2Temp;
    while (!p1.isEmpty() && !p2.isEmpty())
    {
        p1Temp = p1.pop();
        p2Temp = p2.pop();
        if (p1Temp > p2Temp)
        {
            cout << p1Temp << " is greater than " << p2Temp << ". Player 1 wins" << endl; 
            p1Discard.push(p1Temp);
            p1Discard.push(p2Temp);
        }
        else if (p2Temp > p1Temp)
        {
            cout << p2Temp << " is greater than " << p1Temp << ". Player 2 wins" << endl;
            p2Discard.push(p1Temp);
            p2Discard.push(p2Temp);
        }
        else
        {
            cout << p1Temp << " and " << p2Temp << " are equal." << endl;
        }
    }
    
}

void swap(Stack &p1, Stack &p1Discard, Stack &p2, Stack &p2Discard)
{
    Stack temp1 = p1;
    Stack temp2 = p2;
    p1.head = p1Discard.head;
    p2.head = p2Discard.head;
    p1Discard.head = temp1.head;
    p2Discard.head = temp2.head;
}

int main()
{
    Stack p1;
    Stack p2;
    Stack p1Discard;
    Stack p2Discard;

    generateDecks(p1, p2);

    playRound(p1, p1Discard, p2, p2Discard);
    swap(p1, p1Discard, p2, p2Discard);
    int i = 0;
    while ((!p1.isEmpty() && !p1Discard.isEmpty() && !p2.isEmpty() && !p2Discard.isEmpty()) && i < 100)
    {
        playRound(p1, p1Discard, p2, p2Discard);
        swap(p1, p1Discard, p2, p2Discard);
        i++;
    }
    return 0;
}