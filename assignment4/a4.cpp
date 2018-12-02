// 301280241 jmtate Joshua Tate
#include <iostream>
#include <queue> // For priority_queue
using namespace std;

void readFileAndStoreIn(priority_queue<int>& p1, priority_queue<int>& p2);
int answer(priority_queue<int>& p1, priority_queue<int>& p2);
// debug function
void printQueues(priority_queue<int>& p1, priority_queue<int>& p2);

int main() {
  priority_queue<int> p1;
  priority_queue<int> p2;
  cout << "301280241 jmtate Joshua Tate\n";
  readFileAndStoreIn(p1, p2);
  printQueues(p1, p2);
  cout << answer(p1,p2) << endl;
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

int answer(priority_queue<int>& p1, priority_queue<int>& p2) {
  // Complete this
  return 0;
}

void printQueues(priority_queue<int>& p1, priority_queue<int>& p2) {
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
