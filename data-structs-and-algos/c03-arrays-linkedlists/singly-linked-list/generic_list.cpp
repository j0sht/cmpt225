#include <iostream>
#include <string>
using namespace std;

template <typename Elem>
class SinglyLinkedList {
public:
    SinglyLinkedList();
    ~SinglyLinkedList();
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
SinglyLinkedList<Elem>::SinglyLinkedList(): head(NULL) {}
// Destructor
template <typename Elem>
SinglyLinkedList<Elem>::~SinglyLinkedList() {
    while (!empty())
	removeFront();
}
// Is list empty?
template <typename Elem>
bool SinglyLinkedList<Elem>::empty() const {
    return head == NULL;
}
// Get front element
template <typename Elem>
const Elem& SinglyLinkedList<Elem>::front() const {
    return head->elem;
}
// Inserting to the front of a singly-linked list:
//  - Create a new node
//     - set its elem value to desired string
//     - set its next link to point to the current head
//  - Set head to new node
template <typename Elem>
void SinglyLinkedList<Elem>::addFront(const Elem& e) {
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
void SinglyLinkedList<Elem>::removeFront() {
    Node* old = head;
    head = old->next;
    delete old;
}

template <typename Elem>
void SinglyLinkedList<Elem>::printList() const {
    cout << "List:\n";
    cout << "  " << head->elem << " (head)\n";
    Node* curr = head->next;
    while (curr && curr->next) {
	cout << "  " << curr->elem << endl;
	curr = curr->next;
    }
    cout << "  " << curr->elem << " (tail)\n";
}

int main() {
    SinglyLinkedList<string> list;
    list.addFront("BOS");
    list.addFront("ATL");
    list.addFront("MSP");
    list.addFront("LAX");
    cout << "Before removal:\n";
    list.printList();
    list.removeFront();
    cout << "\nAfter removal:\n";
    list.printList();
    return 0;
}
