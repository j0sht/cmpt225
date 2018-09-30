#include <iostream>
using namespace std;

// Input: Nonnegative integer k
// Output: The kth Fibonacci number Fk
// NOTE:
//  - Very inefficient.
//  - Takes an exponential number of calls to compute kth Fib number this way.
//  - The number of calls more than doubles for each two consecutive indices.
//    i.e. n4 is more than twice n2, n5 is more than twice n3, etc.
//  - Thus, nk > 2^(k/2), i.e BinaryFib makes number of calls exponential in k.
int binaryFib(int k) {
    if (k <= 1) return k;
    else return binaryFib(k-1) + binaryFib(k-2);
}

class IntPair {
public:
    IntPair(int i, int j) { x=i; y=j; }
    int x,y;
};
// Input: Nonnegative integer k
// Output: Pair of fibonacci numbers (Fk, Fk-1)
IntPair linearFib(int k) {
    if (k <= 1) return IntPair(k, 0);
    else {
	IntPair fibNums = linearFib(k-1);
	int tmp = fibNums.x;
	fibNums.x += fibNums.y;
	fibNums.y = tmp;
	return fibNums;
    }
}

int main() {
    cout << "binaryFib(10) = " << binaryFib(10) << endl; // 2^5 calls
    cout << "linearFib(10) = " << linearFib(10).x << endl;
}
