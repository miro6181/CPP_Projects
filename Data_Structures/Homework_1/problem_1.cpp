/* Written by Michael Rogers
Student ID: 105667404
Professor Gupta
Problem 1*/

#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

int insertIntoSortedArray(int myArray[], int numEntries, int newValue) {

}

int main(int argc, char *argv[]) {
  if(argc == 2) {
    ifstream myFile(argv[1]);

    string myArray[100];

    if (myFile.is_open()) {
      cout << "File open successful." << endl;
      string line;
      int counter = 0;

      while (getline(myFile, line)) {
        for(int i = 0; i < 1; i++) {
          myArray[i] = line;
          cout << myArray[i] << endl;
        }
        //cout << line << endl;

        stringstream ss;
        ss << line;

        counter++;
      }

      cout <<"Finished reading file. Closing now..." << endl;
      myFile.close();

    }
    else
      cout << "File open failed." << endl;

    return 0;
  }
  else
    cout << "Program Failed. Incorrect number of arguments." << endl;
}
