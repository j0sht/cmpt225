#include <cstdlib>
#include <iostream>
using namespace std;
/* This program inputs two number x and y and outputs their
   sum */
int main() {
    int x, y;
    cout << "Please enter two numbers: ";
    cin >> x >> y;
    int sum = x + y;
    cout << "Their sum is " << sum << endl;
    return EXIT_SUCCESS;
}
