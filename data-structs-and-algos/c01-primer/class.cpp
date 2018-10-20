#include <iostream>
using namespace std;

// Class declaration
class Counter {
public:
    Counter(); // Initializer
    // const indicates that the function does not modify an instance
    int getCount() const; // Returns count
    void increaseBy(int n = 1);
    friend ostream& operator<<(ostream& outs, const Counter& counter);
private:
    int count;
};

// Class implementation
Counter::Counter() {
    count = 0;
}
int Counter::getCount() const {
    return count;
}
// If called w/o an argument, count will increase by 1
void Counter::increaseBy(int n) {
    count += n;
}

// Output overload
ostream& operator<<(ostream& outs, const Counter& counter) {
    // friend functions can access private member variables directly
    outs << "Count = " << counter.count;
    return outs;
}

int main() {
    Counter counter; // Implicitly calls Counter()
    cout << counter << endl;
    counter.increaseBy(); // Increase count by 1
    cout << counter << endl;
    counter.increaseBy(2); // Count now 3
    cout << counter << endl;
    return 0;
}
