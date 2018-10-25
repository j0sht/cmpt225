#ifndef STACK_H
#define STACK_H
#include <iostream>
#include <string>
#include <stdexcept> // for runtime_error
using namespace std;
/* ANALYSIS */
/* Each of the stack functions in the array realization executes a
 *  constant number of statements involving arithmetic operations,
 *  comparisons, and assignments.
 *
 * Each function runs in O(1) time (constant time).
 *
 * Space usage is O(N), where N is the array's size.
 *   NOTE: The space usage is independent from the number n <= N
 *         of the elements that are actually in the stack.
 *
 * Drawbacks:
 *   - Assumes a fixed upper bound N on the ultimate size of the stack.
 *
 * Alternative:
 *   - Using a vector instead of an array eliminates need for fixed
 *     upper bound, and is a practical way to implement an array-based
 *     stack.
 *
 * Pros:
 *   - When you know the number of items needed, the array-based
 *     implementation is hard to beat from perspective of speed and
 *     simplicity.
 */
class StackEmpty: public runtime_error {
public:
  StackEmpty(const string& err): runtime_error(err) {}
};
// NOTE: StackFull is specific to this implementation of a stack
//       and is not defined in the Stack ADT.
class StackFull: public runtime_error {
public:
  StackFull(const string& err): runtime_error(err) {}
};

template <typename E>
class Stack {
public:
  Stack(int cap=100);
  ~Stack();
  int size() const;
  bool empty() const;
  const E& top() const throw(StackEmpty);
  void push(const E& e);
  void pop() throw(StackEmpty);
  void printStack();
private:
  E* array;
  int t;
  int capacity;
};

template <typename E>
Stack<E>::Stack(int cap) {
  this->capacity = cap;
  this->t = -1;
  this->array = new E[capacity];
}
template <typename E>
Stack<E>::~Stack() {
  delete[] array;
}
template <typename E>
int Stack<E>::size() const {
  return t+1;
}
template <typename E>
bool Stack<E>::empty() const {
  return t < 0;
}
template <typename E>
const E& Stack<E>::top() const throw(StackEmpty) {
  if (empty()) throw StackEmpty("Top of empty stack");
  return array[t];
}
template <typename E>
void Stack<E>::push(const E& e) {
  if (size() == capacity) throw StackFull("Push to full stack");
  array[++t] = e;
}
template <typename E>
void Stack<E>::pop() throw(StackEmpty) {
  if (empty()) throw StackEmpty("Pop from empty stack");
  t--;
}
template <typename E>
void Stack<E>::printStack() {
  Stack<E> temp(capacity);
  cout << "Stack:\n";
  while (!empty()) {
    cout << "  " << top() << endl;
    temp.push(top());
    pop();
  }
  while (!temp.empty()) {
    push(temp.top());
    temp.pop();
  };
}
#endif
