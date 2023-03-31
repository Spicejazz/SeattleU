#include <iostream>

using namespace std;

int bico(int n, int i){
    //dynamically allocates a 2d array for holding triangle values
    n++;
    int** matrix = new int*[n];

    for (int col = 0; col < n; col++){
        //creates new col to be filled
        matrix[col] = new int[col];

        for (int row = 0; row <= col; row++){
            if(col == 0 || col == row){
                //if current row is the first or last line of the current column, it is set to 1
                matrix[col][row] = 1;
            }
            else{
                //for all other postions, takes 2 values above to get current binomial coefficient
                matrix[col][row] = matrix[col-1][row-1] + matrix[col-1][row];
            }
        }
    }
    int result = matrix[n-1][i]; //holds desired value
    //deallocates 2d array
    for (int q = 0; q < n; q++){
        delete[] matrix[q];
    }
    delete[] matrix;
    return result;
}

int main()
{
    int userin1;
    int userin2;
    cout << "Please input the degree of the binomial: " << endl;
    cin >> userin1;
    cout << "Please input the index of the coefficient: " << endl;
    cin >> userin2;
    cout << "The result is: " << bico(userin1, userin2) << endl;
    return EXIT_SUCCESS;
}