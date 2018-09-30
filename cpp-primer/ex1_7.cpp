#include <iostream>
using namespace std;

// Input: an integer n >= 1
// Output: Sum of integers 0+1+...+n-1
int sumUpTo(int n) {
    int sum = 0;
    for (int i = 1; i < n; i++)
	sum += i;
    return sum;
}
int main() {
    cout << "Sum of 1+2+3+...+8 = " << sumUpTo(9) << endl;
    return 0;
}
