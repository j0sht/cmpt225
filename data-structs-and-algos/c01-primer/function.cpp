#include <iostream>
using namespace std;

// Function declaration
// NOTE: Arrays are not passed by value.
//  - Instead a pointer to the first element is passed
//    to the function
//  - Changes made to an array inside a function last beyond
//    its lifetime.
bool evenSum(int a[], int n);

// By default, arguments are passed by value (copied)
// For example, value below is a copy (new initialization),
//  of the formal argument passed to it. To avoid copies,
//  you can pass by reference. If the referenced parameter
//  is not prefixed by 'const', changes made to the referenced
//  argument in the function will persist beyond the functions
//  lifetime
void f(int value, int& ref) {
    value++; // No effect to actual argument
    ref++; // Modifies actual argument
    cout << value << endl // Outputs 2
	 << ref << endl;  // Outputs 6
}

int main() {
    int list[] = { 4,2,7,8,5,1 };
    // Function invocation
    bool result = evenSum(list, 6);
    if (result)
	cout << "The sum is even.\n";
    else
	cout << "The sum is odd.\n";

    int cat = 1;
    int dog = 5;
    f(cat, dog);
    cout << cat << endl  // Outputs 1
	 << dog << endl; // Outputs 6
    return 0;
}

// Function definition
bool evenSum(int a[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++)
	sum += a[i];
    return ((sum%2) == 0);
}
