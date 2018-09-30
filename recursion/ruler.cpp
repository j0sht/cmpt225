#include <iostream>
using namespace std;

// one tick with optional label
void drawOneTick(int tickLength, int tickLabel = -1) {
    for (int i = 0; i < tickLength; i++)
	cout << "-";
    if (tickLabel >= 0)
	cout << " " << tickLabel;
    cout << "\n";
}
// draw ticks of given length
void drawTicks(int tickLength) {
    if (tickLength > 0) {
	drawTicks(tickLength - 1);
	drawOneTick(tickLength);
	drawTicks(tickLength - 1);
    }
}
// draw the entire ruler
void drawRuler(int inches, int majorLength) {
    drawOneTick(majorLength, 0);
    for (int i = 0; i <= inches; i++) {
	drawTicks(majorLength-1);
	drawOneTick(majorLength, i);
    }
}
// MAIN
int main() {
    cout << "2-INCH RULER OF MAJOR TICK LENGTH 4\n";
    drawRuler(2, 4);
    cout << endl;
    cout << "1-INCH RULER OF MAJOR TICK LENGTH 5\n";
    drawRuler(1, 5);
    cout << endl;
    cout << "3-INCH RULER OF MAJOR TICK LENGTH 3\n";
    drawRuler(3, 3);
    return 0;
}
