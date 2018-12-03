// 301280241 jmtate Joshua Tate
#include <iostream>
#include <queue>
#include <map>
using namespace std;

// Reads two lists of integers from stdin and stores them in p1 and p2
//  while filtering out any duplicate numbers
void readAndStoreIn(priority_queue<int>& p1, priority_queue<int>& p2);
// Prints the value of the largest element in p1 that is not in p2.
// Assumes that there are no duplicate entries within either p1 or p2.
void printLargest(priority_queue<int>& p1, priority_queue<int>& p2);

/* MAIN */
int main() {
  cout << "301280241 jmtate Joshua Tate\n";
  priority_queue<int> p1, p2;
  readAndStoreIn(p1, p2);
  printLargest(p1, p2);
  return 0;
}
/* END MAIN */

void readAndStoreIn(priority_queue<int>& p1, priority_queue<int>& p2) {
  int x;
  bool List2 = false;
  map<int, int> values; // used to ignore repeated values
  cin >> x;
  while(!cin.eof()) {
    if(x == 0) {
      List2 = true;
      values = map<int, int>();
    } else {
      if (values.count(x) == 0) {
	if (List2)
	  p2.push(x);
	else
	  p1.push(x);
      }
    }
    if (x != 0)
      values.insert(pair<int,int>(x,1));
    cin >> x;
  }
}
void printLargest(priority_queue<int>& p1, priority_queue<int>& p2) {
  while ((!p1.empty() && !p2.empty()) && (p1.top() <= p2.top())) {
    if (p1.top() == p2.top())
      p1.pop();
    p2.pop();
  }
  if (!p1.empty())
    cout << p1.top() << endl;
  else
    cout << "NONE\n";
}
