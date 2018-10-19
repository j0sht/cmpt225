#include <iostream>
using namespace std;

int main() {
    cout << "Size of char: " << sizeof(char) << endl
	 << "Size of int: " << sizeof(int) << endl
	 << "Size of short: " << sizeof(short int) << endl
	 << "Size of long: " << sizeof(long int) << endl
	 << "Size of bool: " << sizeof(bool) << endl
	 << "Size of float: " << sizeof(float) << endl // There's no short/long float
	 << "Size of double: " << sizeof(double) << endl // There's no short double
	 << "Size of long double: " << sizeof(long double) << endl;
    return 0;
}
