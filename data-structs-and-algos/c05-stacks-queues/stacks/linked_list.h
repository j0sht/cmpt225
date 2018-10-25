#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include <iostream>
#include <string>
using namespace std;

template <typename Elem>
class LinkedList {
public:
  LinkedList();
  ~LinkedList();
  bool empty() const;
  const Elem& front() const;
  void addFront(const Elem& e);
  void removeFront();
  void printList() const;
private:
  struct Node {
    Elem elem;
    Node* next;
  };
  Node* head;
};

// Constructor
template <typename Elem>
LinkedList<Elem>::LinkedList(): head(NULL) {}
// Destructor
template <typename Elem>
LinkedList<Elem>::~LinkedList() {
    while (!empty())
	removeFront();
}
// Is list empty?
template <typename Elem>
bool LinkedList<Elem>::empty() const {
    return head == NULL;
}
// Get front element
template <typename Elem>
const Elem& LinkedList<Elem>::front() const {
    return head->elem;
}
// Inserting to the front of a singly-linked list:
//  - Create a new node
//     - set its elem value to desired string
//     - set its next link to point to the current head
//  - Set head to new node
template <typename Elem>
void LinkedList<Elem>::addFront(const Elem& e) {
    Node* newNode = new Node;
    newNode->elem = e;
    newNode->next = head;
    head = newNode;
}
// Removing an item from the front of a singly-linked list
//  - Save a pointer to the old head
//  - Advance the head to the next node in the list
//  - Delete the old head
// WARNING: Assumes the list is not empty
template <typename Elem>
void LinkedList<Elem>::removeFront() {
    Node* old = head;
    head = old->next;
    delete old;
}
template <typename Elem>
void LinkedList<Elem>::printList() const {
    cout << "List:\n";
    cout << "  " << head->elem << " (head)\n";
    Node* curr = head->next;
    while (curr && curr->next) {
	cout << "  " << curr->elem << endl;
	curr = curr->next;
    }
    cout << "  " << curr->elem << " (tail)\n";
}
#endif
