#ifndef DATAENTRY_H
#define DATAENTRY_H

#include <vector>
#include <iostream>

using namespace std;

class DataEntry{
public:
    //struct to handle dates
    struct Date{
        int month;
        int day;
        int year;
    };
    //getters and setters
    void setDate(vector<string>);
    void setDate(Date);
    void setCountry(string);
    void setCCases(int);
    void setCDeaths(int);
    Date getDate();
    string getCountry();
    int getCCases();
    int getCDeaths();
private:
    Date d;
    string country;
    int c_cases;
    int c_deaths;
};


#endif