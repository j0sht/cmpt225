#include <iostream>
#include <string>
using namespace std;

typedef string Elem;
class DoublyLinkedList {
public:
  DoublyLinkedList();
  ~DoublyLinkedList();
  bool empty() const;
  const Elem& front() const;
  const Elem& back() const;
  void addFront(const Elem& e);
  void addBack(const Elem& e);
  void removeFront();
  void removeBack();
  friend ostream& operator<<(ostream& outs, const DoublyLinkedList& list);

private:
  struct Node {
    Elem elem;
    Node* prev;
    Node* next;
  };
  /* Dummy nodes */
  //  - Do not store any elements
  //  - Provide quick access to the first and last nodes of the list
  //  - header->next points to the first node of the list
  //     - header->prev = NULL
  //  - trailer->prev points to the last node of the list
  //     - trailer-next = NULL
  Node* header;
  Node* trailer;

protected:
  // protected members can be used internally by the class and
  //  by its subclasses, but cannot be invoked from outside the class.
  void add(Node* v, const Elem& e); // insert new node before v
  void remove(Node* v); // remove node v
};

// Constructor
DoublyLinkedList::DoublyLinkedList() {
  header = new Node;
  trailer = new Node;
  // Have dummy nodes point to one another
  // Note header->prev and trailer->next are NULL by default
  header->next = trailer;
  trailer->prev = header;
}
// Destructor
DoublyLinkedList::~DoublyLinkedList() {
  while (!empty()) removeFront(); // Remove all but the sentinals
  delete header;
  delete trailer;
}
// Is the list empty?
bool DoublyLinkedList::empty() const {
  return (header->next == trailer);
}
// WARNING: Assumes the list is not empty
const Elem& DoublyLinkedList::front() const {
  return header->next->elem;
}
const Elem& DoublyLinkedList::back() const {
  return trailer->prev->elem;
}
// Insert new node before v (protected function)
void DoublyLinkedList::add(Node* v, const Elem& e) {
  Node* u = new Node;
  u->elem = e;
  v->prev->next = u;
  u->prev = v->prev;
  u->next = v;
  v->prev = u;
}
// Add to front of the list
void DoublyLinkedList::addFront(const Elem& e) {
  // Inserts immediately after the header, or equivalently,
  //  immediately before the node that follows the header.
  add(header->next, e);
}
// Add to back of the list
void DoublyLinkedList::addBack(const Elem &e) {
  // Inserts immediately before the trailer
  add(trailer, e);
}
// Remove node v from the list
void DoublyLinkedList::remove(Node* v) {
  Node* u = v->prev; // predecessor
  Node* w = v->next; // successor
  u->next = w; // unlink v from list
  w->prev = u;
  delete v;
}
// Remove from the front
void DoublyLinkedList::removeFront() {
  remove(header->next);
}
// Remove from the back
void DoublyLinkedList::removeBack() {
  remove(trailer->prev);
}
ostream& operator<<(ostream& outs, const DoublyLinkedList& list) {
  if (list.header->next == list.trailer) {
    outs << "List is empty.";
    return outs;
  }
  DoublyLinkedList::Node* curr = list.header->next;
  outs << "List:\n";
  if (curr->next == list.trailer) {
    outs << "  " << curr->elem << " (front and back)";
    return outs;
  }
  while (curr->next != list.trailer) {
    outs << "  " << curr->elem;
    if (curr->prev == list.header)
      outs << " (front)";
    outs << endl;
    curr = curr->next;
  }
  outs << "  " << curr->elem << " (back)";
  return outs;
}

int main() {
    DoublyLinkedList list;
    list.addFront("BOS");
    list.addFront("ATL");
    list.addFront("MSP");
    list.addFront("LAX");
    cout << list << endl;
    list.removeBack(); // Remove BOS
    cout << list << endl;
    list.removeFront(); // Remove LAX
    cout << list << endl;
    list.removeBack(); // Remove ATL
    cout << list << endl;
    list.removeBack(); // Remove MSP
    cout << list << endl;
    return 0;
}
