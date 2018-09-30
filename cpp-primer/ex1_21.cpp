#include <iostream>
using namespace std;

// Input: integer n >= 1
// Output: Sum of all odd integer's smaller than n
int oddSum(int n) {
    int sum = 0;
    for (int i = 1; i <= n; i += 2)
	sum += i;
    return sum;
}
int main() {
    cout << "1+3+5+...+9 = " << oddSum(9) << endl;
    return 0;
}
