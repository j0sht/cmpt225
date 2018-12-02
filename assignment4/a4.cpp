// 301280241 jmtate Joshua Tate
#include <iostream>
#include <queue>
#include <map>
using namespace std;

void readFileAndStoreIn(priority_queue<int>& p1, priority_queue<int>& p2);
void printLargest(priority_queue<int>& p1, priority_queue<int>& p2);

/* MAIN */
int main() {
  priority_queue<int> p1;
  priority_queue<int> p2;
  cout << "301280241 jmtate Joshua Tate\n";
  readFileAndStoreIn(p1, p2);
  printLargest(p1, p2);
  return 0;
}
/* END MAIN */

void readFileAndStoreIn(priority_queue<int>& p1, priority_queue<int>& p2) {
  int x;
  bool List2 = false;
  map<int, int> values; // used to ignore repeated values
  cin >> x;
  while(!cin.eof()) {
    if(x == 0) {
      List2 = true;
      values = map<int, int>();
    } else {
      if (List2) {
	if (values.count(x) == 0)
	  p2.push(x);
      } else {
	if (values.count(x) == 0)
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
