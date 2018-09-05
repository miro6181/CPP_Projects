//Algorithms

/*-Correctness: Your algorithm must work correctly
  -Cost: Memory use and runtime(number of CPU Cycles being used)
  -Big-O Notation:Asymptotic notation that defines the upper bound
  of the growth rate of the algorithmic runtime. f(n) or O(1).
  -Growth Rate: How does an algorithm scale with input size?
  -Look up binary search*/

#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    cout << "hello world" << endl;

    cout << argc << endl;

    for(int i = 0; i < argc; i++)
    {
      cout << argv[i] << endl;
    }
}
