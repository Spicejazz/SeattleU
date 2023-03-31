#include <iostream>
#include <fstream> 
#include "fileUtils.h"

using namespace std;

int *fileProcessor(char *file, int &length)
{
    //returns a pointer to a dynamically allocated array containing lap times
    ifstream input;
    input.open(file);
    int numEntries = readByte(input);
    int *stats = new int[numEntries]; 
    cout << "This file has " << numEntries << " entries" << endl;
    for(int i = 0; i < numEntries; i++) {
        stats[i] = readInt(input);
    }
    for(int i = 0; i < numEntries; i++)
    {
        cout << stats[i] << " ";
    }
    length = numEntries;
    return stats;
}

int findMin(int *inStats, int len)
{
    //finds the minimum value of the inputted array
    int min = inStats[0];
    for (int i = 0; i < len; i++)
    {
        if (inStats[i] <= min)
        {
            min = inStats[i];
        }
    }
    return min;
}

int findMax(int *inStats, int len)
{
    //finds the maximum value of the inputted array
    int max = inStats[0];
    for (int i = 0; i < len; i++)
    {
        if (inStats[i] >= max)
        {
            max = inStats[i];
        }
    }
    
    return max;
}

int sumTimes(int *inStats, int len)
{
    //takes each value in the inputted array and adds them to a sum value
    int sum = 0;
    for (int i = 0; i < len; i++)
    {
        sum+= inStats[i];
    }
    
    return sum;
}

float takeAvg(int *inStats, int len)
{
    //uses sumTimes function to get the sum then divides that value by the size of the array to return the average value
    float avg = 0;
    avg = sumTimes(inStats, len)/len;
    return avg;
}

struct FileStats
{
    //struct containing all the important information from the inputted files
    int min = 0;
    int max = 0;
    float avg = 0;
    int sumTime = 0;
};

int main(int argc, char *argv[]){
    int userInput = 0;
    int *cFile = 0;
    int len = 0;
    FileStats *desiredStats = new FileStats[argc];
    for (int i = 1; i < argc; i++)
    {
        //sets values from the current file to the values in the struct array
        char *fileName = argv[i];
        cFile = fileProcessor(fileName, len);
        desiredStats[i].min = findMin(cFile, len);
        desiredStats[i].max = findMax(cFile, len);
        desiredStats[i].avg = takeAvg(cFile, len);
        desiredStats[i].sumTime = sumTimes(cFile, len);
    }
    do
    {
    int sum = 0;
    int uInp = 0;
    float average = 0;
    //user menu to interact with the program
    cout << "\n" << "Please Select an option" << "\n";
    cout << "1. List the names of the files that have been loaded" << "\n";
    cout << "2. Show the summary stats for a particular file" << "\n";
    cout << "3. Show the average of the average times across all files" << "\n";
    cout << "4. Show the total time combined across all files" << "\n";
    cout << "5. Exit" << "\n";
    
    cin >> userInput;
    switch (userInput)
    {
    case 1:
         for (int i = 1; i < argc; i++)
        {
            //lists file names
            cout << i << ". " << argv[i] << "\n";
        }
    
        break;
    case 2:
            cout << "Please enter the corresponding number for the file you would like to view" << "\n";
            for (int i = 1; i < argc; i++)
            {
                cout << i << ". " << argv[i] << "\n";
            }
            //lists file names then prompts user for desired file then lists stats
            cin >> uInp;
            cout << "Requested file: " << argv[uInp] << "\n";
            cout << "Min: " << desiredStats[uInp].min << "\n";
            cout << "Max: " << desiredStats[uInp].max << "\n";
            cout << "Avg: " << desiredStats[uInp].avg << "\n";
            cout << "Total time (sum): " << desiredStats[uInp].sumTime << "\n";
            break;
    case 3:
            
            for (int i = 1; i < argc; i++)
            {
                //takes the average of all the inputted files
                average += desiredStats[i].avg;
            }
            average = average/(argc-1);
            cout << average << "\n";
            break;
    case 4:
        
        for (int i = 1; i < argc; i++)
        {
            //takes the total of all lap times from all files
            sum += desiredStats[i].sumTime;
        }
        cout << sum << "\n";
        break;
    case 5:
        return 0;
        break;

    default:
        cout << "Please enter a valid value" << "\n";
    }
    }while(1);
}