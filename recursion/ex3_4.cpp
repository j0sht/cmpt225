#include <iostream>
using namespace std;

// Input:
//  - Two dimensional array A of size n*n (in this case, limited to 3*3)
//  - Integers i, j, n, representing number of rows-1, columns-1, and n-1
// Output:
//  - Sum of integers in two dimensional array
int sumTwoDArray(int A[][3], int i, int j, int n) {
    if (i == 0 && j == 0) return A[i][j];
    else if (j == 0) return A[i][j] + sumTwoDArray(A,i-1,n,n);
    else return A[i][j] + sumTwoDArray(A,i,j-1,n);
}

int main() {
    int A[3][3] = {{1,2,3},
		   {4,5,6},
		   {7,8,9}};
    cout << "Sum of 1+2+..+9 = " << sumTwoDArray(A,2,2,2) << endl;
    return 0;
}
