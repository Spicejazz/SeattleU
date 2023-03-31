#ifndef ASSIGNMENT4_CPP
#define ASSIGNMENT4_CPP
#include "CovidDB.h"

void userInterface(){
    CovidDB db;
    DataEntry user;
    int userChoice = -1;
    string userInput;
    vector<string> temp;
    int tempint;
    while (userChoice != 0){
        cout << "Covid Tracker" << endl;
        cout << "Please choose the operation you want: " << endl;
        cout << "1. Create the initial hash table" << endl;
        cout << "2. Add a new data entry" << endl;
        cout << "3. Get a data entry" << endl;
        cout << "4. Remove a data entry" << endl;
        cout << "5. Display the hash table" << endl;
        cout << "0. Quit" << endl;

        cin >> userChoice;

        switch (userChoice){
        case 1:
            db.initialize();
            break;
        case 2:
            //prompt to handle creation of new DataEntry
            cout << "Please create a new DataEntry to add" << endl;
            cout << "Enter the country" << endl;
            cin >> userInput;
            user.setCountry(userInput);
            cout << "Enter the date, month/day/year" << endl;
            cin >> userInput;
            temp.clear();
            temp.push_back(userInput);
            cin >> userInput;
            temp.push_back(userInput);
            cin >> userInput;
            temp.push_back(userInput);
            user.setDate(temp);
            cout << "Enter the new cases" << endl;
            cin >> tempint;
            user.setCCases(tempint);
            cout << "Enter new deaths" << endl;
            cin >> tempint;
            user.setCDeaths(tempint);
            db.add(user);
            break;
        case 3:
            cout << "Enter Country to Get" << endl;
            cin >> userInput;
            if(db.get(userInput) == NULL){
                cout << "Entry not found" << endl;
            } else {
                db.display(db.get(userInput));
            }
            break;
        case 4:
            cout << "Enter Country To Remove" << endl;
            cin >> userInput;
            db.remove(userInput);
            break;
        case 5:
            db.display();
            break;
        case 0:
            return;
            break;
        default:
            cout << "Invalid input" << endl;
            break;
        }
    }
    
}
int main(){
    userInterface();
    return 0;
}

#endif