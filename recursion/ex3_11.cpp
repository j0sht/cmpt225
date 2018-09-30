#include <iostream>
using namespace std;

// Input:
//  - Integer array A, integer i >= 1 representing size of array
// Output:
//  - The max int in A
int recursiveMax(int* A, int i) {
    if ((i-1)==0) return A[i-1];
    else {
	int max = recursiveMax(A,i-1);
	if (A[i-1] > max) return A[i-1];
	else return max;
    }
}

int main() {
    int A[5] = {3,2,6,4,1};
    cout << "Max in {3,2,6,4,1} = " << recursiveMax(A,5) << endl;
    return 0;
}
