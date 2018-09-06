/* Written by Michael Rogers
Student ID: 105667404
Professor Gupta */

#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

//int insertIntoSortedArray(int myArray[], int numEntries, int newValue);

int main(int argc, char *argv[])
{
  if(argc == 2)
  {
    ifstream myFile(argv[1]);

    if (myFile.is_open())
    {
      cout << "File open successful. It contains: " << endl;
      string line;
      int counter = 0;

      while (getline(myFile, line))
      {
        cout << line << endl;

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
