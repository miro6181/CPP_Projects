#include <iostream>

using namespace std;

void passByReference(int &a) {
  a++;
}

void passByArray(int *a) {
  a[0] = 10;
  a[1] = 11;
}

// Dynamically allocated arrays
int *y = new int[10]; //array of 10 ints
double *x = new double[20]; //array of 20 doubles

delete[] y; //frees the memory allocated to y
delete[] x; //frees the memory allocated to x



int main() {

}
