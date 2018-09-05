#include <iostream>
using namespace std;

int main()
{
  const double pi = 3.14;
  cout << "Welcome to the area and circumference calculator!" << endl;
  cout << "Input the radius of your circle: " ;
  float radius = 0;
  cin >> radius;

  float circumference = 2* pi* radius;
  float area = pi * (radius * radius);

  cout << "The area is "<< area << endl;
  cout << "The circumference is " << circumference << endl;

  return 0;

}
