/*
**  a4.cpp
**  Assignment 4, CMPT-225
**
**  Reads a sequence of integers (in the range of int's) from standard in;
**  It is interpreted as two lists, separated by a single 0
**/
#include <iostream>

using namespace std;

int main(){
	
     int x ;
     bool List2 = false; 
     cout << "list 1:" << endl ;

     cin >> x ;
     while( !cin.eof() ){
        if( x == 0 ){
            List2 = true ;
            cout << "\nlist 2:\n" ;
        }else{
            cout << x << " " ;
        }
        cin >> x ;
     }
     cout << endl

