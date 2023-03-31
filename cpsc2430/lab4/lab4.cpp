/*
Ben Kahl
Lab 4
*/
#include <vector>
#include <iostream>

using namespace std;

class MinHeap{
private:     
    vector<int> heapVec;
    void percolateUp(int index); 
    void percolateDown(int index); 
public: 
    void insert(int element); 
    void deleteMin(); 
    int extractMin(); 
    int heapSize(); 
    void heapDisplay();
};

void MinHeap::percolateUp(int index){
    //find index of parent
    int parent = (index-1)/2;

    //swap parent node and inputted node then percolateUp to maintain heap structure
    if (heapVec[index] < heapVec[parent]){
        swap(heapVec[index], heapVec[parent]);
        percolateUp(index);
    }
    
}

void MinHeap::percolateDown(int index){
    //find left and right node indexes
    int left = 2*index + 1;
    int right = 2*index + 2;

    //keep track of minimum value
    int min = index;

    //checks to update min
    if (left < heapSize() && heapVec[left] < heapVec[index]){
        min = left;
    }
    if (right < heapSize() && heapVec[right] < heapVec[min]){
        min = right;
    }

    //if min no longer equals what it started as, swap and recurse
    if (min != index){
        swap(heapVec[index], heapVec[min]);
        percolateDown(min);
    }
}

void MinHeap::insert(int element){
    //pushback an element then percolateUp to maintain structure
    heapVec.push_back(element);
    int i = heapVec.size() - 1;
    percolateUp(i);
}

void MinHeap::deleteMin(){
    //check for empty vector
    if (heapSize() == 0){
        cout << "vector is empty, cannot delete" << endl;
        return;
    }
    
    //delete min vector then percolateDown to maintain structure
    heapVec[0] = heapVec.back();
    heapVec.pop_back();
    percolateDown(0);
}

int MinHeap::extractMin(){
    //returns the top value of the heap
    return heapVec.front();
}

int MinHeap::heapSize(){
    //returns the size of the heap
    return heapVec.size();
}

void MinHeap::heapDisplay(){
    //prints out all values in the heap
    vector<int>::iterator i;
    for(i = heapVec.begin(); i != heapVec.end(); i++)
    {
        cout << *i << ' ';
    }
    cout << endl;
}

void userInterface(){
    //simple UI
    MinHeap main;
    int userInput = -1;
    int userInput2 = -1;
    while (userInput != 6){
        cout << "Welcome to lab 4 on basic min-heap operations" << endl;
        cout << "1. Insert" << endl;
        cout << "2. ExtractMin" << endl;
        cout << "3. DeleteMin" << endl;
        cout << "4. HeapSize" << endl;
        cout << "5. HeapDisplay" << endl;
        cout << "6. Exit" << endl;
        cin >> userInput;
        switch (userInput)
        {
        case 1:
            cout << "Enter desired value" << endl;
            cin >> userInput2;
            main.insert(userInput2);
            break;
        case 2:
            cout << "min = " << main.extractMin() << endl;
            break;
        case 3:
            main.deleteMin();
            cout << "min has been deleted" << endl;
            break;
        case 4:
            cout << "current heapsize = " << main.heapSize() << endl;
            break;
        case 5:
            main.heapDisplay();
            break;
        default:
            break;
        }
    }
}


int main(){
    //simple call to UI
    userInterface();
    return EXIT_SUCCESS;
}