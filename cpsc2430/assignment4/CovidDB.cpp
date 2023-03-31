#ifndef COVIDDB_CPP
#define COVIDDB_CPP

#include "CovidDB.h"

CovidDB::CovidDB(){
    hashTable.resize(17);
}

int CovidDB::hash(string country){
    int sum = 0;
    //computes the sum of the country string, then mod by 17
    for (int i = 0; i < (int)country.size(); i++){
        sum += (i+1)*((int)country.at(i));
    }
    sum %= 17;
    return sum;
}

bool compareDates(DataEntry::Date d1, DataEntry::Date d2){
    //compares from year down to day
    if (d1.year > d2.year){
        return true;
    } else if (d1.year == d2.year && d1.month > d2.month){
        return true;
    } else if (d1.year == d2.year && d1.month == d2.month && d1.day > d2.day){
        return true;
    } else {
        return false;
    }
}

bool CovidDB::add(DataEntry data){
    DataEntry* temp = get(data.getCountry());
    //Add new country to table if it does not exist
    if (temp == nullptr){
        hashTable[hash(data.getCountry())].push_back(data);
        return true;
    }
    //update existing country's record
    if (compareDates(data.getDate(), temp->getDate())){
        temp->setCCases((data.getCCases() + temp->getCCases()));
        temp->setCDeaths((data.getCDeaths() + temp->getCDeaths()));
        temp->setDate(data.getDate());
        return true;
    }
    return false;
}

DataEntry* CovidDB::get(string country){
    int h = hash(country);
    //if doesn't equal the root name, look through the chain until found
    for (int i = 0; i < (int)hashTable[h].size(); i++){
        if (hashTable[h][i].getCountry() == country){
            return &hashTable[h][i];
        }
    }
    //country not found
    return NULL;
}

void CovidDB::remove(string country){
    int h = hash(country);
    DataEntry* temp = get(country);
    if (temp != NULL){
        //if country exists, check for where in chain entry is
        for (int i = 0; i < (int)hashTable[h].size(); i++){
            if (hashTable[h][i].getCountry() == country){
                //Entry found, erase at index i
                hashTable[h].erase(hashTable[h].begin() + i);
                cout << "Country has been deleted" << endl;
                return;
            }
        }
    }
    cout << "Country not found, nothing removed" << endl;
}

void CovidDB::display(){
    cout << "Hash Table:" << endl;
    for (int i = 0; i < (int)hashTable.size(); i++){
        cout << i << ": ";
        for (int j = 0; j < (int)hashTable[i].size(); j++){
            //display entry's data at index [i][j]
            cout << j << ": " << hashTable[i][j].getDate().month << "/" <<  hashTable[i][j].getDate().day << "/" 
            << hashTable[i][j].getDate().year << ", " << hashTable[i][j].getCountry() << ", " << hashTable[i][j].getCCases() 
            << ", " << hashTable[i][j].getCDeaths() << endl;
        }  
    }
}

void CovidDB::display(DataEntry* data){
    cout << data->getDate().month << "/" <<  data->getDate().day << "/" 
    << data->getDate().year << ", " << data->getCountry() << ", " << data->getCCases() 
    << ", " << data->getCDeaths() << endl;
}

DataEntry initializeData(string line){
    DataEntry toAdd;
    stringstream s(line);
    string temp;
    vector<string> date;
    //processes line, updates DataEntry accordingly
    for (int i = 0; i <= 2; i++){
        if (i < 2){
            getline(s, temp, '/');
        } else {
            getline(s, temp, ',');
        }
        date.push_back(temp);   
    }
    toAdd.setDate(date);
    getline(s, temp, ',');
    toAdd.setCountry(temp);
    getline(s, temp, ',');
    int cases = stoi(temp);
    toAdd.setCCases(cases);
    getline(s, temp, ',');
    int deaths = stoi(temp);
    toAdd.setCDeaths(deaths);
    return toAdd;
}

void CovidDB::initialize(){
    string filename = "WHO-COVID-data.csv";
    hashTable.resize(17);
    fstream fin;
    DataEntry temp;
    fin.open(filename, ios::in);
    //this will be used to initialize the vector
    string line;
    stringstream s(line);
    if (fin.is_open()){
        getline(fin, line);
        while (fin.peek() != EOF){
            getline(fin, line);
            //process each line, then use add to push it back or update entry accordingly
            temp = initializeData(line);
            add(temp);
        }
    } else {
        cout << "Could not open file" << endl;
    }
}

#endif