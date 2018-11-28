#include <iostream>
#include <queue>
#include <deque>
using namespace std;

/*
 * Suppose you have a deque D containing the numbers (1,2,3,4,5,6,7,8), in this
 *  order.
 * Suppose further that you have an intially empty queue Q.
 * Implement a function that uses only D and Q (and no other variable or objects)
 *  and results in D storing the elements (1,2,3,5,4,6,7,8), in this order.
 */

void swapFourAndFive(deque<int>& D, queue<int>& Q) {
  while (D.front() != 4) {
    Q.push(D.front());
    D.pop_front();
    D.push_back(Q.front());
    Q.pop();
  }
  // After loop: D = (4,5,6,7,8,1,2,3); Q = ()
  Q.push(D.front()); D.pop_front();
  Q.push(D.front()); D.pop_front();
  // D = (6,7,8,1,2,3); Q = (4,5)
  D.push_front(Q.front()); Q.pop();
  // D = (4,6,7,8,1,2,3); Q = (5)
  D.push_back(Q.front()); Q.pop();
  // D = (4,6,7,8,1,2,3,5); Q = ()
  while (D.front() != 1) {
    Q.push(D.front());
    D.pop_front();
    D.push_back(Q.front());
    Q.pop();
  }
  // After loop: D = (1,2,3,5,4,6,7,8); Q = ()
}

void printDeque(deque<int>& D) {
  cout << "D = (";
  int i;
  for (i = 0; i < D.size()-1; i++)
    cout << D[i] << ", ";
  cout << D[i] << ")\n";
}

int main() {
  deque<int> D;
  for (int i = 1; i < 9; i++)
    D.push_back(i);
  queue<int> Q;
  cout << "Before function:\n\t";
  printDeque(D);
  swapFourAndFive(D,Q);
  cout << "After function:\n\t";
  printDeque(D);
  return 0;
}
