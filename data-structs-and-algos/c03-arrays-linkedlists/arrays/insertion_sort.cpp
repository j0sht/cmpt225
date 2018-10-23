#include <iostream>
using namespace std;

// High level outline:
//  - Start with the first item in the array.
//  - One element by itself is already sorted.
//  - Then consider the next item in the array.
//    - If it is smaller than the first, swap them.
//  - Then consider the next.
//    - Swap it leftward until it is in proper order with the first two.
//  - Continue in this manner for the rest of the array.
void insertionSort(int* array, int size) {
    // Can be implemented using two loops:
    // Outer loop: Considers each element in the array in turn.
    // NOTE: Since one element by itself is already sorted,
    //       i starts at the second element.
    for (int i = 1; i < size; i++) {
	// Inner loop: moves element at i to proper location
	//  with the sorted subarray to the left of i [0...i-1].
	int current = array[i];
	int j = i-1;
	while ((j >= 0) && array[j] > current) {
	    array[j+1] = array[j];
	    j--;
	}
	array[j+1] = current;
    }
}
/* ANALYSIS */
// - If the array is already sorted, the inner loop only does one
//    comparison, determines no swap is needed, and returns to outer loop.
// - WORST CASE: If the array is given in descending order.

int main() {
    int nums[] = { 5,3,2,4,1 };
    cout << "Elements (unsorted): ";
    for (int i = 0; i < 5; i++)
	cout << nums[i] << " ";
    cout << endl;
    insertionSort(nums, 5);
    cout << "Elements (sorted): ";
    for (int i = 0; i < 5; i++)
	cout << nums[i] << " ";
    cout << endl;
    return 0;
}
