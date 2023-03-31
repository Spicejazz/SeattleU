#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

void heapify(int A[], int n, int i){
    //similar to my min heapify function, but altered for max heap
    int max = i;
    int left = (2*i) + 1;
    int right = (2*i) + 2;
    if (left < n && A[left] > A[max]){
        max = left;
    }
    if (right < n && A[right] > A[max]){
        max = right;
    }
    if (max != i){
        swap(A[i], A[max]);
        heapify(A, n, max);
    }
}

void heapSort(int A[], int n){
    for (int i = (n/2) - 1; i >= 0; i--){
        heapify(A, n, i);
    }
    for (int i = n - 1; i >= 0; i--){
        swap(A[0], A[i]);
        heapify(A, i, 0);
    }
}

void merge(int A[], int p, int q, int r){
    //create sub region bounds
    int sub1 = q - p + 1;
    int sub2 = r - q;
    //initialize temp arrays
    int* lArr = new int[sub1];
    int* rArr = new int[sub2];
    //fill arrays with the data given
    for (int i = 0; i < sub1; i++){
        lArr[i] = A[p+ i];
    }
    for (int j = 0; j < sub2; j++){
        rArr[j] = A[q + 1 + j];
    }

    //track indexes of the subregions
    int indexOfSub1 = 0;
    int indexOfSub2 = 0;
    int mergeIndex = p;
    //merge together
    while (indexOfSub1 < sub1 && indexOfSub2 < sub2){
        if (lArr[indexOfSub1] <= rArr[indexOfSub2]){
            A[mergeIndex] = lArr[indexOfSub1];
            indexOfSub1++;
        } else {
            A[mergeIndex] = rArr[indexOfSub2];
            indexOfSub2++;
        }
        mergeIndex++;
    }
    while (indexOfSub1 < sub1){
        A[mergeIndex] = lArr[indexOfSub1];
        indexOfSub1++;
        mergeIndex++;
    }
    while (indexOfSub2 < sub2){
        A[mergeIndex] = rArr[indexOfSub2];
        indexOfSub2++;
        mergeIndex++;
    }
    //clean up, delete temp arrays
    delete[] lArr;
    delete[] rArr;
}

void mergeSort(int A[], int i, int j){
    if (i < j){
     int mid = (i+j)/2;
     //separate subregions
     mergeSort(A, i, mid);
     mergeSort(A, mid+1, j);
     //merge after splitting
     merge(A, i, mid, j);
    }
}

int partition(int A[], int i, int j){
    int p = A[i];
    int m = 0;
    for (int k = i + 1; k <= j; k++){
        if (A[k] <= p){
            m++;
        }
    }
    //find good pivot point
    int pivotIndex = i + m;
    swap(A[pivotIndex], A[i]);
    //sort subregions
    int sub1 = i;
    int sub2 = j;
    while (sub1 < pivotIndex && sub2 > pivotIndex){
        while (A[sub1] <= p)
        {
            sub1++;
        }
        
        while (A[sub2] > p){
            sub2--;
        }
        //if initial while condition is still true, swap elements
        if (sub1 < pivotIndex && sub2 > pivotIndex){
            swap(A[sub1++], A[sub2--]);
        }
        
    }
    return pivotIndex;
}

void quickSort(int A[], int i, int j){
    if (i >= j){
        return;
    }
    int pivotIndex = partition(A, i, j);
    //sort left region
    quickSort(A, i, pivotIndex-1);
    //sort right region
    quickSort(A, pivotIndex+1, j);
}

void initializeRandArray(int A[], int n){
    for (int i = 0; i < n; i++){
        //assigns random val
        A[i] = rand() % 10000;
    }
}

void printArr(int A[], int n){
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}

void bubbleSort(int A[], int n){
    for (int i = 0; i < n-1; i++){
        for (int j = 1; j < n - i - 1; j++)
        {
            if (A[j] > A[j+1])
            {
                swap(A[i], A[j+1]);
            }
        }
        
    }
    
}

int main(){
    int size[] = {10, 100, 1000, 10000, 100000};
    int* unsortedArr;
    for (int i = 0; i < 5; i++){
        unsortedArr = new int[size[i]];
        initializeRandArray(unsortedArr, size[i]);
        if (i == 0){
            cout << "Unsorted: ";
            printArr(unsortedArr, size[i]);
        }
        cout << "Heap sort: " << endl;
        auto start = high_resolution_clock::now();
        heapSort(unsortedArr, size[i]);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<nanoseconds>(stop - start);
        cout << "Time for heapSort with " << size[i] << " items: " << duration.count() << endl;
        if (i == 0){
            cout << "Sorted: ";
            printArr(unsortedArr, size[i]);
        }
        
        initializeRandArray(unsortedArr, size[i]);
        if (i == 0){
            cout << "Unsorted: ";
            printArr(unsortedArr, size[i]);
        }
        cout << "Merge sort: " << endl;
        start = high_resolution_clock::now();
        mergeSort(unsortedArr, 0, size[i] - 1);
        stop = high_resolution_clock::now();
        duration = duration_cast<nanoseconds>(stop - start);
        cout << "Time for mergeSort with " << size[i] << " items: " << duration.count() << endl;
        if (i == 0){
            cout << "Sorted: ";
            printArr(unsortedArr, size[i]);
        }

        initializeRandArray(unsortedArr, size[i]);
        if (i == 0){
            cout << "Unsorted: ";
            printArr(unsortedArr, size[i]);
        }
        cout << "Quick sort: " << endl;
        start = high_resolution_clock::now();
        quickSort(unsortedArr, 0, size[i] - 1);
        stop = high_resolution_clock::now();
        duration = duration_cast<nanoseconds>(stop - start);
        cout << "Time for quickSort with "<< size[i] << " items: " << duration.count() << endl;
        if (i == 0){
            cout << "Sorted: ";
            printArr(unsortedArr, size[i]);
        }
    }
    int* bubbleArray = new int[10];
    initializeRandArray(bubbleArray, 10);
    printArr(bubbleArray, 10);
    bubbleSort(bubbleArray, 10);
    printArr(bubbleArray, 10);
    return EXIT_SUCCESS;
}

