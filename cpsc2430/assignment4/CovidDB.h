#ifndef COVIDDB_H
#define COVIDDB_H

#include "DataEntry.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

class CovidDB{
private:
    //Holds the hash table and hashing function is kept private
    vector<vector<DataEntry>> hashTable;
    int hash(string);
public:
    //Basic functions, with added initialize class to handle the csv input
    bool add(DataEntry);
    DataEntry* get(string);
    void remove(string);
    void display();
    void display(DataEntry*);
    void initialize();
    CovidDB();
};
#endif