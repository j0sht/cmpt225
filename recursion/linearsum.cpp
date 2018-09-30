/*
 * The simplest form of recursion is linear recursion:
 *  - A function defined such that it makes at most one recursive
 *    call each time it is invoked.
 *
 * In general, an algorithm that uses linear recursion typically has:
 *  i) Test for base cases
 *    - Should be at least one.
 *    - Should be defined so that every possible chain of recursive calls
 *      eventually reaches a base case.
 *    - The handling of each base case should not use recursion.
 *  ii) Recursive step
 *    - After testing for base cases, perform a single recursive call.
 *    - Should be defined so that it makes progress towards a base case.
 */
#include <iostream>
using namespace std;

// Input:
//  - An integer array A, and an int n >= 1, s.t. A has @ least n elements
// Output:
//  - The sum of the first n integers in A
// Analysis:
//  - For an input array of size n, linearSum makes n calls, hence
//    it spends a constant amount of time performing the nonrecursive
//    part of each call.
//  - The memory space used by the algorithm (in addition to array A),
//    is roughly proportional to n, since we need a constant amount of
//    memory space for each call until the final recursive one.
int linearSum(int* A, int n) {
    if (n == 1) return A[0];
    else return linearSum(A, n-1) + A[n-1];
}

int main() {
    int A[5] = {1,2,3,4,5};
    cout << "linearSum([1,2,3,4,5], 5) = " << linearSum(A, 5) << endl;
    return 0;
}
