#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int *getBiggerArray(int *oldArray, int oldCapacity)
{
    int ∗newArray = new int[oldCapacity]// dynamically allocate an array of size 2 * oldCapacity

    // copy all data from oldArray to newArray
    delete [] oldArray;
    return newArray;
}

int main (int argc, char ∗argv[])
{
    if(argc != 2)
    {
      return error;// throw error
    }

    string filename = argv[1];
    string line;
    fstream myFile(filename)// open the filename that was the first command-line argument

    int capacity = 10;
    int *array = new int[capacity]// dynamically allocate array with initial capacity
    int numberOfLines = 0;
    for(getline(myFile, line))
    {
        if( numberOfLines >= capacity )
        {
            array = getBiggerArray(array, capacity);
            capacity = 2 * capacity;
        }
        // add the number in the line into the array
    }
}
