#include <iostream>

void printArray(int[], int, int);
int partitionArray(int[], int, int);
int selectNthOrder(int[], int, int, int);

using namespace std;

int main(){
    int len = 8;
    int arr[len] = {2,8,7,1,3,5,6,4};
    /**
    printArray(arr, len);
    int pivot = partitionArray(arr, 0, 7);
    printArray(arr, len);
    cout << "Pivot is: " << pivot << endl; 
    **/
    int nthOrderElement = selectNthOrder(arr, 0, 7, 1);
    cout << "nthOrderElement is: " << nthOrderElement << endl; 
    return 0;
}

/**
Takes an array and its start and end index
and the nth order element we want to find
Returns the nth element
**/

int selectNthOrder(int A[], int p, int r, int n) {
    cout << "\n" << "\n";
    cout << p << "\t" << r << "\t" << n << endl;
    
    if(p == r) 
        return A[p];
    int q = partitionArray(A, p, r);
    if(n == q)
        return A[q];
    else if(n < q)
        return selectNthOrder(A, p, q - 1, n);
    else
        return selectNthOrder(A, q + 1, r, n);
} 

/**
Takes an array and its start and end index
Returns the pivot element q such that 
all indices from p to q are smallter than q + 1 to r
**/
int partitionArray(int A[], int p, int r) {
    
    int i = p - 1;
    int x = A[r];
    
    for(int j = p; j <= r ; j++) {
        if(A[j] <= x) {
            i = i + 1;
            int temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }
    cout << "pivot is: " << i << endl;
    printArray(A, p, r);
    return i;
}

void printArray(int arr[], int p, int r) {
    for(int i = p; i <= r ; i++) {
        cout << i << ":" <<arr[i] << "\t";
    }
    cout << endl;
}