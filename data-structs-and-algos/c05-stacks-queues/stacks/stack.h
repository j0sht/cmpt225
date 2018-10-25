#ifndef STACK_H
#define STACK_H
#include <iostream>
#include <string>
#include <stdexcept> // for runtime_error
#include "linked_list.h"
using namespace std;

class StackEmpty: public runtime_error {
public:
  StackEmpty(const string& err): runtime_error(err) {}
};
template <typename E>
class Stack {
public:
  Stack();
  ~Stack();
  int size() const;
  bool empty() const;
  const E& top() const throw(StackEmpty);
  void push(const E& e);
  void pop() throw(StackEmpty);
  void printStack();
private:
  LinkedList<E>* list;
  int n;
};

template <typename E>
Stack<E>::Stack() {
  this->n = 0;
  this->list = new LinkedList<E>();
}
template <typename E>
Stack<E>::~Stack() {
  delete list;
}
template <typename E>
int Stack<E>::size() const {
  return n;
}
template <typename E>
bool Stack<E>::empty() const {
  return n == 0;
}
template <typename E>
const E& Stack<E>::top() const throw(StackEmpty) {
  if (empty()) throw StackEmpty("Empty stack");
  return list->front();
}
template <typename E>
void Stack<E>::push(const E& e) {
  list->addFront(e);
  n++;
}
template <typename E>
void Stack<E>::pop() throw(StackEmpty) {
  if (empty()) throw StackEmpty("Empty stack");
  list->removeFront();
  n--;
}
template <typename E>
void Stack<E>::printStack() {
  Stack<E> temp;
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
