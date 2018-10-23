#include <iostream>
using namespace std;

class EmptyList {};

class StringLinkedList {
public:
    StringLinkedList(); // empty list constructor
    ~StringLinkedList(); // destructor
    bool empty() const; // is the list empty?
    const string& front() const; // get front element
    void addFront(const string& e); // add to front of list
    void removeFront() throw (EmptyList); // remove front item of the list

    friend ostream& operator<<(ostream& outs, const StringLinkedList& list);
private:
    struct StringNode {
	string elem;
	StringNode* next;
    };
    StringNode* head;
};

// Constructor
StringLinkedList::StringLinkedList(): head(NULL) {}
// Destructor
StringLinkedList::~StringLinkedList() {
    while (!empty())
	removeFront();
}
// Is list empty?
bool StringLinkedList::empty() const {
    return head == NULL;
}
// Get front element
const string& StringLinkedList::front() const {
    return head->elem;
}
// Inserting to the front of a singly-linked list:
//  - Create a new node
//     - set its elem value to desired string
//     - set its next link to point to the current head
//  - Set head to new node
void StringLinkedList::addFront(const string& e) {
    StringNode* newNode = new StringNode;
    newNode->elem = e;
    newNode->next = head;
    head = newNode;
}
// Removing an item from the front of a singly-linked list
//  - Save a pointer to the old head
//  - Advance the head to the next node in the list
//  - Delete the old head
void StringLinkedList::removeFront() throw (EmptyList) {
    if (empty())
	throw EmptyList();
    StringNode* old = head;
    head = old->next;
    delete old;
}
ostream& operator<<(ostream& outs, const StringLinkedList& list) {
    outs << "List:\n";
    outs << "  " << list.head->elem << " (head)\n";
    StringLinkedList::StringNode* curr = list.head->next;
    while (curr && curr->next) {
	outs << "  " << curr->elem << endl;
	curr = curr->next;
    }
    outs << "  " << curr->elem << " (tail)";
    return outs;
}

int main() {
    StringLinkedList list;
    list.addFront("BOS");
    list.addFront("ATL");
    list.addFront("MSP");
    list.addFront("LAX");
    cout << "Before removal:\n";
    cout << list << endl;
    list.removeFront();
    cout << "\nAfter removal:\n";
    cout << list << endl;
    return 0;
}
