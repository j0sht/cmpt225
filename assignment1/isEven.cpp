#include <iostream>
using namespace std;

int main() {
    int x;
    cin >> x;
    if (cin.peek() == '\n')
	if ((x % 2) == 0)
	    cout << "Even";
	else
	    cout << "Odd";
    else
	cout << "Nonint";
    return 0;
}
