#include <iostream>

using namespace std;

struct node
{
    node* next;
};

int recursiveCountList(node* head){
    if (head == nullptr){
        return 0;
    }
    if (head->next == nullptr){
        return 1;
    }
    return 1 + recursiveCountList(head->next);
}

node* recursiveReverseList(node* head){
    if(head == nullptr){
        return head;
    }
    if(head->next == nullptr){
        return head;
    }
    
    
}

int main(){
    node* head = new node;
    node* second = new node;
    node* third = new node;
    head->next = second;
    second->next = third;
    third->next = nullptr;
    int count = recursiveCountList(head);
    cout << count << endl;
}