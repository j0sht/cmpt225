#include <iostream>
using namespace std;

class GameEntry {
public:
    GameEntry(const string& n="", int s=0);
    string getName() const;
    int getScore() const;
private:
    string name;
    int score;
};

GameEntry::GameEntry(const string& n, int s): name(n), score(s) {}

string GameEntry::getName() const { return name; }
int GameEntry::getScore() const { return score; }

class IndexOutOfBounds {
public:
    IndexOutOfBounds(string& msg);
    friend ostream& operator<<(ostream& outs, IndexOutOfBounds& e);
private:
    string msg;
};
IndexOutOfBounds::IndexOutOfBounds(string& msg) {
    this->msg = msg;
}
ostream& operator<<(ostream& outs, IndexOutOfBounds& e) {
    outs << e.msg;
    return outs;
}

class Scores {
public:
    Scores(int maxEntries = 10);
    ~Scores();
    void add(const GameEntry& e);
    GameEntry remove(int i) throw (IndexOutOfBounds);
private:
    int maxEntries;
    int numEntries;
    GameEntry* entries; // array of game entries
};

Scores::Scores(int maxEnt) {
    maxEntries = maxEnt;
    entries = new GameEntry[maxEntries];
    numEntries = 0;
}

Scores::~Scores() {
    delete[] entries;
}

// Analysis of add:
//  - The number of time the loop is performed depends on the number
//    of entries that need to be shifted.
//  - This is fast if the number of entries is small, but if there is
//    a lot to move, this method can be slow.
void Scores::add(const GameEntry& e) {
    int newScore = e.getScore();
    if (numEntries == maxEntries) {
	// Score is not high enough - ignore it
	if (newScore <= entries[maxEntries-1].getScore())
	    return;
    }
    else
	numEntries++; // if not full, one more entry

    int i = numEntries-2; // start with next to last
    while (i >= 0 && newScore > entries[i].getScore()) {
	entries[i+1] = entries[i]; // shift right if smaller
	i--;
    }
    entries[i+1] = e; // put e in the empty spot
}

GameEntry Scores::remove(int i) throw (IndexOutOfBounds) {
    if ((i < 0) || (i >= numEntries)) // invalid index
	throw IndexOutOfBounds("Invalid index");
    GameEntry e = entries[i]; // save the removed object
    for (int j = i+1; j < numEntries; j++)
	entries[j-1] = entries[j]; // Shift entries left
    numEntries--;
    return e;
}
