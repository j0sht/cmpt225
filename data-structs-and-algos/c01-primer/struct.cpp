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
    case 0:
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
    return 0;
}
