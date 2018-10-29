#include <iostream>
#include <fstream>
#include <sstream>
#include "HashTable.hpp"

using namespace std;

int main(int argc, char* argv[]) {

    HashTable HungerGamesTable = HashTable(stoi(argv[4]));
    HungerGamesTable.getStopWords(argv[3]);

    ifstream wordStream;
    wordStream.open(argv[2]);
    //cout << argv[2] << endl;
    string line;
    //cout << "chk1" << endl;
    while(wordStream >> line) {
        if(HungerGamesTable.isInTable(line) && HungerGamesTable.isStopWord(line)) {
            HungerGamesTable.incrementCount(line);
        }
        else if(!HungerGamesTable.isStopWord(line)) {
            HungerGamesTable.addWord(line);
        }
    }

    HungerGamesTable.printTopN(stoi(argv[1]));

    cout << "#" << endl;
    cout << "Number of collisions: " << HungerGamesTable.getNumCollisions() << endl;
    cout << "#" << endl;
    cout << "Unique non-stop words: " << HungerGamesTable.getNumUniqueWords() << endl;
    cout << "#" << endl;
    cout << "Total non-stop words: " << HungerGamesTable.getTotalNumberNonStopWords() << endl;
}
