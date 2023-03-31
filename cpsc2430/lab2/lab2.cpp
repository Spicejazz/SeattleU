/*
Ben Kahl

Purpose:
The purpose of this lab is to observe the time complexity differences
between recursive and iterative versions of the Pascal's triangle function
*/

#include <iostream>
using namespace std;

int recursiveBico(int n, int i){
//a recursive implementation of finding the binomial coefficient.    
    //exit base case
    if (i > n){
        return 0;
    }
    //edge of triangle case
    if (i == 0 || n == i){
        return 1;
    }
    
    //recursive call, adds value from column and row above
    return recursiveBico(n-1, i-1) + recursiveBico(n-1, i);
}


int main()
{
    //example output
    int recurBico = recursiveBico(5, 2);
    cout << "The result for recursive method is: " << recurBico << endl;

    return EXIT_SUCCESS;
}