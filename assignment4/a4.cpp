// 301280241 jmtate Joshua Tate
#include <iostream>
#include <queue> // For priority_queue
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
  cin >> x;
  while(!cin.eof()) {
    if(x == 0)
      List2 = true;
    else
      if (List2)
	p2.push(x);
      else
	p1.push(x);
    cin >> x;
  }
}

void answer(priority_queue<int>& p1, priority_queue<int>& p2) {
  while ((!p1.empty() && !p2.empty()) && (p1.top() <= p2.top())) {
    if (p1.top() == p2.top()) {
      int e = p1.top();
      while ((!p1.empty() && !p2.empty()) && (p1.top() == e || p2.top() == e)) {
	if (p1.top() == e)
	  p1.pop();
	if (p2.top() == e)
	  p2.pop();
      }
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
  cout << "p1: ";
  priority_queue<int> tmp = p1;
  while (!tmp.empty()) {
    if (tmp.size() > 1)
      cout << tmp.top() << ", ";
    else
      cout << tmp.top() << endl;
    tmp.pop();
  }
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
