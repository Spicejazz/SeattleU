#include <iostream>
using namespace std;

struct Airport
{
    string name;
    Airport* next;
};

Airport* penultimate(Airport* head){
    Airport* p,* q;
    p = head;
    q = head->next;
    if(head != nullptr){
        while (q->next != nullptr)
        {
            p = p->next;
            q = q->next;
        }
    }
    return p;
}

int main(){
    Airport* head = new Airport;
    Airport* second = new Airport;
    Airport* third = new Airport;
    Airport* fourth = new Airport;
    second->name = "MSP";
    third->name = "ATL";
    fourth->name = "BOS";
    head->name = "LAX";
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = nullptr;
    Airport* penult = penultimate(head);

    cout << penult->name << endl;
}