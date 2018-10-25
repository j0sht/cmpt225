#include <iostream>
#include "stack.h"
using namespace std;

int main() {
  Stack<int> s(7);
  cout << "Pushing 7, 13\n";
  s.push(7);
  s.push(13);
  cout << "Top of stack: " << s.top() << endl;
  cout << "Stack size = " << s.size() << endl;
  cout << "Popping stack.\n";
  s.pop();
  cout << "After pop:\n";
  s.printStack();
  s.push(9);
  cout << "Pushing 9\n";
  s.printStack();
  s.pop();
  cout << "After pop:\n";
  s.printStack();
  cout << "Top of stack: " << s.top() << endl;
  Stack<string> s2(10);
  s2.push("Bob");
  s2.push("Alice");
  s2.printStack();
  cout << "Top of stack: " << s2.top() << endl;
  s2.pop();
  cout << "After pop:\n";
  s2.printStack();
  s2.push("Eve");
  s2.printStack();
  return 0;
}
