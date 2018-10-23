#include <iostream>
using namespace std;

const int X = 1, O = -1, EMPTY = 0; // possible markers
int board[3][3]; // 3x3 array of integers representing the game board
int currentPlayer; // current player (X or O)

void clearBoard() {
    for (int i = 0; i < 3; i++)
	for (int j = 0; j < 3; j++)
	    board[i][j] = EMPTY;
    currentPlayer = X; // player X starts
}

void putMark(int i, int j) { // mark row i and column j
    board[i][j] = currentPlayer; // mark with current player
    currentPlayer = -currentPlayer; // switch players
}

bool isWin(int mark) { // Is mark the winner?
    int win = 3 * mark;
    // Check if three in one row is a win
    for (int i = 0; i < 3; i++) {
	int score = 0;
	for (int j = 0; j < 3; j++)
	    score += board[i][j];
	if (score == win)
	    return true;
    }
    // Check if three in one column is a win
    for (int j = 0; j < 3; j++) {
	int score = 0;
	for (int i = 0; i < 3; i++)
	    score += board[i][j];
	if (score == win)
	    return true;
    }
    // Check if diagonals are a win
    return ((board[0][0] + board[1][1] + board[2][2] == win)
	    || (board[2][0] + board[1][1] + board[0][2] == win));
}

int getWinner() { // EMPTY means tie
    if (isWin(X)) return X;
    else if (isWin(O)) return O;
    else return EMPTY;
}

void printBoard() {
    for (int i = 0; i < 3; i++) {
	for (int j = 0; j < 3; j++) {
	    switch(board[i][j]) {
	    case X:
		cout << "X"; break;
	    case O:
		cout << "O"; break;
	    case EMPTY:
		cout << " "; break;
	    }
	    if (j < 2) cout << "|"; // column boundary
	}
	if (i < 2) cout << "\n-+-+-\n"; // row boundary
    }
}

int main() { // main program
    clearBoard();
    putMark(0,0); putMark(1,1);
    putMark(0,1); putMark(0,2);
    putMark(2,0); putMark(1,2);
    putMark(2,2); putMark(2,1);
    putMark(1,0);
    printBoard(); // print the final board
    int winner = getWinner();
    if (winner != EMPTY) // print the winner
	cout << " " << (winner == X ? 'X' : 'O') << " wins" << endl;
    else
	cout << " Tie" << endl;
    return 0;
}
