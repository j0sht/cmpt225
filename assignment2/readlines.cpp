#include <iostream>
using namespace std;

int main() {
    string strings[10];
    string input;
    int i = 0;
    while (getline(cin, input) && input != "\0")
	strings[i++] = input;
    for (int j = 0; j < i; j++)
	cout << strings[j] << endl;
    return 0;
}
