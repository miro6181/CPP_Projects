/* Written by Michael Rogers
Student ID: 105667404
Professor Gupta */

#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>

using namespace std;

//int insertIntoSortedArray(int myArray[], int numEntries, int newValue);

int main(char useFile)
{
  // string useFile;
  // cout << "Input a file to read from: ";
  // cin >> useFile;

  ifstream myFile(useFile);

  if (myFile.is_open())
  {
    cout << "File open successful. It contains: " << endl;
    string line;
    int counter = 0;
    //vector<int> numbers;

    while (getline(myFile, line))
    {
      cout << line << endl;

      stringstream ss;
      ss << line;

      //numbers.push_back(line);
      //cout << numbers << endl;
      counter++;
    }

    cout <<"Finished reading file. Closing now..." << endl;
    myFile.close();

  }
  else
    cout << "File open failed." << endl;

  return 0;
}
