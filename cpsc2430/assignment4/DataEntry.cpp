#ifndef DATAENTRY_CPP
#define DATAENTRY_CPP

#include "DataEntry.h"

void DataEntry::setDate(vector<string> newDate){
    //conversion from string vector
    d.month = stoi(newDate[0]);
    d.day = stoi(newDate[1]);
    d.year = stoi(newDate[2]);
}

void DataEntry::setDate(Date newDate){
    d.month = newDate.month;
    d.day = newDate.day;
    d.year = newDate.year;
}

void DataEntry::setCountry(string newCountry){
    country = newCountry;
}

void DataEntry::setCCases(int newCases){
    c_cases = newCases;
}

void DataEntry::setCDeaths(int newDeaths){
    c_deaths = newDeaths;
}

DataEntry::Date DataEntry::getDate(){
    return d;
}

string DataEntry::getCountry(){
    return country;
}

int DataEntry::getCCases(){
    return c_cases;
}

int DataEntry::getCDeaths(){
    return c_deaths;
}

#endif