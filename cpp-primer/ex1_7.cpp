#include <iostream>
using namespace std;

// Input: an integer n >= 1
// Output: Sum of integers 0+1+...+n
int sumUpTo(int n) {
    int sum = 0;
    for (int i = 1; i <= n; i++)
	sum += i;
    return sum;
}

// Alt
int sumUpTo_v2(int n) {
    return (n*(n+1)) / 2;
}

int main() {
    cout << "Sum of 1+2+3+...+9 = " << sumUpTo(9) << endl;
    cout << "sumUpTo(9) == sumUpTo_v2(9)? "
	 << ((sumUpTo(9) == sumUpTo_v2(9)) ? "True" : "False") << endl;
    return 0;
}
