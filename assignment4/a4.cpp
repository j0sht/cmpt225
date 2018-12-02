// 301280241 jmtate Joshua Tate
#include <iostream>
#include <queue>
#include <map>
using namespace std;

void readFileAndStoreIn(priority_queue<int>& p1, priority_queue<int>& p2);
void answer(priority_queue<int>& p1, priority_queue<int>& p2);
// debug function
void printQueues(const priority_queue<int>& p1, const priority_queue<int>& p2);

int main() {
  priority_queue<int> p1;
  priority_queue<int> p2;
  cout << "301280241 jmtate Joshua Tate\n";
  readFileAndStoreIn(p1, p2);
  answer(p1,p2);
  return 0;
}

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

void answer(priority_queue<int>& p1, priority_queue<int>& p2) {
  while ((!p1.empty() && !p2.empty()) && (p1.top() <= p2.top())) {
    if (p1.top() == p2.top()) {
      p1.pop();
      p2.pop();
    } else { // p1.top() < p2.top()
      p2.pop();
    }
  }
  if (!p1.empty())
    cout << p1.top() << endl;
  else
    cout << "NONE\n";
}

void printQueues(const priority_queue<int>& p1, const priority_queue<int>& p2) {
  priority_queue<int> tmp = p1;
  if (!p1.empty()) {
    cout << "p1: ";
    while (!tmp.empty()) {
      if (tmp.size() > 1)
	cout << tmp.top() << ", ";
      else
	cout << tmp.top() << endl;
      tmp.pop();
    }
  }
  if (!p2.empty()) {
    cout << "p2: ";
    tmp = p2;
    while (!tmp.empty()) {
      if (tmp.size() > 1)
	cout << tmp.top() << ", ";
      else
	cout << tmp.top() << endl;
      tmp.pop();
    }
  }
}
