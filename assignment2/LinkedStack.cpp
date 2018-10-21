//==========================================================================
// Name        : LinkedStack.cpp
// Author      : Joshua Tate
// Version     : 1
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//==========================================================================
#include <cstdlib>
#include <iostream>
#include <string>
using std::string;
using namespace std;

// a node in a list of strings
class StringNode {
private:
    // element value
    string elem;
    // next item in the list
    StringNode* next;

    // provide StringLinkedList access
    friend class StringLinkedList;
};

// a linked list of strings
class StringLinkedList {
public:
    // empty list constructor
    StringLinkedList();
    // destructor
    ~StringLinkedList();
    // is list empty?
    bool empty() const;
    // get front element
    const string& front() const;
    // add to front of list
    void addFront(const string& e);
    // remove front item list
    void removeFront();
private:
    // pointer to the head of list
    StringNode* head;
};

// constructor
StringLinkedList::StringLinkedList() : head(NULL) {}

// destructor
StringLinkedList::~StringLinkedList() {
    while (!empty())
	removeFront();
}

// is list empty?
bool StringLinkedList::empty() const {
    return head == NULL;
}

// get front elements
const string& StringLinkedList::front() const {
    return head->elem;
}

// add to front of list
void StringLinkedList::addFront(const string& e) {
    // create new node
    StringNode* v = new StringNode;
    // store data
    v->elem = e;
    // head now follows v
    v->next = head;
    // v is now the head
    head = v;
}

// remove front item
void StringLinkedList::removeFront() {
    // save current head
    StringNode* old = head;
    // skip over old head
    head = old->next;
    // delete the old head
    delete old;
}

// stack element type
typedef string Elem;

// stack as a linked list
class LinkedStack {
public:
    // constructor
    LinkedStack();
    // number of items in the stack
    int size() const;
    // is the stack empty?
    bool empty() const;
    // the top element
    const Elem& top() const;
    // push element onto stack
    void push(const Elem& e);
    // pop the stack
    void pop();
private:
    // member data
    // linked list of elements
    StringLinkedList S;
    // number of elements
    int n;
};

// constructor
LinkedStack::LinkedStack() : S(), n(0) {}

// get size of the stack
int LinkedStack::size() const {
    return n;
}

// is the stack empty?
bool LinkedStack::empty() const {
    return n == 0;
}

// see element at top of the stack
const Elem& LinkedStack::top() const {
    return S.front();
}

// push element onto stack
void LinkedStack::push(const Elem& e) {
    ++n;
    S.addFront(e);
}

// pop the stack
void LinkedStack::pop() {
    --n;
    S.removeFront();
}

// main helper functions
void printNameAndID();
void sayGoodbye();

int main() {
    printNameAndID();

    // Create instances of LinkedStack
    LinkedStack stack, temp;

    // Read lines and store in stack
    Elem input;
    while (getline(cin, input) && input != "\0")
	stack.push(input);

    // Print stack size and print concatenation of Elems
    //  in reverse order.
    cout << endl << stack.size() << endl;
    while (!stack.empty()) {
	Elem s = stack.top();
	cout << s;
	temp.push(s);
	stack.pop();
    }
    cout << endl;

    // Print Elems in original order
    while (!temp.empty()) {
	cout << temp.top() << endl;
	temp.pop();
    }

    sayGoodbye();
    return EXIT_SUCCESS;
}

void printNameAndID() {
    cout << "Joshua Tate\n"
	 << "jmtate\n"
	 << "301280241\n";
}
void sayGoodbye() {
    cout << "goodbye\n";
}
