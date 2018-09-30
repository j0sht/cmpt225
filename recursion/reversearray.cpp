#include <iostream>
using namespace std;

void swap(int& x, int& y) {
    int tmp = x;
    x = y;
    y = tmp;
}

// Input:
//  - An array A and nonnegative integer indices i and j
// Output:
//  - The reversal of the elements in A starting at i and ending at j
// NOTE:
//  - This is an example of tail recursion
//  - An algorithm that uses linear recursion and makes a recursive
//    call as its very last operation.
//  - An algorithm that uses tail recursion can easily be converted to
//    a non-recursive algorithm, by iterating through the recursive calls
//    rather than calling them explicitly. (see iterativeReverseArray)
void reverseArray(int* A, int i, int j) {
    // Note: There are two base cases (when i = j, and when i > j)
    // Guarenteed to make progress to one of the two base cases:
    //  - If n is odd, we reach i = j case
    //  - Else, we reach i > j case.
    if (i < j) {
	swap(A[i], A[j]);
	reverseArray(A, i+1, j-1);
    }
}
void iterativeReverseArray(int* A, int i, int j) {
    while (i < j)
	swap(A[i++], A[j--]);
}

void printArray(int* A, int size) {
    for (int i = 0; i < size; i++)
	cout << A[i] << " ";
    cout << endl;
}

int main() {
    // Odd number of elements
    int A[5] = {1,2,3,4,5};
    cout << "A before reverse:\n";
    printArray(A, 5);
    reverseArray(A, 0, 4);
    cout << "A after reverse:\n";
    printArray(A, 5);

    // Even number of elements
    int B[4] = {4,3,2,1};
    cout << "\nB before reverse:\n";
    printArray(B, 4);
    reverseArray(B, 0, 3);
    cout << "B after reverse:\n";
    printArray(B, 4);

    // Testing iterativeReverseArray
    cout << "Testing iterativeReverseArray on B:\n";
    iterativeReverseArray(B, 0, 3);
    printArray(B, 4);
    return 0;
}
