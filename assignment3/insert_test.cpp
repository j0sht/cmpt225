/*************************************************************
   Test Program for Basic Heap Class
**************************************************************/
#include <iostream>
#include "heap.h"
using namespace std;

void heapTest();
 
int main(){
      heapTest();
      return 0;
}

void heapTest(){
 
      bool OK ;

      // Test TrickleUp 
      // Use: default constructor, insert, peekMin, and peekMinPriority.
      Heap H;
      OK = true ;

      H.insert(91,7);
      if( H.peekMin() != 91 || H.peekMinPriority() != 7 ) OK = false ;
      H.insert(92,6);
      if( H.peekMin() != 92 || H.peekMinPriority() != 6 ) OK = false ;
      H.insert(94,5);
      if( H.peekMin() != 94 || H.peekMinPriority() != 5 ) OK = false ;
      H.insert(93,8);
      H.insert(95,9);
      H.insert(85,10);
      H.insert(84,12);
      if( H.peekMin() != 94 || H.peekMinPriority() != 5 ) OK = false ;
      H.insert(83,4);
      if( H.peekMin() != 83 || H.peekMinPriority() != 4 ) OK = false ;
      H.insert(82,6);
      H.insert(81,3);
      if( H.peekMin() != 81 || H.peekMinPriority() != 3 ) OK = false ;
      if( H.size() != 10 ) OK = false ;
      H.print();
      cout << OK << endl ;
}
