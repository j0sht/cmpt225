#include <iostream>
using namespace std;

// Enum - Discreet enumerated values
// Defaults to 0,1,...,n-1
// Example below) NO_PREF = 0, Regular = 1, ..., Vegetarian = 3
enum MealType { NO_PREF, REGULAR, LOW_FAT, VEGETARIAN };

// C-style struct representing airline passenger
struct Passenger {
    string name;
    MealType mealPref;
    bool isFreqFlyer;
    string freqFlyerNo;
};

int main() {
    // Passenger allocated in main stack space
    Passenger pass = { "John Smith", VEGETARIAN, true, "123456" };
    cout << "Name: " << pass.name << endl;
    cout << "Meal preference: ";
    switch (pass.mealPref) {
    case 0: // Alternatively, NO_PREF
	cout << "No preference\n";
	break;
    case 1:
	cout << "Regular\n";
	break;
    case 2:
	cout << "Low fat\n";
	break;
    case 3:
	cout << "Vegetarian\n";
    }
    cout << "Is frequent flyer? ";
    if (pass.isFreqFlyer) {
	cout << "Yes\n";
	cout << "Frequent flyer number: "
	     << pass.freqFlyerNo << endl;
    } else {
	cout << "No\n";
    }

    // Dynamically allocated struct (stored in heap memory)
    // The 'new' operator dynamically allocated the correct amount of storage
    //  for an object of a given type and returns a pointer to this object.
    //  i.e. The value of the pointer is the address where the object lives
    //       in memory.
    Passenger* p = new Passenger;
    // Two ways to access p's member variables
    //  i) The ugly way (*p).name
    // ii) Pretty way p->name
    (*p).name = "Josh";
    p->mealPref = LOW_FAT;
    p->isFreqFlyer = false;
    cout << "Name: " << p->name << endl;
    cout << "Meal preference: ";
    switch (p->mealPref) {
    case 0: // Alternatively, NO_PREF
	cout << "No preference\n";
	break;
    case 1:
	cout << "Regular\n";
	break;
    case 2:
	cout << "Low fat\n";
	break;
    case 3:
	cout << "Vegetarian\n";
    }
    cout << "Is frequent flyer? ";
    if (p->isFreqFlyer) {
	cout << "Yes\n";
	cout << "Frequent flyer number: "
	     << p->freqFlyerNo << endl;
    } else {
	cout << "No\n";
    }

    // Remember to delete any allocated memory
    delete p;
    return 0;
}
