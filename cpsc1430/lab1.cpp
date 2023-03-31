#include <iostream>
using namespace std;

int sumArray(int array[8]) {
	int sum = 0;
	for(int i = 0; i < 8; i++){
		sum += array[i];
	}
	return sum;
}

int *createNewArray(int size){
	int *newArray = new int[size];
	return newArray;
}

int sumArrayDynamic(int *darray, int length){
	int dSum = 0;
	for(int z = 0; z < length; z++){
		dSum += darray[z];
	}
	return dSum;
}

int numGreater(int *leftArray, int leftArrayLength, int *rightArray, int rightArrayLength){
	int greater = 0;
	for (int i = 0; i < rightArrayLength; i++)
	{
		if (leftArray[i] > rightArray[i])
		{
			greater++;
		}
	}
	return greater;
}

int *promptArray(int &sizeOut){
	cout << "Please enter the desired length of the array";
	cin >> sizeOut;
	int *userArray = createNewArray(sizeOut);
	for (int i = 0; i < sizeOut; i++)
	{
		cout << "Please enter the desired value of the array at position " << i+1;
		cin >> userArray[i];
	}
	return userArray;
}
int main(){
	return 0;
}