/* APPLICATION: Parentheses Matching
 *
 * Given a sequence X = x0,x1,...,x(n-1), where each x(i) is a token, that
 *  can be a grouping symbol, a variable name, an arithmetic operator, or
 *  a number.
 *
 * Process the tokens in X in order.
 *
 * Each time an opening symbol is encountered, push that symbol onto stack S.
 * Each time a closing symbol is encountered, pop the top symbol from S
 *  (assuming S is not empty), and check that top matches closing symbol.
 * For example, if the symbol "(" was pushed, the symbol ")" should be its
 *  match.
 *
 * If the stack is empty after the whole sequence is processed, then the
 *  symbols in X match.
 *
 * Assuming push and pop operations are implemented to run in constant
 *  time, this algorithm runs in O(n) total time.
 */
#include <iostream>
#include "stack.h"
using namespace std;

// NOTE: simple implementation that only considers "(" and ")" as grouping
//       symbols
bool paren_match(string* sequence, int n) {
  Stack<string> s;
  for (int i = 0; i < n; i++) {
    if (sequence[i] == "(")
      s.push(sequence[i]);
    else if (sequence[i] == ")") {
      if (s.empty()) // nothing to match with
	return false;
      if (s.top() != "(") // wrong type
	return false;
      s.pop();
    }
  }
  if (s.empty())
    return true; // every symbol matched
  else
    return false; // some symbols were never matched
}

int main() {
  string correct[] = {"(",")","(","(",")",")"}; // 6 elements
  string incorrect[] = {")","(","(",")",")",")"}; // 6 elements
  string incorrect2[] = {"("}; // 1 element
  cout << paren_match(correct, 6) << endl; // true
  cout << paren_match(incorrect, 6) << endl; // false
  cout << paren_match(incorrect2, 1) << endl; // false
  return 0;
}
