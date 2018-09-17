#include <iostream>
using namespace std;

int main() {
    int x;
    cin >> x;
    int c = cin.peek();
    if (c != '.')
	if ((x % 2) == 0)
	    cout << "Even";
	else
	    cout << "Odd";
    else
	cout << "Nonint";
    return 0;
}
