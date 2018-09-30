/*
 *  Binary Recursion:
 *   - When an algorithm makes two recursive calls.
 *   - Can be used to solve two similar halves of some problem.
 */
#include <iostream>
#include <cmath> // for floor and ceil
using namespace std;

// BinarySum
//  Input: Array A, and integers i (starting index) and n (length of sequence)
//  Output: Sum of n integers in A starting at i.
// NOTE:
//  - The value of the parameter n is halved at each recursive call.
//  - Therefore, the depth of the recursion, ie the number of function
//    instances that are active at the same time, is 1 + log(n).
//  - The running time is still roughly proportional to n, since each
//    call is visited in constant time when stepping through the algorithm,
//    and there are 2n - 1 calls.
int binarySum(int* A, int i, int n) {
    if (n == 1) return A[i];
    else {
	double nDouble = static_cast<double>(n);
	int x1 = static_cast<int>(ceil(nDouble/2.0));
	int x2 = static_cast<int>(floor(nDouble/2.0));
	return binarySum(A, i, x1) + binarySum(A, i+x1, x2);
    }
}

int main() {
    int A[5] = {1,2,3,4,5};
    cout << "binarySum(A,0,5) = " << binarySum(A,0,5) << endl;
    return 0;
}
