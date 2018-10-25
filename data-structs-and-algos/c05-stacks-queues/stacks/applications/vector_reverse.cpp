#include <iostream>
#include <vector>
#include "stack.h"
using namespace std;

/* APPLICATION: Reversing a vector using a stack
 *
 * A non recursive algorithm for array reversal.
 *
 * General idea:
 *  - Push all the elements of the vector in order into a stack,
 *    then fill the vector back up by popping the elements off the stack.
 */
template <typename E>
void reverse(vector<E>& v) {
  Stack<E> s(v.size());
  for (int i = 0; i < v.size(); i++)
    s.push(v[i]);
  for (int i = 0; i < v.size(); i++) {
    v[i] = s.top();
    s.pop();
  }
}
template <typename E>
void printVector(const vector<E>& v) {
  for (int i = 0; i < v.size(); i++) {
    if (i == 0)
      cout << "[";
    cout << v[i];
    if (i == v.size()-1)
      cout << "]";
    else
      cout << ", ";
  }
  cout << endl;
}
int main() {
  static const string names[] = { "Jack", "Kate", "Hurley",
				  "Jin", "Michael" };
  vector<string> v(names, names + sizeof(names)/sizeof(names[0]));
  cout << "Before reverse: ";
  printVector(v);
  reverse(v);
  cout << "After reverse: ";
  printVector(v);
  return 0;
}
