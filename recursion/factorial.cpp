#include <iostream>
using namespace std;

int recursiveFactorial(int n) {
    if (n == 0) return 1; // base case
    else return n * recursiveFactorial(n-1); // recursive case
}

int main() {
    for (int i = 0; i < 6; i++)
	cout << "Factorial " << i << " = " << recursiveFactorial(i) << endl;
    return 0;
}
