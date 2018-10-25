#include <iostream>
#include "stack.h"
using namespace std;

int main() {
  Stack<int> s;
  cout << "Pushing 9,7,3,5\n";
  s.push(9);
  s.push(7);
  s.push(3);
  s.push(5);
  cout << "Top of stack: " << s.top() << endl;
  cout << "Stack size = " << s.size() << endl;
  s.pop();
  cout << "\nAfter pop:\n" << s;
  s.push(8);
  cout << "Pushing 8\n" << s;
  s.pop();
  cout << "\nAfter pop:\n" << s;
  cout << "Top of stack: " << s.top() << endl;
  return 0;
}
