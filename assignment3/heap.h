#include <iostream>
/******************************************************
  Heap.h -- Declarations for Basic Heap-of-Pair-of-Ints Class

  Stores pairs <element,priority> of ints.
  Supports O(log n) insertion, O(1) peeking at min priority and element 
  with min priority, and O(log n) extraction of element with min priority.
*******************************************************/
using namespace std;

class Heap{

public:
  // Constructors and Destructor
  
  // New empty Heap with default capacity.
  Heap();  
  
  // New empty Heap with capacity c.
  Heap(int c); 
  
  // New Heap with size s, consisting of pairs <Pi,Ei> where, 
  // for 0 <= i < s, Pi is Priorities[i] and Ei is value Elements[i].  
  // Capacity is s + c, where c is the "spare capacity" argument.
  // Requires: Priorities and Elements are of size at least s. 
  Heap( const int * Priorities, const int * Elements, int s, int c); 
  
  // New Heap with combined contents the two Heap arguments. 
  // Size of the new Heap is the sum of the sizes of argument Heaps.
  // Capacity of the new Heap is its size plus the "spare capacity" c.
  Heap( const Heap & Heap1, const Heap & Heap2, int c ); 
  
  // Destructor.
  ~Heap(); 
  
  // Accessors
  bool empty() const {return hSize == 0;}; // True iff Heap is empty.
  int size() const { return hSize ;} ; // Current size of Heap.
  int capacity() const { return hCapacity ;} ; // Current capacity.
  int peekMin() const { return A[0].element ;} // Peek at minimum priority element.
  int peekMinPriority() const { return A[0].priority ;} // Peek at minimum priority.
  
  // Modifiers
  void insert( int element, int priority ); // Insert the pair <element,priority>.
  int extractMin(); // Remove and return the highest (minimum) priority element.

  // Debug print
  void print();
private:
  class Pair{
  public:
    int element ;
    int priority ;
  };
  
  Pair* A ; // Array containing heap contents.
  int hCapacity ; // Max number of elements (= size of A).
  int hSize ; // Current number of elements.
  
  // Repairs ordering invariant after adding leaf at A[i].
  void trickleUp(int i);
  
  // Repairs ordering invariant for sub-tree rooted at index i,
  //   when A[i] may be have larger priority than one of its children,
  //   but the subtrees of its children are heaps.
  void trickleDown(int i);
  
  // Establishes ordering invariant for entire array contents.
  void heapify(); //(Same as "make_heap" in lectures.)
  
  // Useful for implementing trickle up and down
  void swap(int i,int j);

  // Index for parent of index i
  int parent(int i) { return (i-1)/2; }
  int leftChild(int i) { return (2*i)+1; }
  int rightChild(int i) { return (2*i)+2; }
};

Heap::Heap(){
  hCapacity = 10 ;
  A = new Pair[hCapacity];
  hSize = 0 ; 
}

Heap::Heap(int c){ // New empty Heap with capacity c.
  hCapacity = c;
  A = new Pair[hCapacity];
  hSize = 0;
}

// New Heap with capacity c+s, with s elements, consisting of pairs <Pi,Vi> where 
//  Pi is Priorities[i], Ei is value Elements[i], for 0 <= i < s.
Heap::Heap( const int * Priorities, const int * Elements, int s, int c){ 
  // Complete this.
  hCapacity = c+s;
  A = new Pair[hCapacity];
  hSize = 0;
  for (int i = 0; i < s; i++)
    insert(Elements[i], Priorities[i]);
}

// New Heap with combined contents and of the two given heaps.
Heap::Heap( const Heap & Heap1, const Heap & Heap2, int c ){ 
  hCapacity = Heap1.hSize + Heap2.hSize + c ;
  A = new Pair[hCapacity];
  hSize = 0;
  // Complete this.
  // for (int i = 0; i < Heap1.size(); i++)
  //   insert(Heap1.A[i].element, Heap1.A[i].priority);
  // for (int i = 0; i < Heap2.size(); i++)
  //   insert(Heap2.A[i].element, Heap2.A[i].priority);
  int n = Heap1.hSize;
  for (int i = 0; i < n; i++) {
    A[i] = Heap1.A[i];
    hSize++;
  }
  for (int i = 0; i < Heap2.hSize; i++) {
    A[n+i] = Heap2.A[i];
    hSize++;
  }
  heapify();
}

// Destructor
Heap::~Heap(){
  delete[] A;
}

// Modifiers
void Heap::insert(int element, int priority){
  A[hSize].element = element;
  A[hSize].priority = priority;
  trickleUp(hSize);
  hSize++;
}

// Repairs the heap ordering invariant after adding a new element.
// Initial call should be trickleUp(hSize-1).
void Heap::trickleUp(int i){
  // Complete this.
  while (i > 0) {
    if (A[i].priority < A[parent(i)].priority)
      swap(i, parent(i));
    else
      break;
    i = parent(i);
  }
}

void Heap::swap(int i, int j){
  Pair temp = A[i];
  A[i] = A[j];
  A[j] = temp ;
}

// Removes and returns the element with highest priority.
// (That is, the element associated with the minimum priority value.)
int Heap::extractMin(){
  // Complete this.
  int element = A[0].element;
  
  trickleDown(0);
}

// Repairs the heap ordering invariant after replacing the root.
// (extractMin() calls trickleDown(0)).
// (trickleDown(i) performs the repair on the subtree rooted a A[i].)
// (heapify() calls trickleDown(i) for i from (hSize/2)-1 down to 0.)
void Heap::trickleDown(int i){
  // Complete this.
  
}

// Turns A[0] .. A[size-1] into a heap.
void Heap::heapify(){
  for( int i = (hSize/2)-1; i>=0 ; i-- ) trickleDown(i);  
}

void Heap::print() {
  for (int i = 0; i < hSize; i++) {
    cout << "Element " << i << ": P(" << A[i].element << ", " << A[i].priority << ")\n";
  }
}
