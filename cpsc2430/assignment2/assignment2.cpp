/*
Ben Kahl

Purpose:
To practice recursive algorithms
*/

#include <iostream>
#include <cmath>

using namespace std;

//takes the remainder from dividing by 10 then "chops off" the last digit by dividing by 10
int sumDigits(int a){
    if (a <= 0){
        return 0;
    }
    return (a % 10 + sumDigits(a/10));
}

//following the pattern for guessing the root, increases y by 4x and to the power of 4 to closer approximate the root
double root5(int n, double y){
    if (abs(pow(y, 5) - n) < 0.0001){
        return y;
    }
    
    return root5(n,(4*(y) + (n/pow(y, 4)))/5);
}

//halves the int by adding up the number of times the int is subtracted by the divisor
int halveInt(int a, int divisor){
    if (a < divisor){
        return 0;
    }
    return 1 + halveInt((a - divisor), divisor);
}

//adds an int to itself to double it
int doubleInt(int a){
    return a + a;
}

//overloaded function to account for d
int egyptDivision(int a, int b, int c, int d){
    if (a < 1){
        return d;
    }
    if (b > c){
        return egyptDivision(halveInt(a, 2), halveInt(b, 2), c, d);
    }
    return egyptDivision(halveInt(a, 2), halveInt(b, 2), (c-b), (a+d));
}

//creates the a, b, and c charts then calls the overloaded function to do the division
int egyptDivision(int a, int b, int c){
    if (b > c){
        return egyptDivision(a, b, c, 0);
    }
    return egyptDivision(doubleInt(a), doubleInt(b), c);
}

//follows the ramanujan formula's pattern
double ramanujan(int a, int b, int c){
    if (a == 0){
         return 0;
    }
    return sqrt(b + (c * ramanujan(a - 1, b + 1, c + 1)));
}

//simple user interface
void userInterface(){
    int userChoice;
    int userChoice2;
    int userChoice3;
    while (userChoice != 5){
        cout << "Welcome to the recursion assignment. What would you like to test?" << endl;
        cout << "1. sumDigits" << endl;
        cout << "2. root5" << endl;
        cout << "3. egyptDivision" << endl;
        cout << "4. ramanujan" << endl;
        cout << "5. exit" << endl;
        cin >> userChoice;

        switch (userChoice)
        {
        case 1:
            cout << "Please enter a number to sum its digits" << endl;
            cin >> userChoice2;
            cout << "Result: " << sumDigits(userChoice2) << endl;
            break;
        case 2:
            cout << "Please enter a number to calculate its fifth root:" << endl;
            cin >> userChoice2;
            cout << "Result: " << root5(userChoice2, 1) << endl;
            break;

        case 3:
            cout << "Egyptian Division. Enter dividend and divisor:" << endl;
            cin >> userChoice2;
            cin >> userChoice3;
            cout << "Result: " << egyptDivision(1 ,userChoice3, userChoice2) << endl;
            break;
        
        case 4:
            cout << "Ramanujan. Enter integer depth:" << endl;
            cin >> userChoice2;
            cout << "Result: " << ramanujan(userChoice2, 6, 2) << endl;
            cout << "Result approaching infinity: " << ramanujan(20000, 6, 2) << endl;
            break;

        case 5:
            return;

        default:
            cout << "Please enter a valid number" << endl;
            break;
        }
    }
    return;
}

int main(){
    //only need to call UI, handles the rest of the program
    userInterface();

    return EXIT_SUCCESS;
}