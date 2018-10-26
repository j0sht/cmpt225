/* APPLICATION: HTML tag matching
 *
 * Similar idea to paren match.
 */
#include <iostream>
#include <vector>
#include <string>
#include "stack.h"
using namespace std;

// WARNING: Assumes that all tags are syntactically well formed.
vector<string> getHTMLTags() {
  // vector of HTML tags
  vector<string> tags;
  // read until end of file
  while (cin) {
    string line;
    // input a full line of text
    getline(cin, line);
    // current scan position
    int pos = 0;
    // possible tag start
    int ts = line.find("<", pos);
    // repeat until end of string
    while (ts != string::npos) {
      // scan for tag end
      int te = line.find(">", ts+1);
      // append tag to the vector
      tags.push_back(line.substr(ts, te-ts+1));
      // advance position
      pos = te + 1;
      ts = line.find("<", pos);
    }
  }
  return tags;
}

bool isHTMLMatched(const vector<string>& tags) {
  // stack for opening tags
  Stack<string> s; // should use linked-stack implementation
  // iterator type
  typedef vector<string>::const_iterator Iter;
  // iterate through vector
  for (Iter p = tags.begin(); p != tags.end(); ++p) {
    // opening tag? (checks by seeing that it is NOT a closing tag)
    if (p->at(1) != '/')
      // push it onto the stack
      s.push(*p);
    else { // must be closing tag
      // nothing to match - failure
      if (s.empty()) return false;
      // opening tag excluding '<'
      string open = s.top().substr(1);
      // closing tag excluding '</'
      string close = p->substr(2);
      // fail to match
      if (open.compare(close) != 0) return false;
      // pop matched element
      else s.pop();
    }
  }
  // everything matched - good
  if (s.empty()) return true;
  // some unmatched - bad
  else return false;
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
  vector<string> htmlTags = getHTMLTags();
  cout << "Tags: ";
  printVector(htmlTags);
  if (isHTMLMatched(htmlTags)) // test tags
    cout << "The input file is a matched HTML document.\n";
  else
    cout << "The input file is not a matched HTML document.\n";
  return 0;
}
